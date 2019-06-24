// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/PlayerController.h"
#include "ABPlayerController.generated.h"


UCLASS()
class ARENABATTLE_API AABPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AABPlayerController();
	
	virtual void PostInitializeComponents() override;
	virtual void OnPossess(APawn* aPawn) override;

	void NPCKill(class AABCharacter* KilledNPC) const;
	void AddGameScore() const;

	void ChangeInputMode(bool bGameMode = true);
	void ShowResultUI();

	class UABHUDWidget* GetHUDWidget() const;
protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UABHUDWidget> HUDWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UABGameplayWidget> MenuWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UABGameplayResultWidget> ResultWidgetClass;

private:
	void OnGamePause();


	UPROPERTY()
		class AABPlayerState* ABPlayerState;

	UPROPERTY()
		class UABHUDWidget* HUDWidget;

	UPROPERTY()
		class UABGameplayWidget* MenuWidget;

	UPROPERTY()
		class UABGameplayResultWidget* ResultWidget;


	FInputModeGameOnly GameInputMode;
	FInputModeUIOnly   UIInputMode;

};

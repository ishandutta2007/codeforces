import java.util.ArrayList;
import java.util.Scanner;

public class B {

	
	public static void main(String[] args) {
		ArrayList<String> toOutput=new ArrayList<>();
		
		Scanner s=new Scanner(System.in);
		int playerHealth=s.nextInt();
		int playerAttack=s.nextInt();
		int playerHeal=s.nextInt();
		int enemyHealth=s.nextInt();
		int enemyPower=s.nextInt();
		
		boolean playersTurn=true;
		while (Math.min(playerHealth, enemyHealth)>0) {
			if (playersTurn) {
				if (enemyHealth<=playerAttack) {
					toOutput.add("STRIKE");
					enemyHealth-=playerAttack;
				}
				else if (playerHealth>enemyPower) {
					toOutput.add("STRIKE");
					enemyHealth-=playerAttack;
				}
				else {
					toOutput.add("HEAL");
					playerHealth+=playerHeal;
				}
			}
			else {
				playerHealth-=enemyPower;
			}
			playersTurn^=true;
		}

		System.out.println(toOutput.size());
		for (String st:toOutput) {
			System.out.println(st);
		}
	}
	
	

}
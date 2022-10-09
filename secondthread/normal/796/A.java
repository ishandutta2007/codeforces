

import java.util.Scanner;

public class Houses {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int numberOfHouses=s.nextInt();
		int dreamHouse=s.nextInt()-1;
		int money=s.nextInt();
		
		int[] houses=new int[numberOfHouses];
		for (int i=0; i<houses.length; i++) {
			houses[i]=s.nextInt();
		}
		
		int bestHouseIndex=-1;
		for (int i=0; i<houses.length; i++) {
			if (bestHouseIndex==-1) {
				if (houses[i]!=0&&houses[i]<=money) {
					bestHouseIndex=i;
				}
			}
			else {
				if (houses[i]!=0&&houses[i]<=money) {
					if (Math.abs(i-dreamHouse)<Math.abs(bestHouseIndex-dreamHouse)) {
						bestHouseIndex=i;
					}
				}
			}
		}
		System.out.println(10*Math.abs(bestHouseIndex-dreamHouse));
	}

}
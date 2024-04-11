import java.util.Scanner;

public class Candies {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int totalDays=s.nextInt();
		int candiesAHas=0;
		int candiesToGive=s.nextInt();
		for (int i=0; i<totalDays; i++) {
			candiesAHas+=s.nextInt();
			int candiesGiven=Math.min(candiesAHas, Math.min(8, candiesToGive));
			candiesAHas-=candiesGiven;
			candiesToGive-=candiesGiven;
			if (candiesToGive==0) {
				System.out.println(i+1);
				return;
			}
		}
		System.out.println(-1);

	}

}
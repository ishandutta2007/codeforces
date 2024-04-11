import java.util.Scanner;

public class BrewingCoffee {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int numberOfRecipies=s.nextInt();
		int minSuggusted=s.nextInt();
		int queries=s.nextInt();
		int[] delta=new int[200002];
		for (int i=0; i<numberOfRecipies; i++) {
			delta[s.nextInt()]++;
			delta[s.nextInt()+1]--;
		}
		
		int[] admissibleBefore=new int[200002];
		int counter=0;
		int admissibleSpots=0;
		for (int i=0; i<admissibleBefore.length; i++) {
			counter+=delta[i];
			if (counter>=minSuggusted) {
				admissibleSpots++;
			}
			admissibleBefore[i]=admissibleSpots;
		}
		
		for (int i=0; i<queries; i++) {
			int start=s.nextInt()-1;
			int end=s.nextInt();
			System.out.println(admissibleBefore[end]-admissibleBefore[start]);
		}
	}

}
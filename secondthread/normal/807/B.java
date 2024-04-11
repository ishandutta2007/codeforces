import java.util.Scanner;

public class Shirts {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int myPlace=s.nextInt();
		int myScore=s.nextInt();
		int minScore=s.nextInt();
		for (int testScore=myScore; testScore>=minScore; testScore-=50) {
			if (wouldGetShirt(testScore, myPlace)) {
				System.out.println(0);
				return;
			}
		}
		for (int counter=0; counter==counter; counter++) {
			if (wouldGetShirt(myScore+50*counter, myPlace)) {
				System.out.println((counter+1)/2);
				return;
			}
		}
	}
	
	public static boolean wouldGetShirt(int score, int placeNumber) {
		score/=50;
		score%=475;
		for (int i=0; i<25; i++) {
			score=(score*96+42)%475;
			//System.err.println(score);
			if (26+score==placeNumber) {
				return true;
			}
		}
		return false;
	}

}
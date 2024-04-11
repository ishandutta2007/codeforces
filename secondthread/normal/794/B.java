import java.util.Scanner;

public class Carrots {
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int numberOfCuts=s.nextInt()-1;
		int height=s.nextInt();
		for (int i=0; i<numberOfCuts; i++) {
			double percentDone=(double)(i+1)/(numberOfCuts+1);
			double answer=Math.sqrt(height*(double)height*percentDone);
			System.out.println(answer);
		}
	}
}
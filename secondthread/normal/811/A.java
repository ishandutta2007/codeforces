import java.util.Random;
import java.util.Scanner;

public class GivingCandies {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		long a=s.nextInt(), b=s.nextInt();
		//Random r=new Random();
		//long a=r.nextInt(15), b=r.nextInt(15);
		System.out.println(solve(a, b));
		//System.out.println(solveManually(a, b));
	}
	
	public static String solve(long firstCandies, long secondCandies) {
		int firstTurns=(int)Math.sqrt(firstCandies);
		int secondTurns=(int) ((-1+Math.sqrt(1+4*secondCandies))/2);
		//System.err.println(firstTurns+" "+secondTurns);
		if (firstTurns<=secondTurns) {
			return ("Vladik");
		}
		else {
			return ("Valera");
		}
	}
	
	public static String solveManually(long firstCandies, long secondCandies) {
		int counter=1;
		while (true) {
			firstCandies-=counter++;
			secondCandies-=counter++;
			if (firstCandies<0) {
				return "Valdik";
			}
			if (secondCandies<0) {
				return "Valera";
			}
		}
	}

}
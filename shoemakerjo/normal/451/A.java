import java.util.Scanner;

public class GameWithSticks {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		int min = Math.min(n, m);
		if (min%2==0) System.out.println("Malvika");
		else System.out.println("Akshat");

	}

}
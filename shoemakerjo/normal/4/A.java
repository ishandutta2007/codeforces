import java.util.Scanner;

public class Watermelon {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		long n = s.nextLong();
		if (n <= 2) System.out.println("NO"); 
		else if(n%2==0) System.out.println("YES");
		else System.out.println("NO");

	}

}
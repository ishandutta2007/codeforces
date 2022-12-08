import java.util.Scanner;

public class EvenOdds {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		long n = s.nextLong();
		long k = s.nextLong();
		long odds, evens;
		if (n%2==1) {
			odds = n/2+1;
			evens=n/2;
		}
		else {
			odds=n/2;
			evens=n/2;
		}
		if (k <= odds) {
			System.out.println(2*(k-1)+1);
		}
		else {
			k-=odds;
			System.out.println(2*k);
		}

	}

}
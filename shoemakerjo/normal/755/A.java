import java.math.BigInteger;
import java.util.Scanner;

public class BallHypothesis {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		for (int i = 1; i <= 1000; i++) {
			BigInteger cur  = BigInteger.valueOf(n*i+1);
			if (!cur.isProbablePrime(1000)) {
				System.out.println(i);
				break;
			}
		}

	}

}
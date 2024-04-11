import java.math.BigInteger;
import java.util.Scanner;

public class LearnFromMath {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		long n = s.nextLong();
		for (long i = 2; i <= n; i++) {
			long o = n-i;
			BigInteger f = BigInteger.valueOf(i);
			BigInteger se = BigInteger.valueOf(o);
			if (!f.isProbablePrime(1000) && !se.isProbablePrime(1000)) {
				System.out.println(i+ " " + o);
				break;
			}
		}

	}

}
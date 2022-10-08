import java.math.BigInteger;
import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int T=s.nextInt();
		while (T-->0) {
			BigInteger a=new BigInteger(s.next()), b=new BigInteger(s.next());
			System.out.println(a.multiply(a).subtract(b.multiply(b)).isProbablePrime(99)?"YES":"NO");
		}
	}
}
import java.math.BigInteger;
import java.util.Scanner;

public class D066 {
	static int[] primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
			47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109,
			113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
			191, 193, 197, 199, 211, 223, 227, 229 };

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		if(n==2) {
			System.out.println("-1");
			return;
		}
		BigInteger big = BigInteger.ONE;
		for (int x = 0; x < n; x++) {
			big = big.multiply(BigInteger.valueOf((long) primes[x]));
		}
		for (int x = 0; x < n; x++) {
			BigInteger num = big.divide(BigInteger.valueOf((long) primes[x]));
			System.out.println(num);
		}

	}
}
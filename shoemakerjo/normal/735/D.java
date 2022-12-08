import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class D {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		long n = s.nextLong();
		long ans = 0;
		long cur = n;
		if (cur%2 == 0 && cur!=2) System.out.println(2);
		else {
			BigInteger temp = BigInteger.valueOf(cur);
			if (temp.isProbablePrime(1000)) {
				System.out.println(1);
			}
			else {
				temp = BigInteger.valueOf(cur-2);
				if (temp.isProbablePrime(1000)) {
					System.out.println(2);
				}
				else System.out.println(3);
			}

		}
		

	}

}
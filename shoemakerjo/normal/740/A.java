import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		long n = s.nextLong(); //number had
		long a = s.nextLong(); //1 pack
		long b = s.nextLong(); //2 pack
		long c = s.nextLong(); //3 pack
		long remaining = 4-n%4;
		if (remaining == 0) System.out.println(0);
		else {
			long min = 0;
			if (remaining == 1) {
				min = a;
				min = Math.min(min, b+c);
				min = Math.min(min, 3*c);
			}
			if (remaining == 2) {
				min = 2*a;
				min = Math.min(min, b);
				min = Math.min(min, 2*c);
			}
			if (remaining == 3) {
				min = 3*a;
				min = Math.min(min, c);
				min = Math.min(min, a+b);
			}
			System.out.println(min);
			
		}

	}

}
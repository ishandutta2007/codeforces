import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long m = sc.nextLong();
		long a = sc.nextLong();
		long x, y;
		if(n%a == 0) {
			x = n/a;
		} else {
			x = n/a + 1;
		}
		if(m%a == 0) {
			y = m/a;
		} else {
			y = m/a + 1;
		}
		
		System.out.println(x*y);
	}

}
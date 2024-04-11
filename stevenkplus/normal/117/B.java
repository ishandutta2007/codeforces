import java.util.Scanner;

public class B117 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();

		int mod = (int) 1E9 % c;
		int d = c;
		if (d > a)
			d = a;
		int prev = 0;
		for (int x = 1; x <= d; x++) {
			prev = (prev + mod) % c;
			int k = c - prev;
			if (k == c)
				k = 0;
			if (k > b) {
				System.out.printf("%d %09d\n", 1, x);
				return;
			}
		}
		System.out.println(2);
	}
}
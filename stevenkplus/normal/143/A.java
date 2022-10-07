import java.util.Scanner;

public class A143 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), d = in
				.nextInt(), e = in.nextInt(), f = in.nextInt();
		int sq1 = (a + c - f) / 2;
		int sq2 = a - sq1;
		int sq3 = c - sq1;
		int sq4 = e - sq1;
		if (sq1 + sq2 == a && sq1 + sq3 == c && sq1 + sq4 == e
				&& sq2 + sq3 == f && sq2 + sq4 == d && sq3 + sq4 == b
				&& sq1 != sq2 && sq1 != sq3 && sq1 != sq4 && sq2 != sq3
				&& sq2 != sq4 && sq3 != sq4&&i(sq1)&&i(sq2)&&i(sq3)&&i(sq4))
			System.out.printf("%d %d\n%d %d\n", sq1, sq2, sq3, sq4);
		else
			System.out.println("-1");
	}
	static boolean i(int a) {
		return a>=1&&a<=9;
	}
}
import java.util.Scanner;

public class A108 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		String[] u = in.nextLine().split(":");
		int h = Integer.parseInt(u[0]), m = Integer.parseInt(u[1]);
		do {
			m++;
			if (m == 60) {
				h++;
				if (h == 24)
					h = 0;
				m = 0;
			}
		} while (!pal(h, m));
		System.out.printf("%02d:%02d\n", h, m);
	}

	static boolean pal(int a, int b) {
		int m = b % 10, n = b / 10;
		return a / 10 == m && a % 10 == n;
	}
}
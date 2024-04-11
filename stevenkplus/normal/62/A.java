import java.util.Scanner;

public class A062 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt(), b = in.nextInt(), x = in.nextInt(), y = in
				.nextInt();
		System.out.println(w(a, y) || w(b, x) ? "YES" : "NO");

	}

	static boolean w(int a, int b) {
		return b>=a-1&&2*a+2>=b;
	}
}
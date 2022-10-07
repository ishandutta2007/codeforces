import java.util.Scanner;

public class A040 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt(), b = in.nextInt();
		System.out.println(f(a, b) ? "white" : "black");
	}

	static boolean f(int a, int b) {
		if (a == 0 || b == 0)
			return false;
		int dist = a * a + b * b;
		int sqrt = (int) Math.sqrt(dist);
		if (sqrt * sqrt == dist)
			return false;
		return sqrt%2==1^a>0^b>0;
	}
}
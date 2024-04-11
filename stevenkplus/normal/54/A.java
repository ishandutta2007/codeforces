import java.util.Scanner;

public class A054 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt(), c = in.nextInt();
		boolean[] holiday = new boolean[9001];
		for (int x = 0; x < c; x++) {
			holiday[in.nextInt()] = true;
		}
		int prev = 0;
		int count = 0;
		for (int x = 1; x <= n; x++) {
			if (holiday[x] || x - prev == k) {
				prev = x;
				count++;
			}
		}
		System.out.println(count);
	}
}
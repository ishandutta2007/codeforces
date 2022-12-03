import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int p = in.nextInt();
		int n = in.nextInt();
		boolean[] a = new boolean[p];
		for (int i = 1; i <= n; i++) {
			int x = in.nextInt();
			int h = x % p;
			if (a[h]) {
				System.out.println(i);
				return;
			}
			a[h] = true;
		}
		System.out.println(-1);
	}
}
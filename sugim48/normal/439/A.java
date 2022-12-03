import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int d = in.nextInt();
		int[] t = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = in.nextInt();
		}
		
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += t[i];
		}
		sum += (n - 1) * 10;
		
		if (sum <= d) {
			System.out.println((n - 1) * 2 + (d - sum) / 5);
		} else {
			System.out.println(-1);
		}
	}
}
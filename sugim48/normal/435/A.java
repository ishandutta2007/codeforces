import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		
		int ans = 0, k = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > k) {
				ans++;
				k = m;
			}
			k -= a[i];
		}
		
		System.out.println(ans);
	}
}
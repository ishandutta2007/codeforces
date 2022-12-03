import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextLong();
		}
		
		long k = 0;
		for (int i = 0; i < n; i++) {
			k += a[i];
		}
		long K = (int)(k / n);
		
		long ans = 0;
		for (int i = 0; i < n - 1; i++) {
			long da = K - a[i];
			a[i + 1] -= da;
			ans += Math.abs(da);
		}
		
		System.out.println(ans);
	}
}
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		Long[] a = new Long[n];
		Long[] b = new Long[m];
		
		for (int i = 0; i < n; i++) {
			a[i] = in.nextLong();
		}
		for (int j = 0; j < m; j++) {
			b[j] = in.nextLong();
		}
		
		Arrays.sort(a);
		Arrays.sort(b);
		
		Long[] c = new Long[n + m];
		for (int i = 0; i < n; i++) {
			c[i] = a[i];
		}
		for (int j = 0; j < m; j++) {
			c[n + j] = b[j];
		}
		Arrays.sort(c);
		
		long[] A = new long[n + m];
		int i = 0;
		for (int k = 1; k < n + m; k++) {
			while (true) {
				if (i == n || a[i] >= c[k]) {
					break;
				}
				i++;
			}
			A[k] = A[k - 1] + i * (c[k] - c[k - 1]);
		}
		
		long[] B = new long[n + m];
		int j = m - 1;
		for (int k = n + m - 2; k >= 0; k--) {
			while (true) {
				if (j == -1 || b[j] <= c[k]) {
					break;
				}
				j--;
			}
			B[k] = B[k + 1] + (m - 1 - j) * (c[k + 1] - c[k]);
		}
		
		long ans = Long.MAX_VALUE;
		for (int k = 0; k < n + m; k++) {
			ans = Math.min(ans, A[k] + B[k]);
		}
		System.out.println(ans);
	}
}
import java.util.Scanner;

public class codeforces9d {
	static long[][] dp;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), h = in.nextInt();
		dp = new long[n + 1][h + 1];
		for(long[] k:dp) {
			for(int x=0;x<k.length;x++) {
				k[x]=-1;
			}
		}
		System.out.println(find(n, h));
	}

	static long find(int n, int h) {
		if (h > n)
			return 0;
		if (n == 0)
			return 1;
		if (dp[n][h] == -1) {
			long s = 0;
			for (int x = 0; x < n; x++) {
				if (h == 0) {
					s += find(x, 0) * find(n - 1 - x, 0);
				} else {
					s += 
						find(x, h - 1)	 * find(n - 1 - x, 0) + 
						find(x, 0) 		 * find(n - 1 - x, h - 1) - 
						find(x, h - 1)	 * find(n - 1 - x, h - 1);
					// inclusion exclusion
				}
			}
			dp[n][h]=s;
		}
		return dp[n][h];
	}
}
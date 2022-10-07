import java.util.Scanner;

public class C132 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		a = in.nextLine();
		int n = in.nextInt();
		dp = new int[2][a.length()][n + 1];
		for (int x = 0; x < a.length(); x++) {
			for (int y = 0; y < n + 1; y++) {
				dp[0][x][y] = dp[1][x][y] = NULL;
			}
		}
		int a = max(0, n, 0);
		int b = -max(0, n, 1);
		System.out.println(a > b ? a : b);
	}

	static int max(int start, int swaps, int f) {
		if (swaps < 0)
			return NULL2;
		if (start == a.length()) {
			if (swaps % 2 == 0)
				return 0;
			else
				return NULL2;
		}
		if (dp[f][start][swaps] == NULL) {
			int n, k, j;
			if (a.charAt(start) == 'F') {
				k = max(start + 1, swaps, f);
				n = k + 1;
				j = -max(start + 1, swaps - 1, 1 - f);
			} else {
				j = -max(start + 1, swaps, 1 - f);
				k = max(start + 1, swaps - 1, f);
				n = k + 1;
			}
			boolean b= j>n;
			if(f==1) b = !b;
			if (isnull(k) || (!isnull(j) && b)) {
				dp[f][start][swaps] = j;
			} else
				dp[f][start][swaps] = n;
		}

		return dp[f][start][swaps];
	}

	static boolean isnull(int k) {
		return k == NULL2 || k == -NULL2;
	}

	static int NULL = 6969;
	static int NULL2 = 696969;
	static String a;
	static int[][][] dp;
}
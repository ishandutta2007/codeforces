import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class D098 {
	static int[][] dp;
	static int[][] dp2;
	static int[][] best;
	static String s;

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer token;
		String line = in.next();
		s = line;
		int k = in.nextInt();
		dp = new int[line.length()][k + 1];
		dp2 = new int[line.length() + 1][line.length() + 1];
		best = new int[line.length()][k + 1];
		for (int[] i : dp) {
			Arrays.fill(i, -1);
		}
		for (int[] i : dp2) {
			Arrays.fill(i, -1);
		}
		for (int[] i : best) {
			Arrays.fill(i, -1);
		}
		System.out.println(get(0, k));
		StringBuffer ret = new StringBuffer();
		int cur = 0;
		for (int x = 0; x < k; x++) {
			if(cur==s.length()) break;
			int b = best[cur][k - x];
			ret.append(topal(s.substring(cur, b)));
			ret.append("+");
			cur = b;
		}
		System.out.println(ret.substring(0,ret.length()-1));
	}
	public static String topal(String s) {
		char[] c = s.toCharArray();
		for(int x = 0;x<s.length();x++) {
			int y = s.length()-x-1;
			if(c[x]!=c[y])
				c[y] = c[x];
		}
		return new String(c);
	}
	public static int get(int a, int b) {
		if (a == s.length()) {
			return 0;
		}
		if (dp[a][b] == -1) {
			if (b == 0) {
				return -1;
			}

			int min = -1;
			int bet = 0;
			for (int x = a + 1; x <= s.length(); x++) {
				int c = get(x, b - 1);
				if (c == -1)
					continue;
				int p = changesNeeded(a, x - 1) + c;
				if (p < min || min == -1) {
					min = p;
					bet = x;
				}
			}
			best[a][b] = bet;
			dp[a][b] = min;
		}
		return dp[a][b];
	}

	public static int changesNeeded(int a, int b) {
		if (dp2[a][b] == -1) {
			if (b - a < 1) {
				dp2[a][b] = 0;
			} else {
				int p = s.charAt(a) == s.charAt(b) ? 0 : 1;
				dp2[a][b] = p + changesNeeded(a + 1, b - 1);
			}
		}
		return dp2[a][b];
	}
}
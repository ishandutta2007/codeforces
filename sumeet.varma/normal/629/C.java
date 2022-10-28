import java.io.*;
import java.util.*;

public class R343qC {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		char s[] = in.readString().toCharArray();
		int c = 0;
		int min = 2*n;
		for(int i = 0; i < m; i++){
			//c += x == '(' ? 1 : -1;
			if(s[i] == '(')
				c++;
			else
				c--;
			
			min = Math.min(min, c);
		}
		
		final int mod = (int)1e9 + 7;
		int dp[][] = new int[2010][2011]; //dp[i][j] = number of bracket sequences of length i such that '( - ')' = j
										  // number of ways to arrange i brackets such that currently '(' - ')' = j
		dp[0][0] = 1;
		
		for(int i = 1; i < dp.length; i++){
			for(int j = 0; j <= dp.length; j++){
				dp[i][j] = 0;
				if(j > 0)
					dp[i][j] += dp[i - 1][j - 1];
				if(j + 1 <= dp.length)
					dp[i][j] += dp[i - 1][j + 1];
				if(dp[i][j] >= mod)
					dp[i][j] -= mod;
			}
		}
		
		long ans = 0;
		
		for(int len = 0; len <= n - m; len++){
			for(int pre = 0; pre <= len; pre++){
				long p = dp[len][pre];
				int post = pre + c;
				if(pre + min < 0)
					continue;
				long q = post <= (n - m - len) ? dp[n - m - len][post] : 0;
				ans += p * q;
				ans %= mod;
			}
		}
		
		w.println(ans);
		w.close();
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar, snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}
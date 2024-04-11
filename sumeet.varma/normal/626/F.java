import java.io.*;
import java.util.*;

public class _8VCVentureCupqF {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		final int mod = (int)1e9 + 7;
		int n = in.nextInt();
		int K = in.nextInt();
		
		int a[] = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		
		Arrays.sort(a);
		
		int dp[][][] = new int[2][n + 1][K + 1];
		
		for(int i = 0; i <= K; i++)
			dp[1][0][i] = 1;
		
		
		for(int i = n - 1; i >= 0; i--){
			for(int j = 0; j <= i; j++){
				for(int k = 0; k <= K; k++){
					int p = i;
					i = 0;
					if(j == 0){
						dp[i][j][k] = dp[i + 1][j][k];
						dp[i][j][k] += dp[i + 1][j + 1][k];
						if(dp[i][j][k] >= mod)
							dp[i][j][k] -= mod;
					}
					
					else if(k + j*(a[p] - a[p - 1]) <= K){
						dp[i][j][k] += (j+1L)*dp[i + 1][j][k + j*(a[p] - a[p - 1])] % mod;
						dp[i][j][k] += dp[i + 1][j + 1][k + j*(a[p] - a[p - 1])];
						if(dp[i][j][k] >= mod)
							dp[i][j][k] -= mod;
						dp[i][j][k] += j*1L*dp[i + 1][j - 1][k + j*(a[p] - a[p - 1])] % mod;
						if(dp[i][j][k] >= mod)
							dp[i][j][k] -= mod;
					}
					i = p;
					//System.out.println(i + " " + j + " " + k + " " + dp[i][j][k]);
				}
			}
			for(int j = 0; j <= i; j++){
				for(int k = 0; k <= K; k++){
					dp[1][j][k] = dp[0][j][k];
					dp[0][j][k] = 0;
				}
			}
		}

		w.println(dp[1][0][0]);
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
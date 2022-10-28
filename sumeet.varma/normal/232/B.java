import java.io.*;
import java.util.*;

public class R144qBTable {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		final int mod = (int)1e9 + 7;
		
		int n = in.nextInt();
		long m = in.nextLong();
		int k = in.nextInt();
		
		int c[][] = new int[n + 1][n + 1];
		c[0][0] = 1;
		for(int i = 1; i <= n; i++){
			c[i][0] = c[i][i] = 1;
			for(int j = 1; j < i; j++)
				c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
		
		int d[] = new int[n + 1];
		for(int i = 0; i <= n; i++)
			d[i] = (int)pow(c[n][i] , m/n , mod);
		
		int e[] = new int[n + 1];
		for(int i = 0; i <= n; i++)
			e[i] = (int)pow(c[n][i] , m/n + 1, mod);
		
		int t = (int)(m % n);
		
		int dp[][] = new int[n][k + 1];
		
		for(int i = 0; i <= k; i++)
			dp[n - 1][i] = (k - i <= n ? d[k - i] : 0);
		
		for(int i = n - 2; i >= 0; i--)
			for(int j = 0; j <= k; j++)
				for(int x = 0; x + j <= k && x <= n; x++)
					dp[i][j] = (int)(( dp[i][j] + dp[i + 1][x + j] * 1L * (i < t ? e[x] : d[x])) % mod);
			
		w.println(dp[0][0]);
		w.close();
	}
	
	static long pow(int a, long b, int mod){
		if(b == 0)
			return 1;
		long t = pow(a , b >> 1, mod);
		t = (t * t) % mod;
		if( (b & 1) != 0)
			t = (t * a) % mod;
		return t;
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
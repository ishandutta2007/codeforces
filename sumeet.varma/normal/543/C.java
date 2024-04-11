import java.io.*;
import java.util.*;

/* java.is.awesome */

public class R543qCRememberingStrings {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		char s[][] = new char[n][m];
		for(int i = 0; i < n; i++)	s[i] = in.readString().toCharArray();
		
		int a[][] = new int[n][m];
		for(int i = 0; i < n; i++)	a[i] = in.nextIntArray(m);
		
		int op[][] = new int[n][m];
		int co[][] = new int[n][m];
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int max = 0;
				for(int k = 0; k < n; k++){
					if(s[k][j] == s[i][j]){
						op[i][j] |= 1 << k;
						co[i][j] += a[k][j];
						max = Math.max(max, a[k][j]);
					}
				}
				co[i][j] -= max;
			}
		}
		
		
		int dp[] = new int[1 << n];
		
		for(int i = (1 << n) - 2; i >= 0; i--){
			int lowest = -1;
			for(int j = 0; j < n; j++){
				if( (i & (1 << j)) == 0){
					lowest = j;
					break;
				}
			}
			dp[i] = Integer.MAX_VALUE / 3;
			for(int j = 0; j < m; j++){
				dp[i] = Math.min(dp[i], dp[i | (1 << lowest)] + a[lowest][j]);
				dp[i] = Math.min(dp[i], dp[i | op[lowest][j]] + co[lowest][j]);
			}
		}
		
		w.println(dp[0]);
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
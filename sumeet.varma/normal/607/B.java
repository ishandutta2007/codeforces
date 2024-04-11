import java.io.*;
import java.util.*;

public class R336qB {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		int a[] = new int[n + 2];
		for (int i = 1; i <= n; i++)
			a[i] = in.nextInt();

		boolean isPali[][] = new boolean[n + 5][n + 5];
		int dp[][] = new int[n + 5][n + 5];

		for (int i = 1; i <= n; i++) {
			isPali[i][i] = true;
			dp[i][i] = 1;
			if (a[i + 1] == a[i]){
				isPali[i][i + 1] = true;
				dp[i][i+1] = 1;
			}
			else
				dp[i][i+1] = 2;
		}

		for (int l = 2; l < n; l++){
			for (int i = 1; i + l <= n; i++){
				isPali[i][i + l] = a[i] == a[i + l] && isPali[i + 1][i + l - 1];
				if(isPali[i][i + l])
					dp[i][ i + l] = 1;
				else
					dp[i][ i + l] = l + 1;
				if(a[i] == a[i + l])
					dp[i][i + l] = Math.min(dp[i][i + l], dp[i + 1][i + l - 1]);
				for(int k = i;k < i + l; k++)
					dp[i][i + l] = Math.min(dp[i][i + l], dp[i][k] + dp[k+1][i + l]);
			}
		}
		
		w.println(dp[1][n]);
		w.close();
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
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
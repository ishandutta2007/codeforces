import java.io.*;
import java.util.*;

public class R107qDMissionImpassable {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		int a[] = new int[n + 1];
		for (int i = 1; i <= n; i++)
			a[i] = in.nextInt();

		char s[] = ("$" + in.readString()).toCharArray();

		if (n == 1) {
			w.println(Math.max(0, a[1]));
			w.close();
			return;
		}

		int dp[][][] = new int[n + 1][n + 1][n + 1];
		
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				for (int k = 0; k <= n; k++)
					dp[i][j][k] = -1;

		for (int i = 1; i <= n; i++) {
			dp[i][i][1] = 0;
			for (int l = 1; l <= n; l++)
				if (dp[i][i][l] != -1 && a[l] != -1)
					dp[i][i][0] = Math.max(dp[i][i][0], dp[i][i][l] + a[l]);
		}

		for (int i = 1; i + 1 <= n; i++) {
			dp[i][i + 1][1] = a[1];
			dp[i][i + 1][2] = s[i] == s[i + 1] ? 0 : -1;

			for (int l = 1; l <= n; l++)
				if (dp[i][i + 1][l] != -1 && a[l] != -1)
					dp[i][i + 1][0] = Math.max(dp[i][i + 1][0], dp[i][i + 1][l] + a[l]);
		}

		for (int l = 2; l < n; l++) {
			for (int i = 1, j = i + l; j <= n; i++, j++) {

				for (int x = 1; x <= l + 1; x++) {
					dp[i][j][x] = -1;

					if (s[i] == s[j] && x >= 2)
						if (dp[i + 1][j - 1][x - 2] != -1)
							dp[i][j][x] = dp[i + 1][j - 1][x - 2];

					for (int k = i; k < j; k++)
						if (dp[i][k][x] != -1 && dp[k + 1][j][0] != -1)
							dp[i][j][x] = Math.max(dp[i][j][x], dp[i][k][x] + dp[k + 1][j][0]);

					for (int k = j; k > i; k--)
						if (dp[k][j][x] != -1 && dp[i][k - 1][0] != -1)
							dp[i][j][x] = Math.max(dp[i][j][x], dp[i][k - 1][0] + dp[k][j][x]);

					if (dp[i][j][x] != -1 && a[x] != -1)
						dp[i][j][0] = Math.max(dp[i][j][0], dp[i][j][x] + a[x]);

				}
			}
		}

		int ans[][] = new int[n + 1][n + 1];

		for (int i = 1; i <= n; i++)
			ans[i][i] = a[1] == -1 ? 0 : a[1];

		for (int i = 1; i + 1 <= n; i++) {
			ans[i][i + 1] = Math.max(ans[i][i + 1], 2 * a[1]);
			if (s[i] == s[i + 1])
				ans[i][i + 1] = Math.max(ans[i][i + 1], a[2]);
		}

		for (int l = 2; l < n; l++) {
			for (int i = 1, j = i + l; j <= n; i++, j++) {
				for (int k = i; k < j; k++)
					ans[i][j] = Math.max(ans[i][j], ans[i][k] + ans[k + 1][j]);
				ans[i][j] = Math.max(ans[i][j], dp[i][j][0]);
			}
		}

		w.println(ans[1][n]);
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
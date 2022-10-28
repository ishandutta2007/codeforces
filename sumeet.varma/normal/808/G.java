import java.io.*;
import java.util.*;

public class ER21qG {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		char s[] = in.readString().toCharArray();
		int n = s.length;

		char t[] = in.readString().toCharArray();
		int m = t.length;
		int kmp[] = getLPSArray(t);

		int v[][] = new int[m][26];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 26; j++) {
				if (t[i] - 'a' == j) {
					v[i][j] = i + 1;
				} else if (i > 0) {
					v[i][j] = v[kmp[i - 1]][j];
				}
			}
		}
		
		/*
		System.out.println(v[2][0]);
		System.out.println(v[4][0]);
		System.out.println(kmp[4]);
		*/

		int dp[][] = new int[n + 1][m];

		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				if (s[i] == '?') {
					for (int x = 0; x < 26; x++) {
						int newj = v[j][x];
						//if (i == 4 && j == 4 && x == 0)
							//System.out.println("newj " + newj);
						if (newj == m) {
							newj = kmp[m - 1];
							dp[i][j] = Math.max(dp[i][j], 1 + dp[i + 1][newj]);
						} else {
							dp[i][j] = Math.max(dp[i][j], dp[i + 1][newj]);
						}
					}
				} else {
					int newj = v[j][s[i] - 'a'];
					if (newj == m) {
						newj = kmp[m - 1];
						dp[i][j] = Math.max(dp[i][j], 1 + dp[i + 1][newj]);
					} else {
						dp[i][j] = Math.max(dp[i][j], dp[i + 1][newj]);
					}
				}
				//System.out.println(i + " " + j + " " + dp[i][j]);
			}
		}

		w.println(dp[0][0]);
		w.close();
	}

	public static int[] getLPSArray(char s[]) {
		int n = s.length;
		int lps[] = new int[n];
		lps[0] = 0;
		int len = 0;
		for (int i = 1; i < n;) {
			if (s[i] == s[len]) {
				lps[i++] = ++len;
			} else {
				if (len == 0) {
					lps[i++] = 0;
				} else {
					len = lps[len - 1];
				}
			}
		}
		return lps;
	}
	
	static class InputReader {

		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, snumChars;

		public InputReader(InputStream st) {
			this.stream = st;
		}

		public int read() {
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
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			return a;
		}

		public String readString() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public String nextLine() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

	}

}
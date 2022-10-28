import java.io.*;
import java.util.*;

public class PalindromePairs {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		char s[] = in.readString().toCharArray();
		Manacher man = new Manacher(s);

		int n = s.length;
		int start[] = new int[n + 1];
		int end[] = new int[n + 1];

		for (int i = 0,j = 0; i < man.p.length; i += 2, j++) {
				start[j + 1]--;
				start[j - man.p[i]/2]++;
				end[j]++;
				end[j + man.p[i]/2 + 1]--;
		}
		
		for(int i = 1,j = 0; i < man.p.length; i += 2, j++){
			start[j + 1]--;
			start[j - man.p[i]/2 + 1]++;
			end[j + 1]++;
			end[j + 1 + man.p[i]/2]--;
		}

		for (int i = 1; i < n; i++) {
			start[i] += start[i - 1];
			end[i] += end[i - 1];
		}

		for (int i = n - 2; i >= 0; i--)
			start[i] += start[i + 1];

		long ans = 0;
		for (int i = 0; i < n - 1; i++)
			ans += end[i] * start[i + 1];

		w.println(ans);
		w.close();
	}

	static public class Manacher {
		private int[] p; // p[i] = length of longest palindromic substring of t,
							// centered at i
		private char s[]; // original string
		private char[] t; // transformed string

		public Manacher(char[] s) {
			this.s = s;
			preprocess();
			p = new int[t.length];

			int center = 0, right = 0;
			for (int i = 1; i < t.length - 1; i++) {
				int mirror = 2 * center - i;

				if (right > i)
					p[i] = Math.min(right - i, p[mirror]);

				while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
					p[i]++;

				if (i + p[i] > right) {
					center = i;
					right = i + p[i];
				}
			}

			int ans[] = new int[p.length - 4];
			for (int i = 2; i < p.length - 2; i++)
				ans[i - 2] = p[i];

			p = ans;
		}

		private void preprocess() {
			t = new char[s.length * 2 + 3];
			t[0] = '$';
			t[s.length * 2 + 2] = '@';
			for (int i = 0; i < s.length; i++) {
				t[2 * i + 1] = '#';
				t[2 * i + 2] = s[i];
			}
			t[s.length * 2 + 1] = '#';
		}

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
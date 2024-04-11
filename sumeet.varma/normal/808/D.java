import java.io.*;
import java.util.*;

public class ER21qD {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		int a[] = in.nextIntArray(n);

		long tot = 0;
		for (int x : a)
			tot += x;

		{
			long pre = 0;
			TreeSet<Long> set = new TreeSet<Long>();
			for (int i = 0; i < n; i++) {
				pre += a[i];
				set.add((long)a[i]);
				long suf = tot - pre;
				if (pre == suf) {
					System.out.println("YES");
					return;
				}
				if ((pre-suf) %2 == 0 && set.contains((pre - suf)/2)) {
					System.out.println("YES");
					return;
				}
			}
		}
		
		{
			long suf = 0;
			TreeSet<Long> set = new TreeSet<Long>();
			for (int i = n - 1; i >= 0; i--) {
				suf += a[i];
				set.add((long)a[i]);
				long pre = tot - suf;
				if (pre == suf) {
					System.out.println("YES");
					return;
				}
				if ((suf - pre) % 2 == 0 && set.contains((suf - pre)/2)) {
					System.out.println("YES");
					return;
				}
			}
		}
		
		System.out.println("NO");
		w.close();
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
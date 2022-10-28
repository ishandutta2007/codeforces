import java.io.*;
import java.util.*;

public class R320qC {

	static int n;
	static int a[];

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();

		a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();

		double ans = Double.MAX_VALUE;
		double L = -20000, R = 20000;

		for (int i = 1; i <= 100; i++) {
			double mid1 = L + (R - L) / (3.0);
			double mid2 = R - (R - L) / (3.0);
			double x = f(mid1), y = f(mid2);
			ans = Math.min(ans, Math.min(x, y));
			if (x < y)
				R = mid2;
			else
				L = mid1;
		}

		w.println(ans);
		w.close();
	}

	static public double f(double x) {
		double max = 0;
		double min = 0;
		double pre = 0;
		double ans = Double.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			pre += a[i] - x;
			ans = Math.max(ans, Math.abs(pre - max));
			ans = Math.max(ans, Math.abs(pre - min));
			max = Math.max(max, pre);
			min = Math.min(min, pre);
		}
		return ans;
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
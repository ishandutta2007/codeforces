import java.io.*;
import java.util.*;

public class _8VCVentureCupqE {

	static final int mod = (int) 1e9 + 7;
	static int n;
	static int a[];
	static long p[];

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();

		a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();

		Arrays.sort(a);

		p = new long[n];
		for (int i = 0; i < n; i++)
			p[i] = a[i] + (i == 0 ? 0 : p[i - 1]);

		int idx = 0, length = 0;
		Fraction ans = new Fraction(0, 1);

		for (int i = 0; i < n; i++) {

			int max = Math.min(i, n - 1 - i), start = 0, end = max, bestLength = 0;
			Fraction bestAns = new Fraction(0, 1);

			while (end - start + 1 > 3) {
				int mid1 = start + (end - start) / 3;
				int mid2 = end - (end - start) / 3;

				Fraction ans1 = f(i, mid1);
				Fraction ans2 = f(i, mid2);

				if (ans1.compareTo(ans2) < 0) {
					if (ans2.compareTo(bestAns) > 0) {
						bestAns = ans2;
						bestLength = mid2;
					}
					start = mid1;
				}

				else {
					if (ans.compareTo(bestAns) > 0) {
						bestAns = ans1;
						bestLength = mid1;
					}
					end = mid2;
				}
			}

			for (int j = start; j <= end; j++) {
				Fraction ans1 = f(i, j);
				if (ans1.compareTo(bestAns) > 0) {
					bestAns = ans1;
					bestLength = j;
				}
			}

			if (bestAns.compareTo(ans) > 0) {
				ans = bestAns;
				idx = i;
				length = bestLength;
			}
		}

		w.println(2 * length + 1);

		w.print(a[idx] + " ");
		for (int i = 1; i <= length; i++) {
			w.print(a[idx - i] + " ");
			w.print(a[n - i] + " ");
		}

		w.println();
		w.close();
	}

	static Fraction f(int center, int length) {
		if (length == 0)
			return new Fraction(0L, 1L);
		long sum = a[center] + p[center - 1]
				- (center - 1 - length < 0 ? 0 : p[center - 1 - length])
				+ p[n - 1] - p[n - 1 - length];
		return new Fraction(sum - a[center] * (1L + 2 * length), 1 + 2 * length);
	}

	static Fraction brute(int[] a) {
		int n = a.length;
		Fraction max = new Fraction(0, 1);
		for (int i = 1; i < n - 1; i++) {
			long sum = a[i], cnt = 1;
			for (int x = i - 1, y = n - 1; x >= 0 && y > i; x--, y--) {
				sum += a[x] + a[y];
				cnt += 2;
				if (new Fraction(sum - cnt * a[i], cnt).compareTo(max) > 0)
					max = new Fraction(sum - cnt * a[i], cnt);
			}
		}
		return max;
	}

	static class Fraction {
		long num, den;

		Fraction(long num, long den) {
			this.num = num;
			this.den = den;
		}

		public int compareTo(Fraction b) {
			return Long.compare(num * b.den, b.num * den);
		}
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
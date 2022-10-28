import java.io.*;
import java.util.*;

public class R339qB {

	public static void main(String args[]) throws Exception {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		long A = in.nextLong();
		long cf = in.nextInt();
		long cm = in.nextInt();
		long m = in.nextLong();

		Pair p[] = new Pair[n + 2];
		for (int i = 1; i <= n; i++)
			p[i] = new Pair(i, in.nextInt());
		p[0] = new Pair(0, -1);
		p[n + 1] = new Pair(n + 1, (int) A + 1);

		Arrays.sort(p);

		int a[] = new int[n + 2];
		for (int i = 1; i <= n; i++)
			a[i] = p[i].val;

		long pre[] = new long[n + 2];
		for (int i = 1; i <= n; i++)
			pre[i] = pre[i - 1] + a[i];

		long suf[] = new long[n + 2];
		for (int i = n; i >= 1; i--)
			suf[i] = suf[i + 1] + a[i];

		long ans[] = new long[n + 2];
		long min[] = new long[n + 2];
		int bestAns = -1;
		long maxAns = -1;

		if (n * A - pre[n] <= m) {
			maxAns = n * cf + A * cm;
			bestAns = n;
			min[n] = A;
		}

		for (int i = 0; i < n; i++) {
			long start = 0, end = A + 1;
			int last = n - i;
			long needed = i * A - suf[n + 1 - i];
			if (needed > m)
				break;
			long left = m - needed;
			left = Math.min(left, m);
			while (start < end) {
				long mid = (start + end) >> 1;
				int ss = 1, ee = last + 1;
				int aa = 0;
				while (ss < ee) { // last element smaller than mid
					int mm = (ss + ee) >> 1;
					if (a[mm] < mid) {
						aa = mm;
						ss = mm + 1;
					} else
						ee = mm;
				}
				if (mid * aa - pre[aa] <= left) {
					min[i] = mid;
					start = mid + 1;
				} else
					end = mid;
			}
			long nowAns = i * cf + min[i] * cm;
			if (nowAns > maxAns) {
				maxAns = nowAns;
				bestAns = i;
			}
		}

		w.println(maxAns);

		if (bestAns == -1) {
			bestAns = 0;
			min[0] = a[1];
		}

		for (int i = 1; i <= n - bestAns; i++)
			ans[p[i].idx] = Math.max(a[i], min[bestAns]);
		for (int i = n - bestAns + 1; i <= n; i++)
			ans[p[i].idx] = A;
		for (int i = 1; i <= n; i++)
			w.print(ans[i] + " ");
		w.println();

		w.close();
	}

	static class Pair implements Comparable<Pair> {
		int idx, val;

		Pair(int i, int v) {
			idx = i;
			val = v;
		}

		public int compareTo(Pair o) {
			if (val != o.val)
				return Integer.compare(val, o.val);
			return Integer.compare(idx, o.idx);
		}

		public String toString() {
			return idx + " " + val;
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
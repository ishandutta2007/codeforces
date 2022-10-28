import java.io.*;
import java.util.*;

public class R352qA {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int ax = in.nextInt();
		int ay = in.nextInt();

		int bx = in.nextInt();
		int by = in.nextInt();

		int tx = in.nextInt();
		int ty = in.nextInt();

		int n = in.nextInt();

		long x[] = new long[n];
		long y[] = new long[n];

		double a[] = new double[n];
		double b[] = new double[n];
		double t[] = new double[n];
		
		Pair A[] = new Pair[n];
		Pair B[] = new Pair[n];
		Pair T[] = new Pair[n];
		double R = 0;
		
		for (int i = 0; i < n; i++) {
			x[i] = in.nextLong();
			y[i] = in.nextLong();
			a[i] = (x[i] - ax) * (x[i] - ax) + (y[i] - ay) * (y[i] - ay);
			b[i] = (x[i] - bx) * (x[i] - bx) + (y[i] - by) * (y[i] - by);
			t[i] = (x[i] - tx) * (x[i] - tx) + (y[i] - ty) * (y[i] - ty);
			a[i] = Math.sqrt(a[i]);
			b[i] = Math.sqrt(b[i]);
			t[i] = Math.sqrt(t[i]);
			A[i] = new Pair(i, a[i] - t[i]);
			B[i] = new Pair(i, b[i] - t[i]);
			T[i] = new Pair(i, t[i]);
			R += t[i];
		}
		
		double ans = Long.MAX_VALUE;
		
		for(int i = 0; i < n; i++){
			double now = 2*R - t[i] + a[i];
			ans = Math.min(ans, now);
			now = 2*R - t[i] + b[i];
			ans = Math.min(ans, now);
			//System.out.println(i + "  " + ans);
		}
		
		//System.out.println(ans);
		
		Arrays.sort(A);
		Arrays.sort(B);
		
		//System.out.println(Arrays.deepToString(A));
		//System.out.println(Arrays.deepToString(B));
		
		for(int i = 0; i < Math.min(3, n); i++){
			for(int j = 0; j < Math.min(3, n); j++){
				if(A[i].idx != B[j].idx){
					double now = 2*R;
					now += a[A[i].idx] - t[A[i].idx];
					now += b[B[j].idx] - t[B[j].idx];
					ans = Math.min(ans, now);
				}
			}
		}
		
		w.println(ans);
		w.close();
	}

	static class Pair implements Comparable<Pair> {
		int idx;
		double val;

		Pair(int i, double v) {
			idx = i;
			val = v;
		}

		public int compareTo(Pair o) {
			if (val != o.val)
				return Double.compare(val, o.val);
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
import java.io.*;
import java.util.*;

//java.is.awesome
//Credits : qwerty7877788

public class R333qEAMuseumRobbery {

	static int n, k, q;
	static U a[];
	static int t[], qA[], qB[];
	static int ans[][];
	static final int mod = (int) 1e9 + 7;
	static final long mod2 = mod * 1L * mod;
	static final int p = (int) 1e7 + 19;
	static int[] pow;
	static final InputReader in = new InputReader(System.in);
	static final PrintWriter w = new PrintWriter(System.out);

	public static void main(String[] args) {

		n = in.nextInt();
		k = in.nextInt();

		a = new U[n];
		for (int i = 0; i < n; i++)
			a[i] = new U(in.nextInt(), in.nextInt());

		q = in.nextInt();

		t = new int[q];
		qA = new int[q];
		qB = new int[q];

		int total = n, time = 0;

		for (int i = 0; i < q; i++) {
			t[i] = in.nextInt();
			if (t[i] == 1) {
				qA[i] = in.nextInt();
				qB[i] = in.nextInt();
				total++;
			} else if (t[i] == 2) {
				qA[i] = in.nextInt();
			} else
				time++;
		}
		
		int from[] = new int[total];
		int to[] = new int[total];
		int val[] = new int[total];
		int mass[] = new int[total];

		for (int i = 0; i < n; i++) {
			val[i] = a[i].v;
			mass[i] = a[i].m;
		}

		Arrays.fill(to, time);

		total = n;
		time = 0;

		for (int i = 0; i < q; i++) {
			if (t[i] == 1) {
				val[total] = qA[i];
				mass[total] = qB[i];
				from[total] = time;
				total++;
			} else if (t[i] == 2) {
				to[qA[i] - 1] = time;
			} else
				time++;
		}
		
		//System.out.println(time + " " + total);
		//System.out.println(Arrays.toString(from));
		//System.out.println(Arrays.toString(to));

		pow = new int[k];
		pow[0] = 1;
		for (int i = 1; i < k; i++)
			pow[i] = (int) ((pow[i - 1] * 1L * p) % mod);

		O root = new O(0, time - 1);

		for (int i = 0; i < total; i++)
			root.add(from[i], to[i] - 1, new U(val[i], mass[i]));

		ans = new int[100][k + 1];
		root.go(1);

		w.close();
	}

	static class O {

		ArrayList<U> list;
		O left, right;
		int from, to;

		O(int s, int e) {
			this.from = s;
			this.to = e;
			list = new ArrayList<U>();
			if (s != e) {
				int m = (s + e) >> 1;
				left = new O(s, m);
				right = new O(m + 1, e);
			}
		}

		void add(int l, int r, U curr) {
			if (r < from || l > to)
				return;
			if (l <= from && to <= r){
				list.add(curr);
				return;
			}
			if (from != to) {
				left.add(l, r, curr);
				right.add(l, r, curr);
			}
		}

		void go(int h) {
			for (int i = 0; i <= k; i++)
				ans[h][i] = ans[h - 1][i];
			for (U u : list) {
				for (int j = k - u.m; j >= 0; j--) {
					int now = ans[h][j] + u.v;
					if (now > ans[h][j + u.m])
						ans[h][j + u.m] = now;
				}
			}
			if (from == to) {
				long answer = 0;
				for (int i = 1; i <= k; i++) {
					answer += ans[h][i] * 1L * pow[i - 1];
					if (answer >= mod2) 
						answer -= mod2;
				}
				w.println(answer % mod);
			}
			else{
				left.go(h + 1);
				right.go(h + 1);
			}
		}
	}

	static class U {
		int v, m;

		U(int v, int m) {
			this.v = v;
			this.m = m;
		}

		public String toString() {
			return "U : " + v + " " + m;
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
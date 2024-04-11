import java.io.*;
import java.util.*;

public class _8VCFinalsqD {

	static int d, n, m;
	static int segtree[];
	static Pair p[];

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		d = in.nextInt();
		n = in.nextInt();
		m = in.nextInt();

		p = new Pair[m + 2];
		p[0] = new Pair(0, 0);
		for (int i = 1; i <= m; i++)
			p[i] = new Pair(in.nextInt(), in.nextInt());
		p[m + 1] = new Pair(d, (int)1e7);

		Arrays.sort(p);

		segtree = new int[4 * (m + 3)];
		build(0, m + 1, 0);

		w.println(go(0, m + 1, n));
		w.close();
	}
	
	static long go(int s, int e, long extra){
		
		//System.out.println(s + " " + e + " " + extra);
		
		if(s == e)
			return 0;
		
		if(s + 1 == e){
			long dist = p[e].x - p[s].x;
			if(dist > n)
				return -1;
			return Math.max(0, dist - extra) * p[s].y;
		}
		
		int mid = find(0 , m + 1 , 0 , s + 1 , e - 1);
		long dist = p[mid].x - p[s].x;
		
		if(dist <= extra){
			long ans1 = 0;
			long left = extra - dist;
			long t = Math.min(n, p[e].x - p[mid].x);
			long ans2 = go(mid , e , t);
			if(ans1 == -1 || ans2 == -1)
				return -1;
			return ans1 + ans2 + Math.max(0 , (t - left)) * p[mid].y;
		}
		
		else{
			long ans1 = go(s , mid , extra);
			long t = Math.min(n, p[e].x - p[mid].x);
			long ans2 = go(mid, e , t);
			if(ans1 == -1 || ans2 == -1)
				return -1;
			return ans1 + ans2 + Math.max(0 , t) * p[mid].y;
		}
	}

	static class Pair implements Comparable<Pair> {
		int x, y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public int compareTo(Pair o) {
			if (x != o.x)
				return Integer.compare(x, o.x);
			return Integer.compare(y, o.y);
		}

		public String toString() {
			return x + " " + y;
		}
	}

	public static void build(int s, int e, int c) {
		if (s == e) {
			segtree[c] = s;
			return;
		}
		int m = (s + e) >> 1;
		build(s, m, 2 * c + 1);
		build(m + 1, e, 2 * c + 2);
		segtree[c] = p[segtree[2 * c + 1]].y <= p[segtree[2 * c + 2]].y ? segtree[2 * c + 1]
				: segtree[2 * c + 2];
	}

	public static int find(int s, int e, int c, int l, int r) {
		if (s == l && e == r)
			return segtree[c];
		int m = (s + e) >> 1;
		if (r <= m)
			return find(s, m, 2 * c + 1, l, r);
		if (l > m)
			return find(m + 1, e, 2 * c + 2, l, r);
		int x = find(s, m, 2 * c + 1, l, m);
		int y = find(m + 1, e, 2 * c + 2, m + 1, r);
		return p[x].y <= p[y].y ? x : y;
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
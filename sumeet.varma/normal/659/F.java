import java.io.*;
import java.util.*;

public class R346qF {

	static int n, m;
	static int ans[][];
	static boolean vis[][];
	static int v[][];
	static int need;
	static int proVal;
	static final int dx[] = new int[] { -1, 1, 0, 0 };
	static final int dy[] = new int[] { 0, 0, -1, 1 };

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		m = in.nextInt();
		long k = in.nextLong();

		Pair p[] = new Pair[n * m];
		v = new int[n][m];

		for (int i = 0, z = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				p[z++] = new Pair(i, j, in.nextInt());
				v[i][j] = p[z - 1].val;
			}
		}

		Arrays.sort(p);

		DisjointSet ds = new DisjointSet(n * m);
		boolean g[][] = new boolean[n][m];

		for (int i = n * m - 1; i >= 0; i--) {
			g[p[i].i][p[i].j] = true;
			// System.out.println(p[i].i + " " + p[i].j);
			for (int j = 0; j < 4; j++) {
				int x = p[i].i + dx[j];
				int y = p[i].j + dy[j];
				if (x >= 0 && x < n && y >= 0 && y < m && g[x][y]) {
					ds.merge(m * p[i].i + p[i].j, m * x + y);
					// System.out.println(p[i].i + " " + p[i].j + " " + x + " "
					// + y);
					// System.out.println();
				}
			}
			// System.out.println(ds.size[ds.find(n * 0 + 2)]);
			if (k % p[i].val == 0) {
				// System.out.println("here " + ds.size[ds.find(n * p[i].i +
				// p[i].j)]);
				if (ds.size[ds.find(m * p[i].i + p[i].j)] >= k / p[i].val) {
					w.println("YES");
					need = (int) (k / p[i].val);
					proVal = p[i].val;
					vis = new boolean[n][m];
					ans = new int[n][m];
					dfs(p[i].i, p[i].j);
					for (int c = 0; c < n; c++) {
						for (int d = 0; d < m; d++)
							w.print(ans[c][d] + " ");
						w.println();
					}
					w.close();
					return;
				}
			}
		}

		w.println("NO");
		w.close();
	}

	static void dfs(int x, int y) {
		if (x < 0 || x >= n || y < 0 || y >= m)
			return;
		if (vis[x][y])
			return;
		vis[x][y] = true;
		if (need > 0 && v[x][y] >= proVal) {
			ans[x][y] = proVal;
			need--;
			for (int k = 0; k < 4; k++) {
				int i = x + dx[k];
				int j = y + dy[k];
				dfs(i, j);
			}
		}
	}

	static class Pair implements Comparable<Pair> {
		int i, j, val;

		Pair(int i, int j, int v) {
			this.i = i;
			this.j = j;
			val = v;
		}

		public int compareTo(Pair o) {
			return Integer.compare(val, o.val);
		}

		public String toString() {
			return i + " " + j + " " + val;
		}
	}

	static public class DisjointSet {

		public int rank[], parent[], size[];
		public int n, comp;

		public DisjointSet(int n) {
			this.n = n;
			makeSet();
		}

		public void makeSet() {
			rank = new int[n];
			parent = new int[n];
			for (int i = 0; i < n; i++)
				parent[i] = i;
			size = new int[n];
			Arrays.fill(size, 1);
			comp = n;
		}

		public int find(int x) {
			if (parent[x] != x)
				parent[x] = find(parent[x]);
			return parent[x];
		}

		public void merge(int x, int y) {
			int xRoot = find(x);
			int yRoot = find(y);

			if (xRoot == yRoot)
				return;

			size[xRoot] = size[yRoot] = size[xRoot] + size[yRoot];

			if (rank[xRoot] < rank[yRoot])
				parent[xRoot] = yRoot;
			else {
				parent[yRoot] = xRoot;
				if (rank[xRoot] == rank[yRoot])
					rank[xRoot]++;
			}

			comp--;
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
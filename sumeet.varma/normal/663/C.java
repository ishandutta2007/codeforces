import java.io.*;
import java.util.*;

public class R347qC {

	static ArrayList<Integer> g[];
	static int color[];
	static boolean yes;
	static int n, m;
	static int u[], v[];
	static boolean c[];

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		m = in.nextInt();

		u = new int[m];
		v = new int[m];
		c = new boolean[m];

		for (int i = 0; i < m; i++) {
			u[i] = in.nextInt() - 1;
			v[i] = in.nextInt() - 1;
			c[i] = in.readString().equals("R");
		}

		int ans1[] = get();
		//System.out.println(Arrays.toString(ans1));
		
		for (int i = 0; i < m; i++)
			c[i] = !c[i];

		int ans2[] = get();

		if (ans1.length < ans2.length) {
			if (ans1.length > n)
				w.println(-1);
			else {
				w.println(ans1.length);
				for (int x : ans1)
					w.print(x + " ");
			}
		} else {
			if (ans2.length > n)
				w.println(-1);
			else {
				w.println(ans2.length);
				for (int x : ans2)
					w.print(x + " ");
			}
		}

		w.println();
		w.close();
	}

	@SuppressWarnings("unchecked")
	static public int[] get() {
		DisjointSet ds = new DisjointSet(n);
		for (int i = 0; i < m; i++) 
			if (c[i])
				ds.merge(u[i], v[i]);

		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<Integer>();

		for (int i = 0; i < m; i++) {
			if (!c[i]) {
				g[ds.find(u[i])].add(ds.find(v[i]));
				g[ds.find(v[i])].add(ds.find(u[i]));
			}
		}

		yes = true;
		color = new int[n];
		for (int i = 0; i < n; i++)
			if (color[i] == 0 && ds.find(i) == i)
				dfs(i, i + 1);

		int ans[] = new int[n + 1];

		if (yes) {
			int a[] = new int[n + 1];
			int b[] = new int[n + 1];
			
			for(int i = 0; i < n; i++){
				int x = ds.find(i);
				if(color[x] > 0)
					a[color[x]]++;
				else
					b[-color[x]]++;
			}
			
			int now = 0;
			for(int i = 0; i < n; i++)
				now += Math.min(a[i], b[i]);
			
			ans = new int[now];
			int k = 0;
			for(int i = 0; i < n; i++){
				int x = ds.find(i);
				if(color[x] > 0){
					if(a[color[x]] <= b[color[x]])
						ans[k++] = i + 1;
				}
				else{
					if(b[-color[x]] < a[-color[x]])
						ans[k++] = i + 1;
				}
			}
		}

		return ans;
	}

	static public void dfs(int x, int c) {
		if (color[x] != 0) {
			if (color[x] != c)
				yes = false;
			return;
		}
		color[x] = c;
		for (int next : g[x])
			dfs(next, -c);
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
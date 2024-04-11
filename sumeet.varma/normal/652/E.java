import java.io.*;
import java.util.*;

public class ER10qF {

	static ArrayList<Integer> g[];
	static boolean vis[];
	static int disc[], low[], id[], parent[];
	static int time, total;
	static ArrayList<Integer> comp[];
	static int bpar[];
	static boolean bparGood[];
	static boolean bcompGood[];
	static boolean ans;
	static int depth[];

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();

		g = new ArrayList[n + 1];
		for (int i = 1; i <= n; i++)
			g[i] = new ArrayList<Integer>();

		while (m-- > 0) {
			int u = in.nextInt();
			int v = in.nextInt();
			int c = in.nextInt();
			g[u].add(v);
			g[u].add(c);
			g[v].add(u);
			g[v].add(c);
		}

		vis = new boolean[n + 1];
		disc = new int[n + 1];
		low = new int[n + 1];
		parent = new int[n + 1];
		time = 0;
		dfs(1);

		Arrays.fill(vis, false);
		total = 1;
		id = new int[n + 1];
		dfs2(1, total);

		comp = new ArrayList[total + 1];
		for (int i = 1; i <= total; i++)
			comp[i] = new ArrayList<Integer>();

		for (int i = 1; i <= n; i++)
			comp[id[i]].add(i);

		bpar = new int[total + 1];
		bparGood = new boolean[total + 1];
		bcompGood = new boolean[total + 1];
		depth = new int[total + 1];

		dfs3(1, 0);

		int a = in.nextInt();
		int b = in.nextInt();
		
		ans = false;
		go(id[a], id[b]);

		w.println(ans ? "YES" : "NO");
		w.close();
	}

	static void go(int a, int b) {
		while(depth[a] > depth[b]){
			ans |= bcompGood[a];
			ans |= bparGood[a];
			a = bpar[a];
		}
		while(depth[b] > depth[a]){
			ans |= bcompGood[b];
			ans |= bparGood[b];
			b = bpar[b];
		}
		while(a != b){
			ans |= bcompGood[a];
			ans |= bparGood[a];
			a = bpar[a];
			ans |= bcompGood[b];
			ans |= bparGood[b];
			b = bpar[b];
		}
		ans |= bcompGood[a];
	}

	static public void dfs3(int curr, int prev) {

		for (int j = 0; j < comp[curr].size(); j++) {
			int now = comp[curr].get(j);
			int s = g[now].size();
			for (int i = 0; i < s;) {
				int u = g[now].get(i++);
				int z = g[now].get(i++);
				if (id[u] == prev)
					continue;
				else if (id[u] == curr) {
					if (z == 1)
						bcompGood[curr] = true;
				} else {
					int nxt = id[u];
					bpar[nxt] = curr;
					depth[nxt] = depth[curr] + 1;
					dfs3(nxt, curr);
					if (z == 1)
						bparGood[nxt] = true;
				}
			}
		}
	}

	static public void dfs(int curr) {
		disc[curr] = low[curr] = time++;
		vis[curr] = true;
		for (int i = 0; i < g[curr].size(); i += 2) {
			int x = g[curr].get(i);
			if (vis[x]) {
				if (x != parent[curr])
					low[curr] = Math.min(low[curr], disc[x]);
			} else {
				parent[x] = curr;
				dfs(x);
				low[curr] = Math.min(low[x], low[curr]);
			}
		}
	}

	static public void dfs2(int curr, int type) {
		id[curr] = type;
		vis[curr] = true;
		for (int i = 0; i < g[curr].size(); i += 2) {
			int x = g[curr].get(i);
			if (!vis[x]) {
				if (low[x] > disc[curr])
					dfs2(x, ++total);
				else
					dfs2(x, type);
			}
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
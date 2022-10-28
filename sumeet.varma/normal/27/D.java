import java.io.*;
import java.util.*;

public class RingRoad2 {

	static int n, m;
	static int a[], b[];
	static ArrayList<Integer> g[];

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		m = in.nextInt();

		a = new int[m];
		b = new int[m];

		for (int i = 0; i < m; i++) {
			a[i] = in.nextInt();
			b[i] = in.nextInt();
		}

		List<Integer> graph[] = new List[2 * m];
		for (int i = 0; i < 2 * m; i++)
			graph[i] = new ArrayList<Integer>();

		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				if (intersects(i, j)) {
					graph[2 * i].add(2 * j + 1);
					graph[2 * j].add(2 * i + 1);
					graph[2 * i + 1].add(2 * j);
					graph[2 * j + 1].add(2 * i);
				}
			}
		}

		boolean ans[] = solve2Sat(graph);
		if (ans == null)
			w.print("Impossible");
		else
			for (int i = 0; i < ans.length; i++)
				w.print(ans[i] ? 'i' : 'o');
		w.println();

		w.close();
	}

	static void dfs1(List<Integer>[] graph, boolean[] used, List<Integer> order, int u) {
		used[u] = true;
		for (int v : graph[u])
			if (!used[v])
				dfs1(graph, used, order, v);
		order.add(u);
	}

	static void dfs2(List<Integer>[] reverseGraph, int[] comp, int u, int color) {
		comp[u] = color;
		for (int v : reverseGraph[u])
			if (comp[v] == -1)
				dfs2(reverseGraph, comp, v, color);
	}

	public static boolean[] solve2Sat(List<Integer>[] graph) {
		int n = graph.length;
		boolean[] used = new boolean[n];
		List<Integer> order = new ArrayList<>();
		for (int i = 0; i < n; ++i)
			if (!used[i])
				dfs1(graph, used, order, i);

		List<Integer>[] reverseGraph = new List[n];
		for (int i = 0; i < n; i++)
			reverseGraph[i] = new ArrayList<>();
		for (int i = 0; i < n; i++)
			for (int j : graph[i])
				reverseGraph[j].add(i);

		int[] comp = new int[n];
		Arrays.fill(comp, -1);
		for (int i = 0, color = 0; i < n; ++i) {
			int u = order.get(n - i - 1);
			if (comp[u] == -1)
				dfs2(reverseGraph, comp, u, color++);
		}

		for (int i = 0; i < n; ++i)
			if (comp[i] == comp[i ^ 1])
				return null;

		boolean[] res = new boolean[n / 2];
		for (int i = 0; i < n; i += 2)
			res[i / 2] = comp[i] > comp[i ^ 1];

		return res;
	}

	static public boolean intersects(int i, int j) {
		int x = Math.min(a[i], b[i]);
		int y = Math.max(a[i], b[i]);
		boolean cond1 = a[j] > x && a[j] < y;
		boolean cond2 = !(a[j] >= x && a[j] <= y);
		boolean cond3 = b[j] > x && b[j] < y;
		boolean cond4 = !(b[j] >= x && b[j] <= y);
		if (cond1 && cond4)
			return true;
		if (cond2 && cond3)
			return true;
		return false;
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
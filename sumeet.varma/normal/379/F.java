import java.io.*;
import java.util.*;

public class GoodBye2013qFNewYearTree {

	static MyArrayList g[];
	static int n, nodes, cnt;
	static int[] depth, dfs_order, first, minPos;

	public static void main(String args[]) throws Exception {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int q = in.nextInt();

		g = new MyArrayList[4 + 2 * q];
		for (int i = 0; i < g.length; i++)
			g[i] = new MyArrayList();

		g[0].add(1);
		g[0].add(2);
		g[0].add(3);

		int a[] = new int[q];
		for (int i = 0; i < q; i++)
			a[i] = in.nextInt() - 1;

		nodes = 4;
		for (int i = 0; i < q; i++) {
			g[a[i]].add(nodes++);
			g[a[i]].add(nodes++);
		}
		
		Lca(0);
		
		int s = 1, e = 2;
		int d = 2, x;

		nodes = 4;
		for (int i = 0; i < q; i++) {
			x = dist(nodes, s);
			if (x > d) {
				e = nodes;
				d = x;
			}
			x = dist(nodes, e);
			if (x > d) {
				s = nodes;
				d = x;
			}
			nodes++;
			x = dist(nodes, s);
			if (x > d) {
				e = nodes;
				d = x;
			}
			x = dist(nodes, e);
			if (x > d) {
				s = nodes;
				d = x;
			}
			nodes++;
			w.println(d);
		}

		w.close();
	}

	public static int dist(int i, int j) {
		return depth[i] + depth[j] - 2 * depth[lca(i, j)];
	}

	public static void dfs(int u, int d) {
		depth[u] = d;
		dfs_order[cnt++] = u;
		for (int i = 0; i < g[u].size(); i++){
			dfs(g[u].get(i), d + 1);
			dfs_order[cnt++] = u;
		}
	}

	public static void buildTree(int node, int left, int right) {
		if (left == right) {
			minPos[node] = dfs_order[left];
			return;
		}
		int mid = (left + right) >> 1;
		buildTree(2 * node + 1, left, mid);
		buildTree(2 * node + 2, mid + 1, right);
		minPos[node] = depth[minPos[2 * node + 1]] < depth[minPos[2 * node + 2]] ? minPos[2 * node + 1] : minPos[2 * node + 2];
	}

	public static void Lca(int root) {
		depth = new int[nodes];

		n = 2 * nodes - 1;
		dfs_order = new int[n];
		cnt = 0;
		dfs(root, 0);

		minPos = new int[4 * n];
		buildTree(0, 0, n - 1);

		first = new int[nodes];
		for (int i = dfs_order.length - 1; i >= 0; i--)
			first[dfs_order[i]] = i;
	}

	public static int lca(int a, int b) {
		return minPos(Math.min(first[a], first[b]), Math.max(first[a], first[b]), 0, 0, n - 1);
	}

	public static int minPos(int a, int b, int node, int left, int right) {
		if (a == left && right == b)
			return minPos[node];
		int mid = (left + right) >> 1;
		if (a <= mid && b > mid) {
			int p1 = minPos(a, Math.min(b, mid), 2 * node + 1, left, mid);
			int p2 = minPos(Math.max(a, mid + 1), b, 2 * node + 2, mid + 1, right);
			return depth[p1] < depth[p2] ? p1 : p2;
		} else if (a <= mid) {
			return minPos(a, Math.min(b, mid), 2 * node + 1, left, mid);
		} else if (b > mid) {
			return minPos(Math.max(a, mid + 1), b, 2 * node + 2, mid + 1, right);
		} else {
			throw new RuntimeException();
		}
	}

	static public class MyArrayList {

		private int[] myStore;
		private int actSize = 0;

		public MyArrayList() {
			myStore = new int[2];
		}

		public int get(int index) {
			if (index < actSize)
				return myStore[index];
			else
				throw new ArrayIndexOutOfBoundsException();
		}

		public void add(int obj) {
			if (myStore.length - actSize <= 1)
				increaseListSize();
			myStore[actSize++] = obj;
		}

		public int size() {
			return actSize;
		}

		private void increaseListSize() {
			myStore = Arrays.copyOf(myStore, myStore.length * 2);
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
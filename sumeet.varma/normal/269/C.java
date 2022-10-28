import java.io.*;
import java.util.*;

public class R165qCFlawedFlow {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();

		@SuppressWarnings("unchecked")
		ArrayList<Integer> g[] = new ArrayList[n + 1];
		for (int i = 1; i <= n; i++)
			g[i] = new ArrayList<Integer>();

		int flow[] = new int[n + 1];

		int u[] = new int[m + 1];
		int v[] = new int[m + 1];
		int ans[] = new int[m + 1];

		for (int i = 1; i <= m; i++) {
			u[i] = in.nextInt();
			v[i] = in.nextInt();
			int c = in.nextInt();
			g[u[i]].add(i);
			g[u[i]].add(v[i]);
			g[u[i]].add(c);
			g[v[i]].add(i);
			g[v[i]].add(u[i]);
			g[v[i]].add(c);
			flow[u[i]] += c;
			flow[v[i]] += c;
		}

		for (int i = 1; i <= n; i++)
			flow[i] /= 2;
		flow[1] = flow[n] = 0;

		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(1);
		boolean done[] = new boolean[n + 1];
		done[1] = true;

		while (!q.isEmpty()) {
			int curr = q.remove();
			for (int i = 0; i < g[curr].size();) {
				int edge = g[curr].get(i++);
				int next = g[curr].get(i++);
				int c = g[curr].get(i++);
				if(done[next])
					continue;
				ans[edge] = u[edge] == curr ? 0 : 1;
				flow[next] -= c;
				if (flow[next] == 0){
					q.add(next);
					done[next] = true;
				}
			}
		}

		for (int i = 1; i <= m; i++)
			w.println(ans[i]);

		w.close();
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;

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
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

	}
}
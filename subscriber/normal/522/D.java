import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Fenwick {
		int[] min;
		int n;

		public Fenwick(int n) {
			this.n = n;
			min = new int[n];
			Arrays.fill(min, Integer.MAX_VALUE);
		}

		int get(int r) {
			int res = Integer.MAX_VALUE;
			for (; r >= 0; r = (r & (r + 1)) - 1) {
				res = Math.min(res, min[r]);
			}
			return res;
		}

		void set(int r, int val) {
			for (; r < n; r = r | (r + 1)) {
				min[r] = Math.min(min[r], val);
			}
		}
	}

	class Q implements Comparable<Q> {
		int fr, to, id;

		public Q(int fr, int to, int id) {
			super();
			this.fr = fr;
			this.to = to;
			this.id = id;
		}

		@Override
		public int compareTo(Q o) {
			return -Integer.compare(fr, o.fr);
		}

	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		Q[] q = new Q[m];
		for (int i = 0; i < m; i++) {
			q[i] = new Q(in.nextInt() - 1, in.nextInt() - 1, i);
		}
		Arrays.sort(q);
		int[] ans = new int[m];
		Fenwick f = new Fenwick(n);
		int cur = n;
		HashMap<Integer, Integer> lastPos = new HashMap<>();
		for (Q qq : q) {
			while (cur != qq.fr) {
				cur--;
				int val = a[cur];
				Integer prev = lastPos.get(val);
				if (prev != null) {
					f.set(prev, prev - cur);
				}
				lastPos.put(val, cur);
			}
			ans[qq.id] = f.get(qq.to);
		}
		for (int res : ans) {
			out.println(res == Integer.MAX_VALUE ? -1 : res);
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}
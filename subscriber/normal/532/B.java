import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] g;
	int[] a;
	long[][] dp;

	void go(int v, int par) {
		for (int to : g[v]) {
			if (to != par) {
				go(to, v);
			}
		}
		dp[1][v] = Long.MIN_VALUE / 3;
		for (int to : g[v]) {
			if (to != par) {
				long ndp0 = Math
						.max(dp[0][v] + dp[0][to], dp[1][v] + dp[1][to]);
				long ndp1 = Math
						.max(dp[0][v] + dp[1][to], dp[1][v] + dp[0][to]);
				dp[0][v] = ndp0;
				dp[1][v] = ndp1;
			}
		}
		dp[1][v] = Math.max(dp[1][v], dp[0][v] + a[v]);
	}

	void solve() {
		int n = in.nextInt();
		a = new int[n];
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; i++) {
			int par = in.nextInt();
			a[i] = in.nextInt();
			if (par != -1) {
				g[par - 1].add(i);
			}
		}
		dp = new long[2][n];
		go(0, -1);
		out.println(Math.max(dp[0][0], dp[1][0]));
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
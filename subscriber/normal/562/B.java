import java.io.*;
import java.util.*;

public class B {

	private void solve() {
		final int MAX = (int) 1e6 + 10;
		int[] cnt = new int[MAX];
		int[] dp = new int[MAX];
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			cnt[in.nextInt()]++;
		}
		int res = 0;
		for (int i = MAX - 1; i > 0; i--) {
			dp[i] = cnt[i];
			for (int j = i + i; j < MAX; j += i) {
				dp[i] = Math.max(dp[i], cnt[i] + dp[j]);
			}
			res = Math.max(res, dp[i]);
		}
		out.println(res);
	}

	class FastScanner {
		StringTokenizer st;
		BufferedReader br;

		FastScanner(String file) {
			try {
				br = new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return null;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					return null;
				}
			}
			return st.nextToken();
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return false;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					return false;
				}
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

	FastScanner in;
	PrintWriter out;

	void runFile() {
		in = new FastScanner("a.in");
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	public static void main(String[] args) {
		new B().run();
	}
}
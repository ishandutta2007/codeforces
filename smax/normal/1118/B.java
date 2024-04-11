
import java.util.*;
import java.io.*;

public class B {

	static final boolean stdin = true;
	static final String filename = "";
	static FastScanner br;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {

		if (stdin) {
			br = new FastScanner();
			pw = new PrintWriter(new OutputStreamWriter(System.out));
		} else {
			br = new FastScanner(filename + ".in");
			pw = new PrintWriter(new FileWriter(filename + ".out"));
		}

		Solver solver = new Solver();
		solver.solve(br, pw);
		pw.close();
	}

	static class Solver {
		static long mod = (long) (1e9);

		public void solve(FastScanner br, PrintWriter pw) throws IOException {
			int n = br.ni();
			int[] in = br.nia(n);
			int[][] a = new int[n][2];
			int evenbef = 0, oddbef = 0, evenaf = 0, oddaf = 0;
			for (int i = 0; i < n; i++) {
				// a[i][0] even pos before + odd pos after
				// a[i][1] odd pos before + even pos after
				a[i][0] = evenbef;
				a[i][1] = oddbef;
				if (i % 2 == 0) {
					evenbef += in[i];
				} else {
					oddbef += in[i];
				}
			}
			for (int i = n - 1; i > -1; i--) {
				a[i][0] += oddaf;
				a[i][1] += evenaf;
				if (i % 2 == 0) {
					evenaf += in[i];
				} else {
					oddaf += in[i];
				}
			}
			int out = 0;
			for(int i = 0; i < n; i++) {
				if(a[i][0] == a[i][1]) {
					out++;
				}
			}
			pw.println(out);
		}

		static long gcd(long a, long b) {
			if (a > b)
				return gcd(b, a);
			if (a == 0)
				return b;
			return gcd(b % a, a);
		}

		static long lcm(long a, long b) {
			return a * (b / gcd(a, b));
		}

		static long pow(long a, long b) {
			if (b == 0)
				return 1L;
			long val = pow(a, b / 2);
			if (b % 2 == 0)
				return val * val % mod;
			else
				return val * val % mod * a % mod;
		}

	}

	static class Point implements Comparable<Point> {
		int a;
		int b;

		Point(int a, int b) {
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(Point o) {
			return this.a - o.a;
		}

		public boolean equals(Object obj) {
			if (obj instanceof Point) {
				Point other = (Point) obj;
				return a == other.a && b == other.b;
			}
			return false;
		}

		public int hashCode() {
			return 65536 * a + b + 4733 * 0;
		}

	}

	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		ArrayList<Integer>[] ng(int n, int e) {
			ArrayList<Integer>[] adj = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new ArrayList<Integer>();
			}
			for (int i = 0; i < e; i++) {
				int a = ni() - 1;
				int b = ni() - 1;
				adj[a].add(b);
				adj[b].add(a);
			}
			return adj;
		}

		Integer[] nIa(int n) {
			Integer[] arr = new Integer[n];
			for (int i = 0; i < n; i++) {
				arr[i] = ni();
			}
			return arr;
		}

		int[] nia(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = ni();
			}
			return arr;
		}

		Long[] nLa(int n) {
			Long[] arr = new Long[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nl();
			}
			return arr;
		}

		long[] nla(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nl();
			}
			return arr;
		}

		String[] nsa(int n) {
			String[] arr = new String[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nt();
			}
			return arr;
		}

		String nt() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int ni() {
			return Integer.parseInt(nt());
		}

		long nl() {
			return Long.parseLong(nt());
		}

		double nd() {
			return Double.parseDouble(nt());
		}

	}
}
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] w = new int[n];
		int[] h = new int[n];
		for (int i = 0; i < n; i++) {
			w[i] = in.nextInt();
			h[i] = in.nextInt();
		}
		int m1 = 0;
		for (int i = 0; i < n; i++) {
			if (h[i] > h[m1]) {
				m1 = i;
			}
		}
		int m2 = 0;
		if (m1 == m2) {
			m2 = 1;
		}
		for (int i = 0; i < n; i++) {
			if (i != m1 && h[i] > h[m2]) {
				m2 = i;
			}
		}
		long sumW = 0;
		for (int i = 0; i < n; i++) {
			sumW += w[i];
		}
		for (int i = 0; i < n; i++) {
			long ww = sumW - w[i];
			long hh = h[m1];
			if (m1 == i) {
				hh = h[m2];
			}
			out.print(ww * hh + " ");
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
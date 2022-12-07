import java.io.*;
import java.util.*;

public class A1 {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) a[i] = in.nextInt();
		int[] h = new int [101];
		Arrays.fill(h, 0);
		for (int i = 0; i < n; i++) h[a[i]]++;
		for (int i = 99; i >= 0; i--) h[i] += h[i + 1];
		Arrays.fill(a, 0);
		for (int i = 0; i < 101; i++) for (int j = 0; j < h[i]; j++) a[n - 1 - j] = i;
		for (int i = 0; i < n - 1; i++) out.print(a[i] + " ");
		out.println(a[n - 1]);
		
	}

	void run() {
		try {
			in = new FastScanner(new File("1.in"));
			out = new PrintWriter(new File("1.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
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
		new A1().runIO();
	}
}
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int get(HashMap<String, ArrayList<String>> hm, String from) {
		ArrayList<String> xx = hm.get(from);
		int res = 1;
		if (xx != null) {
			for (String s : xx) {
				res = Math.max(res, get(hm, s) + 1);
			}
		}
		return res;
	}

	void solve() {
		String first = "polycarp";
		HashMap<String, ArrayList<String>> hm = new HashMap<>();
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			String to = in.next().toLowerCase();
			in.next();
			String from = in.next().toLowerCase();
			ArrayList<String> zz = hm.get(from);
			if (zz == null) {
				zz = new ArrayList<>();
			}
			zz.add(to);
			hm.put(from, zz);
		}
		out.println(get(hm, first));
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
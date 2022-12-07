import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
	    int kitten = 0;
	    int n = in.nextInt();
	    int m = in.nextInt();
	    int t = in.nextInt();
	int[] a = new int[m];
	for (int i = 0; i < n; i++) {
	    String s = in.next();
		for (int j = 0; j < m; j++) if (s.charAt(j) == 'Y') a[j]++;
	}
	int ans = 0;
	for (int i = 0; i < m; i++) if (a[i] >= t) ans++;
	out.println(ans);
	
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

	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}
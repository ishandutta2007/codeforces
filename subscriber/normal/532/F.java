import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	final int mul = 239;
	final int MAX = (int) 1e5 * 4;
	int[] pow = new int[MAX];
	Random rnd = new Random();
	int mod = BigInteger.valueOf((int) 1e9 + rnd.nextInt((int) 1e5))
			.nextProbablePrime().intValue();

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		char[] s = in.next().toCharArray();
		char[] t = in.next().toCharArray();
		pow[0] = 1;
		for (int i = 1; i < pow.length; i++) {
			pow[i] = (int) (pow[i - 1] * 1L * mul % mod);
		}
		int[][] hashes = new int[26][s.length + 1];
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < s.length; j++) {
				hashes[i][j + 1] = (int) ((hashes[i][j] * 1L * mul + ((s[j] - 'a') == i ? 1
						: 0)) % mod);
			}
		}
		int realHash = 0;
		for (int i = 0; i < t.length; i++) {
			realHash = (int) ((realHash * 1L * mul + t[i] - 'a') % mod);
		}
		boolean[] can = new boolean[n - m + 1];
		int[] lastPos = new int[26];
		Arrays.fill(lastPos, -1);
		int[] change = new int[26];
		int powMul = pow[t.length];
		for (int from = n - 1; from >= 0; from--) {
			lastPos[s[from] - 'a'] = from;
			if (from + m - 1 >= n) {
				continue;
			}
			Arrays.fill(change, -1);
			for (int i = 0; i < 26; i++) {
				int pos = lastPos[i];
				if (pos == -1 || pos >= from + m) {

				} else {
					change[i] = t[pos - from] - 'a';
				}
			}
			boolean ok = true;
			for (int i = 0; i < 26; i++) {
				if (change[i] != -1) {
					if (change[change[i]] == -1) {
						change[change[i]] = i;
					} else {
						if (change[change[i]] != i) {
							ok = false;
							break;
						}
					}
				}
			}
			if (ok) {
				long myHash = 0;
				for (int i = 0; i < 26; i++) {
					long curHash = (hashes[i][from + m] - hashes[i][from] * 1L
							* powMul)
							% mod;
					myHash += curHash * change[i];
				}
				myHash %= mod;
				if (myHash < 0) {
					myHash += mod;
				}
				if (myHash == realHash) {
					can[from] = true;
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < can.length; i++) {
			cnt += can[i] ? 1 : 0;
		}
		out.println(cnt);
		for (int i = 0; i < can.length; i++) {
			if (can[i]) {
				out.print((i + 1) + " ");
			}
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
import java.io.*;
import java.util.*;

public class A {
	FastScanner in;
	PrintWriter out;

	final int mod = (int) 1e9 + 7;
	final int mul = 239;
	int[] hash;
	int[] pow;

	int getHash(int from, int to) {
		long res = hash[to + 1] - hash[from] * 1L * pow[to - from + 1];
		res %= mod;
		if (res < 0) {
			res += mod;
		}
		return (int) res;
	}

	boolean less(int fr1, int fr2, int n) {
		int l = 0, r = n + 1;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (getHash(fr1, fr1 + m - 1) == getHash(fr2, fr2 + m - 1)) {
				l = m;
			} else {
				r = m;
			}
		}
		if (l == n) {
			return false;
		}
		return s.charAt(fr1 + l) < s.charAt(fr2 + l);
	}

	String s;

	void solve() {
		s = in.next();
		int n = s.length();
		s = s + s;
		hash = new int[s.length() + 1];
		for (int i = 0; i < s.length(); i++) {
			hash[i + 1] = (int) ((hash[i] * 1L * mul + s.charAt(i)) % mod);
		}
		pow = new int[n + n + 2];
		pow[0] = 1;
		for (int i = 1; i < pow.length; i++) {
			pow[i] = (int) ((pow[i - 1] * 1L * mul) % mod);
		}
		int[] bal = new int[n + n - 1];
		for (int i = 0; i < n + n - 1; i++) {
			if (s.charAt(i) == '(') {
				bal[i]++;
			} else {
				bal[i]--;
			}
			if (i > 0) {
				bal[i] += bal[i - 1];
			}
		}
		int cur = s.length() - 1;
		int[] balanceChange = new int[n];
		int[] qPos = new int[n + n];
		int[] qValue = new int[n + n];
		int qSz = 0, qFrom = 0;
		for (int pos = n - 1; pos >= 0; pos--) {
			while (cur != pos) {
				cur--;
				int value = bal[cur];
				while (qSz > qFrom && qValue[qSz - 1] >= value) {
					qSz--;
				}
				qValue[qSz] = value;
				qPos[qSz] = cur;
qSz++;
			}
			while (qPos[qFrom] >= pos + n) {
				qFrom++;
			}
			int prevBalance = pos > 0 ? bal[pos - 1] : 0;
			balanceChange[pos] = qValue[qFrom] - prevBalance;
		}
		int cntOpen = 0;
		for (int i = 0; i < n; i++) {
			if (s.charAt(i) == '(') {
				cntOpen++;
			} else {
				cntOpen--;
			}
		}
		int maxBalanceChange = 0;
		if (cntOpen < 0) {
			maxBalanceChange = cntOpen;
		}
		int bestCandidate = -1;
		for (int i = 0; i < n; i++) {
			if (balanceChange[i] >= maxBalanceChange) {
				if (bestCandidate != -1) {
					if (!less(i, bestCandidate, n)) {
						continue;
					}
				}
				bestCandidate = i;
			}
		}
		if (bestCandidate < 0) {
			throw new AssertionError();
		}
		for (int i = 0; i < -cntOpen; i++) {
			out.print("(");
		}
		for (int i = 0; i < n; i++) {
			out.print(s.charAt(i + bestCandidate));
		}
		for (int i = 0; i < cntOpen; i++) {
			out.print(")");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("A.in"));
			out = new PrintWriter(new File("A.out"));

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
		new A().runIO();
	}
}
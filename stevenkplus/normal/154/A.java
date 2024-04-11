import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {
	static String next() {
		if (st == null || !st.hasMoreTokens())
			nextLine();
		return st.nextToken();
	}

	static int nextInt() {
		return Integer.parseInt(next());
	}

	static void nextLine() {
		try {
			st = new StringTokenizer(f.readLine());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static StringTokenizer st;
	static PrintWriter out;
	static BufferedReader f;
	static int[][] dp;
	static String str;
	static String[] forbidden;

	public static void main(String[] args) throws IOException {
		String progName = (A.class.getCanonicalName());

		try {
			f = new BufferedReader(new FileReader(progName + ".in"));
			out = new PrintWriter(new BufferedWriter(new FileWriter(progName
					+ ".out")));

		} catch (FileNotFoundException e) {
			f = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		}
		forbidden = new String[26];
		Arrays.fill(forbidden, "");
		str = next();
		int k = nextInt();
		for (int x = 0; x < k; x++) {
			String next = next();
			char a = next.charAt(0), b = next.charAt(1);
			forbidden[a - 'a'] += b;
			forbidden[b - 'a'] += a;
		}
		dp = new int[str.length()][26];
		for (int[] d : dp)
			Arrays.fill(d, -1);
		out.println(min(0, -1));
		out.close();
		// System.exit(0);
	}

	static int min(int start, int prev) {
		if (start >= str.length())
			return 0;
		if (prev != -1 && dp[start][prev] != -1)
			return dp[start][prev];
		String a = str.substring(start, start + 1);
		if (prev != -1 && forbidden[prev].contains(a)) {
			return 1 + min(start + 1, prev);
		}
		int b = 1 + min(start + 1, prev);
		int o = min(start + 1, a.charAt(0) - 'a');
		if (prev != -1)
			return dp[start][prev] = (o < b ? o : b);
		else
			return (o < b ? o : b);

	}
}
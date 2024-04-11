import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		solver.solve(in, out);
		out.close();
	}
}

class Solver {
	static final int MOD = 1000000007;
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		long[][] dp = new long[n + 1][n + 1];
		dp[0][0] = 1;
		dp[0][1] = 0;
		for (int j = 0; j < n + 1; j++) {
			for (int i = 0; i < n + 1; i++) {
				if (i == 0 && j == 0)
					continue;
				if (i > 0) {
					if (j > 0)
						dp[i][j] = (dp[i - 1][j] * i + dp[i][j - 1] * j) % MOD;
					else 
						dp[i][j] = dp[i - 1][j] * i % MOD;
				} else {
					if (j >= 2)
						dp[i][j] = dp[i + 1][j - 2] * (j - 1) % MOD;
				}
			}
		}
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == -1)
				cnt1++;
			else
				if (a[a[i] - 1] == -1)
					cnt2++;
		}
		out.println(dp[cnt2][cnt1 - cnt2]);
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
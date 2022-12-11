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
	long res = 0;
	boolean[] used;
	int[] a;
	/*
	void rec(int st, int n, int cur, int prev) {
		if (st == n) {
			res += cur;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				used[i] = true;
				rec(st + 1, n, cur + Math.abs(prev - a[i]), a[i]);
				used[i] = false;
			}
		}
	}
	long fact(int n) {
		if (n <= 1)
			return 1;
		return n * fact(n - 1);
	}*/
	public void solve(InputReader in, PrintWriter out) {
		int n  = in.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		Arrays.sort(a);
		//used = new boolean[n];
		//rec(0, n, 0, 0);
		//long f = fact(n);
		//int gcd = Integer.parseInt(BigInteger.valueOf(res).gcd(BigInteger.valueOf(f)).toString());
		//f /= gcd;
		//res /= gcd;
		//out.format("%d %d\n", res, f);
		long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += a[i];
		}
		long[] dp = new long[n];
		for (int i = 1; i < n; i++) {
			dp[i] = dp[i - 1] + ((long)(a[i] - a[i - 1])) * i; 
			ans += dp[i] * 2;
		}
		int gcd = Integer.parseInt(BigInteger.valueOf(ans).gcd(BigInteger.valueOf(n)).toString());
		ans /= gcd;
		n /= gcd;
		out.format("%d %d\n", ans, n);
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
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
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		long[] a = new long[n + 1];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextLong();
		}
		a[n] = a[n - 1];
		n++;
		long ans = 0;
		long[] dp = new long[n];
		for (int i = 1; i < n - 1; i++) {
			/*
			if (i == n - 1) {
				ans += Math.abs(a[i] - extr);
				continue;
			}*/
			if ((a[i] - a[i - 1]) * (a[i + 1] - a[i]) >= 0) {
				dp[i] = Math.max(dp[i], dp[i - 1] + Math.abs(a[i] - a[i - 1]));
				continue;
			}
			dp[i + 1] = Math.max(dp[i + 1], dp[i - 1] + Math.abs(a[i] - a[i - 1]));
			dp[i] = Math.max(dp[i], dp[i - 1]);
			/*
			if (Math.abs(a[i] - a[i - 1]) > Math.abs(a[i + 1] - a[i])) {
				ans += Math.abs(a[i] - extr);
				extr = a[i + 1];
				i++;
			} else {
				ans += Math.abs(a[i - 1] - extr);
				extr = a[i];
			}*/
		}
	/*	
		for (int i = 0; i < n; i++) {
			out.print(dp[i]);
			out.print(" ");
		}
		out.println();*/
		out.println(dp[n - 2]);
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
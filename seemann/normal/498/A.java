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
	int sign(long x) {
		if (x > 0)
			return 1;
		if (x < 0)
			return -1;
		return 0;
	}
	public void solve(InputReader in, PrintWriter out) {
		long x1 = in.nextInt();
		long y1 = in.nextInt();
		long x2 = in.nextInt();
		long y2 = in.nextInt();
		int ans = 0;
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			long a = in.nextInt();
			long b = in.nextInt();
			long c = in.nextInt();
			if (sign(a * x1 + b * y1 + c) != sign(a * x2 + b * y2 + c))
				ans++;
		}
		out.println(ans);
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
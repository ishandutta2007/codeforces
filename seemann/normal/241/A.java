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
		int k = in.nextInt();
		int[] s = new int[n];
		int[] d = new int[n];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			d[i] = in.nextInt();
			ans += d[i];
		}
		for (int i = 0; i < n; i++) {
			s[i] = in.nextInt();
		}
		int[] b = new int[n + 1];
		b[0] = 0;
		for (int i = 1; i < n + 1; i++) {
			b[i] = b[i - 1] + s[i - 1] - d[i - 1];
		}
		int mxs = 0;
		int add = 0;
		for (int i = 0; i < n + 1; i++) {
			if (b[i] + add < 0) {
				int rem = 0 - (b[i] + add);
				int c = ((rem + mxs - 1) / mxs);
				//System.err.println(mxs);
				//System.err.println(c);
				add += c * mxs;
				ans += k * c;
			}
			if (i < n)
				mxs = Math.max(mxs, s[i]);
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
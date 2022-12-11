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
		int x = in.nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		x--;
		long sum = 0;
		long min = 1000000001;
		for (int i = 0; i < n; i++) {
			min = Math.min(min, a[i]);
		}
		for(int i = x;;i = ((i == 0)?(n - 1):(i - 1))) {
			if (a[i] == min) {
				long t = a[i];
				for (int j = 0; j < n; j++) {
					a[j] -= t;
				}
				a[i] = t * n + sum;
				for (int j = 0; j < n; j++) {
					out.print(a[j]);
					out.print(' ');
				}
				return;
			}
			sum++;
			a[i]--;
			min = Math.min(a[i], min);
		}
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
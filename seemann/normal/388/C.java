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
		ArrayList<Integer> mid = new ArrayList<Integer>();
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < n; i++) {
			int s = in.nextInt();
			for (int j = 0; j < s / 2; j++) {
				int c = in.nextInt();
				sum1 += c;
			}
			if (s % 2 == 1) {
				int c = in.nextInt();
				mid.add(c);
			}
			for (int j = 0; j < s / 2; j++) {
				int c = in.nextInt();
				sum2 += c;
			}
		}
		Collections.sort(mid);
		for (int i = mid.size() - 1; i >= 0; --i) {
			if (i % 2 != mid.size() % 2)
				sum1 += mid.get(i);
			else {
				sum2 += mid.get(i);
			}
		}
		out.format("%d %d\n", sum1, sum2);
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
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
		int m = in.nextInt();
		char[][] t = new char[n][m];
		for (int i = 0; i < n; i++) {
			String s = in.next();
			for (int j = 0; j < m; j++) {
				t[i][j] = s.charAt(j);
			}
		}
		boolean[] less = new boolean[n];
		int ans = 0;
		for (int j = 0; j < m; j++) {
			boolean good = true;
			for (int i = 0; i < n - 1; i++) {
				if (less[i])
					continue;
				if (t[i][j] > t[i + 1][j])
					good = false;
			}
			if (!good) {
				ans++;
				continue;
			}
			for (int i = 0; i < n - 1; i++) {
				if (less[i])
					continue;
				if (t[i][j] < t[i + 1][j])
					less[i] = true;
			}
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
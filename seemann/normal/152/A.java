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
		int n, m;
		n = in.nextInt();
		m = in.nextInt();
		int[][] a = new int[100][100];
		for (int i = 0; i < n; i++) {
			String s = in.next();
			for (int j = 0; j < m; j++) {
				a[i][j] = s.charAt(j) - '0';
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			boolean ind = false;
			for (int j = 0; j < m; j++) {
				boolean ind1 = true;
				for (int j2 = 0; j2 < n; j2++) {
					if (a[j2][j] > a[i][j])
						ind1 = false;
				}
				if (ind1)
					ind = true;
			}
			if (ind)
				ans++;
		}
		out.print(ans);
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
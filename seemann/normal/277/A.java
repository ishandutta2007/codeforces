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
	int[][] a;
	boolean[] use;
	int n, m;
	private void dfs(int v) {
		use[v] = true;
		for (int i = 0; i < n; i++) {
			if (use[i])
				continue;
			boolean ind = false;
			for (int j = 0; j < m; j++) {
				if (a[i][j] != 0 && a[v][j] != 0)
					ind = true;
			}
			if (ind)
				dfs(i);
		}
	}
	public void solve(InputReader in, PrintWriter out) {
		n = in.nextInt();
		m = in.nextInt();
		a = new int[n][m];
		boolean ind = false;
		for (int i = 0; i < n; i++) {
			int k = in.nextInt();
			if (k > 0)
				ind = true;
			for (int j = 0; j < k; j++) {
				int w = in.nextInt();
				w--;
				a[i][w] = 1;
				
			}
		}
		use = new boolean[n];
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (!use[i]) {
				dfs(i);
				c++;
			}
				
		}
		if (!ind)
			c++;
		out.println(c - 1);
		
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
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
	int MAXN = 2000;
	int[][] g;
	void add(int st, int en) {
		g[st][en] = 1;
		g[en][st] = 1;
	}
	int fr = 1;
	int gen(int st, int en, int k) {
		if (k == 1) {
			add(st, en);
			return 1;
		}
		if (k % 2 == 0) {
			int nst = ++fr;
			int res = gen(nst, en, k / 2);
			add(st, ++fr);
			add(fr, nst);
			add(st, ++fr);
			add(fr, nst);
			return res + 2;
		} else {
			int res = gen(st, en, k - 1);
			int cur = st;
			for (int i = 0; i < res - 1; i++) {
				add(cur, ++fr);
				cur = fr;
				//add(fr, en);
			}
			add(cur, en);
			return res;
		}
	}
	public void solve(InputReader in, PrintWriter out) {
		int k = in.nextInt();
		g = new int[MAXN][MAXN];
		
		gen(0, 1, k);
		int n = fr + 1;
		out.println(n);
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][j] == 0)
					out.print('N');
				else
					out.print('Y');
			}
			out.println();
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
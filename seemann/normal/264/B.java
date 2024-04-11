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
	int[] p;
	int[] np;
	int cp = 0;
	static final int MAXA = 100000;

	public void solve(InputReader in, PrintWriter out) {
		p = new int[10000];
		np = new int[MAXA + 1];
		for (int i = 2; i <= MAXA; i++) {
			boolean ind = true;
			for (int j = 0; j < cp; j++) {
				if (i % p[j] == 0) {
					ind = false;
					break;
				}
			}
			if (ind) {
				np[i] = cp;
				p[cp++] = i;
			}
		}
		int [] prev = new int[cp];
		
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		int[] l = new int[n];
		
		for (int i = n - 1; i >= 0; i--) {
			l[i] = 1;
			ArrayList<Integer> d = new ArrayList<Integer>();
			int w = a[i];
			for (int j = 0; j < cp && p[j] * p[j] <= w; j++) {
				if (w % p[j] == 0) {
					d.add(p[j]);
					while (w % p[j] == 0) {
						w /= p[j];
					}
				}
			}
			if (w > 1) {
				d.add(w);
			}
			for (int j = 0; j < d.size(); j++) {
				int cur = np[d.get(j)];
				int pr = prev[cur];
				if (pr != 0) {
					l[i] = Math.max(l[i], 1 + l[pr]);
				}
				prev[cur] = i;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = Math.max(ans, l[i]);
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
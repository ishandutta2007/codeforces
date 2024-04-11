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
		int[] c = new int[n];
		int[][] a = new int[n][];
		int[][] b = new int[n][];
		int s = 0;
		
		for (int i = 0; i < n; i++) {
			c[i] = in.nextInt();
			a[i] = new int[c[i]];
			b[i] = new int[c[i]];
			s += c[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < c[i]; j++) {
				a[i][j] = in.nextInt();
			}
		}
		
		int[] st = new int[s];
		int ct = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < c[i]; j++) {
				st[ct++] = a[i][j];
			}
		}
		Arrays.sort(st);
		ct = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < c[i]; j++) {
				b[i][j] = st[ct++];
			}
		}
		int[][] ans = new int[s][4];
		int ca = 0;
		for (int i = 0; i < n; i++) {
			start:
			for (int j = 0; j < c[i]; j++) {
				if (a[i][j] == b[i][j])
					continue;
				for (int j2 = i; j2 < n; j2++) {
					for (int k = 0; k < c[j2]; k++) {
						if (j2 == i && k <= j) {
							continue;
						}
						if (a[j2][k] == b[i][j]) {
							a[j2][k] = a[i][j];
							a[i][j] = b[i][j];
							ans[ca][0] = i + 1;
							ans[ca][1] = j + 1;
							ans[ca][2] = j2 + 1;
							ans[ca][3] = k + 1;
							ca++;
							continue start;
						}
					}
				}
			}
		}
		out.println(ca);
		for (int i = 0; i < ca; i++) {
			out.format("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
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
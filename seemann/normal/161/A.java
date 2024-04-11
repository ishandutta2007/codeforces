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
		int x = in.nextInt();
		int y = in.nextInt();
		int[] a = new int[n];
		int[] b = new int[m];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		for (int i = 0; i < m; i++) {
			b[i] = in.nextInt();
		}
		int ca = 0;
		int[] u = new int[n];
		int[] v = new int[n];
		int p1 = 0;
		int p2 = 0;
		while (p1 < n && p2 < m) {
			if (b[p2] < a[p1] - x) {
				p2++;
				continue;
			}
			if (b[p2] > a[p1] + y) {
				p1++;
				continue;
			}
			u[ca] = p1 + 1;
			v[ca++] = p2 + 1;
			p1++;
			p2++;
		}
		out.println(ca);
		for (int i = 0; i < ca; i++) {
			out.print(u[i]);
			out.print(' ');
			out.println(v[i]);
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
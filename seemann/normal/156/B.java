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
		int[] a = new int[n];
		int[] p = new int[n];
		int[] e = new int[n];
		boolean[] c = new boolean[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			if (a[i] > 0) {
				p[a[i] - 1]++;
			} else {
				e[-a[i] - 1]++;
			}
		}
		int sp = 0;
		int se = 0;
		for (int i = 0; i < n; i++) {
			sp += p[i];
			se += e[i];
		}
		int num = 0;
		for (int i = 0; i < n; i++) {
			if (se - e[i] + p[i] == m) {
				num++;
				c[i] = true;
			}
		}
		for (int i = 0; i < n; i++) {
			int wa = Math.abs(a[i]) - 1;
			if (num == 1 && c[wa]) {
				if (a[i] > 0) {
					out.print("Truth\n");
				} else {
					out.print("Lie\n");
				}
			}
			if (num > 1 && c[wa]) {
				out.print("Not defined\n");
			}
			if (!c[wa]) {
				if (a[i] > 0) {
					out.print("Lie\n");
				} else {
					out.print("Truth\n");
				}
			}
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
		String s = next();
		if (s.charAt(0) == '+') {
			s = s.substring(1);
		}
		return Integer.parseInt(s);
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
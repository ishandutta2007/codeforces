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
	int[] apply(int[] a, int[] p) {
		int[] b = new int[a.length];
		for (int i = 0; i < a.length; i++) {
			b[i] = a[p[i]];
		}
		return b;
	}
	int[] apply1(int[] a, int[] p) {
		int[] b = new int[a.length];
		for (int i = 0; i < a.length; i++) {
			b[p[i]] = a[i];
		}
		return b;
	}
	int[] cycleShift(int n, int k) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = (i + k) % n;
		}
		return a;
	}
	int[] dSort(int n, int k, int d) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = i;
		}
		int c = 0;
		for (int i = 0; i < d; i++) {
			for (int j = i; j < k; j += d) {
				a[j] = c++;
			}
		}
		return a;
	}
	int[] power(int[] p, int pow) {
		if (pow == 1)
			return p;
		if (pow % 2 == 0) {
			int[] t = power(p, pow / 2);
			return apply(t, t);
		} else {
			return apply(power(p, pow - 1), p);
		}
	}
	public void solve(InputReader in, PrintWriter out) {
		String str = in.next();
		int n = str.length();
		int[] s = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = str.charAt(i);
		}
		int m = in.nextInt();
		int[] shift = cycleShift(n, n - 1);
		
		
		for (int i = 0; i < m; i++) {
			int k = in.nextInt();
			int d = in.nextInt();
			int[] dSort = dSort(n, k, d);
			
			int[] perm = power(apply(shift, dSort), n - k + 1);
			perm = apply(cycleShift(n, n - k + 1), perm);
			s = apply1(s, perm);
			for (int j = 0; j < n; j++) {
				out.print((char)s[j]);
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
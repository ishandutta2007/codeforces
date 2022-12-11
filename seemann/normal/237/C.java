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
		int a = in.nextInt();
		int b = in.nextInt();
		int k = in.nextInt();
		boolean[] np = new boolean[b + 2];
		np[0] = true;
		np[1] = true;
		for (int i = 2; i <= b; ++i) {
			if (np[i])
				continue;
			for (int j = 2 * i; j <= b; j += i) {
				np[j] = true;
			}
		}
		int l = 0;
		int r = b - a + 1;
		while (l < r - 1) {
			int m = (l + r) / 2;
			int cp = 0;
			for (int i = a; i < a + m; ++i){
				if (!np[i])
					cp++;
			}
			boolean ind = true;
			for (int i = a; i < b - m + 2; ++i) {
				if (cp < k) {
					ind = false;
					break;
				}
				if (!np[i]) {
					cp--;
				}
				if (i + m <= b && !np[i + m]) {
					cp++;
				}
			}
			if (ind) {
				r = m;
			} else
				l = m;
		}
		int cp = 0;
		for (int i = a; i < a + r; ++i){
			if (!np[i])
				cp++;
		}
		boolean ind = true;
		for (int i = a; i < b - r + 2; ++i) {
			if (cp < k) {
				ind = false;
				break;
			}
			if (!np[i]) {
				cp--;
			}
			if (i + r <= b && !np[i + r]) {
				cp++;
			}
		}
		if (!ind) {
			out.println(-1);
		} else {
			out.println(r);
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
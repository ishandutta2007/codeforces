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
		int x, y;
		x = in.nextInt();
		y = in.nextInt();
		int k = in.nextInt();
		long ans = 0;
		for (int i = 0; i < k; i++) {
			int vx, vy;
			vx = in.nextInt();
			vy = in.nextInt();
			int c1, c2;
			if (vx == 0) {
				c1 = n + m + 1;
			} else {
				if (vx > 0) {
					c1 = (n - x) / vx;
				} else {
					c1 = (x - 1) / -vx;
				}
			}
			if (vy == 0) {
				c2 = n + m + 1;
			} else {
				if (vy > 0) {
					c2 = (m - y) / vy;
				} else {
					c2 = (y - 1) / -vy;
				}
			}
			int c = Math.min(c1, c2);
			ans += c;
			x += vx * c;
			y += vy * c;
			//System.err.println(x);
			//System.err.println(y);
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
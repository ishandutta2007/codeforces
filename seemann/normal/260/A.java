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
		int n = in.nextInt();
		StringBuffer ans = new StringBuffer(Integer.toString(a));
		int cur = a % b;
		for (int i = 0; i < n; i++) {
			cur = cur * 10 % b;
			boolean ind = false;
			for(int j = 0; j < 10; ++j) {
				if ((cur + j) % b == 0) {
					ans.append((char)('0' + j));
					cur = 0;
					ind = true;
					break;
				}
			}
			if(!ind) {
				out.println(-1);
				return;
			}
		}
		out.println(ans.toString());
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
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
		String s = in.next();
		String t = in.next();
		StringBuffer w = new StringBuffer();
		for (int i = 0; i < t.length(); i++) {
			w.append('A');
		}
		String ws = w.toString();
		s = ws.concat(s);
		s = s.concat(ws);
		int min = s.length() + 1;
		for (int i = 0; i < s.length() - t.length() + 1; i++) {
			int c = 0;
			for (int j = 0; j < t.length(); j++) {
				if (s.charAt(i + j) != t.charAt(j)) {
					c++;
				}
			}
			min = Math.min(min,  c);
		}
		out.print(min);
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
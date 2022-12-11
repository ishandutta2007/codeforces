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
		int k = in.nextInt();
		char[] p = new char[26];
		for (int i = 0; i < k; i++) {
			String ws = in.next();
			p[ws.charAt(0) - 'a'] = ws.charAt(1);
			p[ws.charAt(1) - 'a'] = ws.charAt(0);
		}
		int i = 0;
		int ans = 0;
		while (i < s.length()) {
			int j = i + 1;
			int c1 = 1;
			int c2 = 0;
			while (j < s.length() && (p[s.charAt(i) - 'a'] == s.charAt(j) || s.charAt(i) == s.charAt(j))) {
				if (s.charAt(i) == s.charAt(j)) {
					c1++;
				} else {
					c2++;
				}
				j++;
			}
			ans += Math.min(c1, c2);
			i = j;
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
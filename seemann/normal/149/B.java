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
		String ws = in.next();
		String[] s = ws.split(":");
		if (Integer.parseInt(s[0], 36) <= 23 && Integer.parseInt(s[1], 36) <= 35) {
			out.print(-1);
			return;
		}
		boolean ind = true;
		for (int i = 2; i <= 59; i++) {
			try {
				if (Integer.parseInt(s[0], i) <= 23 && Integer.parseInt(s[1], i) <= 59) {
					out.print(i);
					out.print(' ');
					ind = false;
				}
			} catch (NumberFormatException e) {
				continue;
			}
		}
		try {
			if ((Integer.parseInt(s[1], 36) - Integer.parseInt(s[1], 35) == 1)&&(Integer.parseInt(s[0], 36) <= 23)) {
				int last = Integer.parseInt(s[1], 36) - 36;
				for (int i = 37; i < 60 - last; i++) {
					out.print(i);
					out.print(' ');
					ind = false;
				}
			}
		} catch (NumberFormatException e) {
		}
		if (ind)
			out.print(0);
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
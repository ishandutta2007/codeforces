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
	public final long MOD = 1000000000+7;
	public void solve(InputReader in, PrintWriter out) {
		int n, m;
		n = in.nextInt();
		m = in.nextInt();
		String[] names = new String[n];
		for (int i = 0; i < n; i++) {
			names[i] = in.next();
		}
		long ans = 1;
		for (int i = 0; i < m; i++) {
			TreeSet<Short> use = new TreeSet<Short>(); 
			for (int j = 0; j < n; j++) {
				use.add((short)names[j].charAt(i));
			}
			ans *= use.size();
			ans %= MOD;
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
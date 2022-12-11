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
	Map<String, List<String>> g;
	int dfs(String v) {
		int mx = 0;
		for (String dest : g.get(v)) {
			mx = Math.max(mx, dfs(dest));
		}
		return mx + 1;
	}
	public void solve(InputReader in, PrintWriter out) {
		int m = in.nextInt();
		String st = "polycarp";
		g = new HashMap<>();
		for (int i = 0; i < m; i++) {
			String s, t;
			s = in.next().toLowerCase();
			t = in.next();
			t = in.next().toLowerCase();
			if (!g.containsKey(s))
				g.put(s, new ArrayList<String>());
			if (!g.containsKey(t))
				g.put(t, new ArrayList<String>());
			g.get(t).add(s);
		}
		out.println(dfs(st));
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
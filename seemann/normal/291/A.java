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
		TreeMap<Integer, Integer> use = new TreeMap<Integer, Integer>();
		
		for (int i = 0; i < n; i++) {
			int id = in.nextInt();
			if (id == 0)
				continue;
			if (!use.containsKey(id))
				use.put(id, 0);
			use.put(id, use.get(id) + 1);
		}
		int ans = 0;
		for (Integer i : use.values()) {
			if (i == 2)
				ans++;
			if (i >= 3) {
				ans = -1;
				break;
			}
		}
		out.println(ans);
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
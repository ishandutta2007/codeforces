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
	ArrayList<Integer>[] e;
	boolean[] use;
	void dfs(int v) {
		use[v] = true;
		for (int dest : e[v]) {
			if (!use[dest])
				dfs(dest);
		}
	}
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int m = in.nextInt();
		e = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			e[i] = new ArrayList<Integer>();
		}
		int[] st = new int[n];
		for (int i = 0; i < m; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			a--; b--;
			st[a]++;
			st[b]++;
			e[a].add(b);
			e[b].add(a);
		}
		use = new boolean[n];
		dfs(0);
		boolean con = true;
		for (int i = 0; i < n; i++) {
			if (!use[i] )
				con = false;
		}
		int[] c = new int[n];
		for (int i = 0; i < n; i++) {
			c[st[i]]++;
		}
		if (con && c[1] == n - 1 && c[n - 1] == 1) {
			out.println("star topology");
			return;
		}
		if (con && c[1] == 2 && c[2] == n - 2) {
			out.println("bus topology");
			return;
		}
		if (con && c[2] == n) {
			out.println("ring topology");
			return;
		}
		out.println("unknown topology");
		
			
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
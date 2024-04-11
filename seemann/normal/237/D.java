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
	int n;
	ArrayList<Integer>[] e;
	boolean use[];
	ArrayList<Integer>[] V;
	int cv = 0;
	int ce = 0;
	ArrayList<Integer>[] E;
	void dfs(int v, int lt) {
		use[v] = true;
		int l = lt;
		for (Integer v1 : e[v]) {
			if (use[v1])
				continue;
			V[cv].add(v);
			V[cv].add(v1);
			cv++;
			int nm = cv - 1;
			dfs(v1, nm);
			if (l != -1) {
				E[ce].add(l);
				E[ce].add(nm);
				ce++;
			}
			l = nm;
		}
	}
	public void solve(InputReader in, PrintWriter out) {
		n = in.nextInt();
		e = new ArrayList[n];
		V = new ArrayList[n];
		E = new ArrayList[n];
		use = new boolean[n];
		for (int i = 0; i < n; i++) {
			e[i] = new ArrayList<Integer>();
			V[i] = new ArrayList<Integer>();
			E[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n - 1; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			a--;
			b--;
			e[a].add(b);
			e[b].add(a);
		}
		dfs(0, -1);
		out.println(n - 1);
		for (int i = 0; i < n - 1; i++) {
			out.format("2 %d %d\n", V[i].get(0) + 1, V[i].get(1) + 1);
		}
		for (int i = 0; i < n - 2; i++) {
			out.format("%d %d\n", E[i].get(0) + 1, E[i].get(1) + 1);
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
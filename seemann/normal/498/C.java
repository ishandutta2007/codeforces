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
	int MAXV = 10000;
	List<Integer> fact(int x) {
		List<Integer> res = new ArrayList<>();
		for (int i = 2; i * i <= x; ++i) {
			while (x % i == 0) {
				res.add(i);
				x /= i;
			}
		}
		if (x > 1)
			res.add(x);
		return res;
	}
	int[] p;
	boolean[] used;
	List<Integer>[] e;
	boolean dfs(int v) {
		if (used[v])
			return false;
		used[v] = true;
		for (int d : e[v]) {
			if (p[d] == -1 || dfs(p[d])) {
				p[d] = v;
				return true;
			}
		}
		return false;
	}
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		int[][] mt = new int[n][n];
		for (int i = 0; i < m; i++) {
			int u = in.nextInt();
			int v = in.nextInt();
			u--; v--;
			mt[u][v] = 1;
			mt[v][u] = 1;
		}
		int[] div = new int[MAXV];
		int[] an = new int[MAXV];
		int fr = 0;
		for (int i = 0; i < n; i++) {
			List<Integer> divs = fact(a[i]);
			for (int d : divs) {
				div[fr] = d;
				an[fr] = i;
				//System.err.println(i + " " + an[fr] + " " + div[fr]);
				fr++;
			}
		}
		//System.err.println(fr);
		n = fr;
		e = new List[n];
		for (int i = 0; i < n; i++) {
			if (an[i] % 2 != 0)
				continue;
			e[i] = new ArrayList<Integer>();
			for (int j = 0; j < n; j++) {
				if (mt[an[i]][an[j]] == 1 && div[i] == div[j])
					e[i].add(j);
			}
			//System.err.println(i + " " + an[i] + " " + div[i] + " " + e[i]);
		}
		p = new int[n];
		Arrays.fill(p,  -1);
		used = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (an[i] % 2 != 0)
				continue;
			Arrays.fill(used,  false);
			dfs(i);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (p[i] != -1)
				ans++;
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
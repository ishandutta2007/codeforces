import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		/*
		try {
			inputStream = new FileInputStream("input.txt");
			outputStream = new FileOutputStream("output.txt");
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}*/
		
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		solver.solve(in, out);
		out.close();
	}
}

class Solver {
	public static final int MAXN = 1000001;
	public static final long P = 1011001;
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int m = in.nextInt();
		int e1[] = new int[m];
		int e2[] = new int[m];
		//ArrayList<Integer>[] r = new ArrayList[n];
		int[][] r = new int[n][];
		int[] cr = new int[n];
		long p[] = new long[MAXN];
		p[0] = 1;
		for (int i = 1; i < MAXN; i++) {
			p[i] = p[i - 1] * P;
		}
		long[][] h = new long[n][];
		
		for (int i = 0; i < m; i++) {
			int v = in.nextInt();
			int u = in.nextInt();
			v--;
			u--;
			e1[i] = v;
			e2[i] = u;
			cr[v]++;
			cr[u]++;
		}
		for (int i = 0; i < n; i++) {
			r[i] = new int[cr[i]];
			cr[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int v = e1[i];
			int u = e2[i];
			r[v][cr[v]++] = u;
			r[u][cr[u]++] = v;
		}
		
		long[] a = new long[n];
		
		for (int i = 0; i < n; i++) {
			Arrays.sort(r[i]);
			h[i] = new long[r[i].length];
			if (r[i].length == 0)
				continue;
			h[i][0] = r[i][0] + 1;
			for (int j = 1; j < r[i].length; j++) {
				h[i][j] = h[i][j - 1] * P + r[i][j] + 1; 
			}
			a[i] = h[i][r[i].length - 1];
		}
		Arrays.sort(a);
		long ans = 0;
		long cur = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] == a[i - 1]) {
				cur++;
			} else {
				ans += cur * (cur - 1) / 2;
				cur = 1;
			}
		}
		ans += cur * (cur - 1) / 2;
		
		for (int i = 0; i < m; i++) {
			int v = e1[i];
			int u = e2[i];
			int p1 = Arrays.binarySearch(r[v], u);
			int p2 = Arrays.binarySearch(r[u], v);
			if (p1 > p2) {
				int t = v;
				v = u;
				u = t;
				t = p1;
				p1 = p2;
				p2 = t;
			}
			int c = r[v].length;
			if (r[v].length == r[u].length) {
				boolean ind = true;
				if (p1 > 0) {
					ind = ind && (h[v][p1 - 1] == h[u][p1 - 1]);
				}
				ind = ind && (h[v][c - 1] - h[v][p2] * p[c - 1 - p2] == h[u][c - 1] - h[u][p2] * p[c - 1 - p2]);
				ind = ind && (h[v][p2] - h[v][p1] * p[p2 - p1] == ((p2 > 0)?(h[u][p2 - 1]):(0)) - ((p1 > 0)?(h[u][p1 - 1]):(0)) * p[p2 - p1]);
				if (ind)
					ans++;
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
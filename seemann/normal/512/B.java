import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		/*
		try {
			inputStream = new FileInputStream("a.in");
		//	outputStream = new FileOutputStream("a.out");
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
	List<Integer> divs(int x) {
		List<Integer> res = new ArrayList<Integer>();
		for (int d = 2; d * d <= x; ++d) {
			if (x % d == 0)
				res.add(d);
			while (x % d == 0)
				x /= d;
		}
		if (x != 1)
			res.add(x);
		/*
		for (int d : res)
			System.err.println(d);
		System.err.println();*/
		return res;
	}
	int n;
	int[] l, c;
	int INF = (int)1e9 + 7;
	int getAns(int x) {
		//System.err.println(l[x]);
		List<Integer> d = divs(l[x]);
		int ms = d.size();
		int[] msk = new int[n];
		for (int j = 0; j < n; j++) {
			msk[j] = 0;
			for (int k = 0; k < ms; k++) {
				if (l[j] % d.get(k) != 0)
					msk[j] |= (1  << k);
			}
		}
		int m = 1 << ms;
		int[] dp = new int[m];
		Arrays.fill(dp,  INF);
		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dp[j | msk[i]] = Math.min(dp[j | msk[i]], dp[j] + c[i]);
			}
		}
		return dp[m - 1] + c[x];
	}
	public void solve(InputReader in, PrintWriter out) {
		n = in.nextInt();
		l = new int[n];
		c = new int[n];
		for (int i = 0; i < n; i++) {
			l[i] = in.nextInt();
		}
		for (int i = 0; i < n; i++) {
			c[i] = in.nextInt();
		}
		
		int ans = INF;
		for (int i = 0; i < n; i++) {
			ans = Math.min(ans, getAns(i));
		}
		if (ans >= INF)
			out.println(-1);
		else
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
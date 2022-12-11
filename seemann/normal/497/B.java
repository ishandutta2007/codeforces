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
			outputStream = new FileOutputStream("a.out");
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
	class Ans implements Comparable<Ans>{
		int s, t;

		public Ans(int s, int t) {
			this.s = s;
			this.t = t;
		}
		public int compareTo(Ans o) {
			if (s != o.s)
				return Integer.compare(s, o.s);
			return Integer.compare(t, o.t);
		}
		public String toString() {
			return s + " " + t;
		}
		
	}
	int[] a, b;
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		a = new int[n + 1];
		b = new int[n + 1];
		for (int i = 0; i < n; i++) {
			a[i + 1] = a[i];
			b[i + 1] = b[i];
			if (in.nextInt() == 1)
				a[i + 1]++;
			else
				b[i + 1]++;
		}
		ArrayList<Ans> ans = new ArrayList<>();
		search:
		for (int t = 1; t <= n; ++t) {
			int as = 0;
			int bs = 0;
			int st = 0;
			while (st < n) {
				int l = st;
				int r = n + 1;
				while (l < r - 1) {
					int m = (l + r) / 2;
					if (a[m] - a[st] >= t || b[m] - b[st] >= t)
						r = m;
					else
						l = m;
				}
				if (r == n + 1)
					continue search;
				if (a[r] - a[st] >= t) {
					as++;
					if (r == n && as <= bs)
						continue search;
				} else {
					bs++;
					if (r == n && bs <= as)
						continue search;
				}
				st = r;
			}
			if (as == bs)
				continue;
			ans.add(new Ans(Math.max(as, bs), t));
		}
		Collections.sort(ans);
		out.println(ans.size());
		for (Ans a : ans) {
			out.println(a);
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
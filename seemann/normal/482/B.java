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
	class Event implements Comparable<Event>{
		int x;
		boolean open;
		int n;
		int q;
		public Event(int x, boolean open, int n, int q) {
			super();
			this.x = x;
			this.open = open;
			this.n = n;
			this.q = q;
		}
		public int compareTo(Event o) {
			if (x != o.x)
				return Integer.compare(x, o.x);
			if (open != o.open)
				return Boolean.compare(open, o.open);
			return Integer.compare(n, o.n);
		}
		
	}
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] l = new int[m];
		int[] r = new int[m];
		int[] q = new int[m];
		Event[] e = new Event[2 * m];
		for (int i = 0; i < m; i++) {
			l[i] = in.nextInt() - 1;
			r[i] = in.nextInt();
			q[i] = in.nextInt();
			e[2 * i] = new Event(l[i], true, i, q[i]);
			e[2 * i + 1] = new Event(r[i], false, i, q[i]);
		}
		Arrays.sort(e);
		int[] a = new int[n];
		int[] cur = new int[30];
		int prev = 0;
		for (Event event : e) {
			for (int i = prev; i < event.x; ++i) {
				//System.err.format("%d %d\n", i, cur[0]);
				for (int j = 0; j < 30; j++) {
					if (cur[j] > 0)
						a[i] = a[i] | (1 << j);
				}
			}
			prev = event.x;
			if (event.open) {
				for (int i = 0; i < 30; i++) {
					if ((event.q & (1 << i)) != 0)
						cur[i]++;
				}
			} else {
				for (int i = 0; i < 30; i++) {
					if ((event.q & (1 << i)) != 0)
						cur[i]--;
				}
			}
			
		}
		int[] p = new int[n + 1];
		for (int i = 0; i < 30; i++) {
			p[0] = 0;
			for (int j = 0; j < n; j++) {
				p[j + 1] = p[j];
				if ((a[j] & (1 << i)) == 0)
					p[j + 1]++;
			}
			for (int j = 0; j < m; j++) {
				if ((q[j] & (1 << i)) != 0)
					continue;
				if (p[r[j]] - p[l[j]] == 0) { 
					out.println("NO");
					return;
				}
			}
		}
		out.println("YES");
		for (int i = 0; i < n; i++) {
			out.format("%d ", a[i]);
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
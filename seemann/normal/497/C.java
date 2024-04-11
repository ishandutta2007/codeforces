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
		int x, n;
		int type;
		public Event(int x, int n, int type) {
			this.x = x;
			this.n = n;
			this.type = type;
		}
		public int compareTo(Event o) {
			if (x != o.x)
				return Integer.compare(x, o.x);
			return Integer.compare(type, o.type);
		}
	}
	
	int[] a, b, c, d, k;
	class SComp implements Comparator<Integer> {
		public int compare(Integer x, Integer y) {
			if (d[x] != d[y])
				return Integer.compare(d[x], d[y]);
			return Integer.compare(x, y);
		}
	}
	int[] ans;
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		a = new int[n];
		b = new int[n];
		ArrayList<Event> e = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			b[i] = in.nextInt();
			e.add(new Event(a[i], i, 2));
		}
		ans = new int[n];
		int m = in.nextInt();
		c = new int[m];
		d = new int[m + 1];
		k = new int[m];
		for (int i = 0; i < m; i++) {
			c[i] = in.nextInt();
			d[i] = in.nextInt();
			k[i] = in.nextInt();
			e.add(new Event(c[i], i, 0));
			//e.add(new Event(d[i], i, 1));
		}
		Collections.sort(e);
		TreeSet<Integer> set = new TreeSet<>(new SComp());
		for (Event ev : e) {
			if (ev.type == 0) {
				set.add(ev.n);
			}
			/*
			if (ev.type == 1) {
				set.remove(ev.n);
			}*/
			if (ev.type == 2) {
				int i = ev.n;
				d[m] = b[i] - 1;
				Integer j = set.higher(m);
				if (j == null) {
					out.println("NO");
					return;
				}
				ans[i] = j;
				k[j]--;
				if (k[j] <= 0)
					set.remove(j);
			}
		}
		out.println("YES");
		for (int i = 0; i < n; i++) {
			out.print((ans[i] + 1) + " ");
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
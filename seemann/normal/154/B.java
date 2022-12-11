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
		boolean[] on = new boolean[100001];
		int[] use = new int[100001];
		int n = in.nextInt();
		int m = in.nextInt();
		ArrayList<Integer> d = new ArrayList<Integer>();
		for (int i = 0; i < m; i++) {
			String s = in.next();
			int a = in.nextInt();
			d.clear();
			int w = a;
			for (int j = 2; j * j <= a; j++) {
				if (a % j == 0)
					d.add(j);
				while(w % j == 0) {
					w /= j;
				}
			}
			if (w > 1) {
				d.add(w);
			}
			
			if (s.charAt(0) == '+') {
				if (on[a]) {
					out.println("Already on");
					continue;
				}
				boolean ind = true;
				for (Integer b : d) {
					if (use[b] != 0) {
						ind = false;
						out.print("Conflict with ");
						out.println(use[b]);
						break;
					}
				}
				if (ind) {	
					on[a] = true;
					for (Integer b : d) {
						use[b] = a;
					}
					out.println("Success");
				}
			} else {
				if (!on[a]) {
					out.println("Already off");
					continue;
				}
				on[a] = false;
				for (Integer b : d) {
					use[b] = 0;
				}
				out.println("Success");
			}
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
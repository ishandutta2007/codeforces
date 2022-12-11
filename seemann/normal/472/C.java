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
		String[] f = new String[n];
		String[] s = new String[n];
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			f[i] = in.next();
			s[i] = in.next();
		}
		for (int i = 0; i < n; i++) {
			p[i] = in.nextInt();
			p[i]--;
		}
		String[] f1 = new String[n];
		String[] s1 = new String[n];
		for (int i = 0; i < n; i++) {
			f1[i] = f[p[i]];
			s1[i] = s[p[i]];
		}
		
		f = f1;
		s = s1;
		for (int i = 0; i < n; i++) {
			if (f[i].compareTo(s[i]) >0) {
				String t = f[i];
				f[i] = s[i];
				s[i] = t;
			}
		}
		String[] h = new String[n];
		boolean ans = true;
		/*
		for (int i = 0; i < n; i++) {
			System.out.println(f[i]);
			System.out.println(s[i]);
			System.out.println(f[i].compareTo(s[i]));
			
		}*/
		for (int i = 0; i < n; i++) {
			if (i == 0 || h[i - 1].compareTo(f[i]) < 0) {
				h[i] = f[i];
			} else {
				
				h[i] = s[i];
			}
			if (i != 0 && h[i - 1].compareTo(h[i]) > 0) {
				ans = false;
				break;
			}
		}
		out.println(ans?"YES":"NO");
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
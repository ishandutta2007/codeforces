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
			//outputStream = new FileOutputStream("a.out");
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
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++) {
			s[i] = in.next();
		}
		int a = 26;
		int[][] m = new int[a][a];
		for (int i = 0; i < n - 1; i++) {
			boolean flag = false;
			for (int j = 0; j < Math.min(s[i].length(),  s[i + 1].length()); ++j) {
				if (s[i].charAt(j) != s[i + 1].charAt(j)) {
					int c1 = s[i].charAt(j) - 'a';
					int c2 = s[i + 1].charAt(j) - 'a';
					m[c1][c2] = 1;

					flag = true;
					break;
				}
			}
			if (!flag && s[i].length() > s[i + 1].length()) {
				out.println("Impossible");
				return;
			}
		}
		/*
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				out.print(m[i][j]);
			}
			out.println();
		}*/
		int[] p = new int[a];
		boolean[] used = new boolean[a];
		for (int i = 0; i < a; i++) {
			int nx = -1;
			for (int j = 0; j < a; j++) {
				if (used[j])
					continue;
				boolean flag = false;
				for (int k = 0; k < a; k++) {
					if (m[k][j] == 1) {
						flag = true;
						break;
					}
				}
				if (!flag) {
					nx = j;
					break;
				}
			}
			if (nx == -1) {
				out.println("Impossible");
				return;
			}
			p[i] = nx;
			used[nx] = true;
			for (int j = 0; j < a; j++) {
				m[nx][j] = 0;
			}
		}
		for (int i = 0; i < a; i++) {
			out.print((char)('a' + p[i]));
		}
		out.println();
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
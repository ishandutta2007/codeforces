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
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			solver.solve(in, out);
		}
		
		out.close();
	}
}

class Solver {
	int M = 64;
	int[] toBits(long a) {
		int[] res = new int[M];
		for (int i = 0; i < M; i++) {
			res[i] = ((a & (1L << i)) == 0)?(0):(1);
		}
		return res;
	}
	long toLong(int[] a) {
		long res = 0;
		for (int i = 0; i < M; i++) {
			res += a[i] * (1L << i);
		}
		return res;
	}
	public void solve(InputReader in, PrintWriter out) {
		long l = in.nextLong();
		long r = in.nextLong();
		int[] lb = toBits(l);
		int[] rb = toBits(r);
		int[] ans = new int[M];
		
		for (int i = M - 1; i >= 0; --i) {
			if (lb[i] == 0 && rb[i] == 1) { 
				for (int j = 0; j < i; j++) {
					ans[j] = 1;
				}
				int cnt = 0;
				for (int j = 0; j <= i; j++) {
					cnt += rb[j];
				}
				if (cnt == i + 1) {
					ans[i] = 1;
				}
				break;
			} else {
				ans[i] = lb[i];
			}
		}
		out.println(toLong(ans));
		
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
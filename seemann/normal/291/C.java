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
	private int getIP(String s) {
		String[] t = s.split("\\.");
		int res = 0;
		for (int i = 3; i >= 0; --i) {
			res += (Integer.parseInt(t[i]) << ((3 - i) * 8));
		}
		return res;
	}
	private String toIP(int a) {
		String res = new String();
		for (int i = 0; i < 4; i++) {
			res = new Integer(a & 255).toString() + res;
			a >>= 8;
			if (i < 3)
				res = "." + res;
		}
		return res;
	}
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int k = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = getIP(in.next());
		}
		int mask = 1<<31;
		for (int i = 1; i < 31; i++) {
			TreeSet<Integer> use = new TreeSet<Integer>();
			for (int j = 0; j < n; j++) {
				use.add(a[j] & mask);
			}
			
			if(use.size() == k) {
				out.println(toIP(mask));
				return;
			}
			mask = mask | (1 << (31 - i));
		}
		out.println(-1);
		
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
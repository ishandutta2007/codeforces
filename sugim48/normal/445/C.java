import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		MyScanner in = new MyScanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int[] x = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			x[i] = in.nextInt();
		}
		double max = 0;
		for (; m > 0; m--) {
			int a = in.nextInt();
			int b = in.nextInt();
			int c = in.nextInt();
			double d = (double)(x[a] + x[b]) / c;
			max = Math.max(max, d);
		}
		System.out.println(max);
	}
}

class MyScanner {
	BufferedReader in;
	String[] tokens = {};
	int i = 0;
	
	MyScanner(InputStream in) {
		this.in = new BufferedReader(new InputStreamReader(in));
	}
	
	String next() {
		if (i >= tokens.length) {
			try {
				tokens = in.readLine().split(" ");
			} catch (IOException e) {}
			i = 0;
		}
		return tokens[i++];
	}
	
	int nextInt() {
		return Integer.parseInt(next());
	}
	long nextLong() {
		return Long.parseLong(next());
	}
	double nextDouble() {
		return Double.parseDouble(next());
	}
}
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		MyScanner in = new MyScanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		int p = in.nextInt();
		long[] colsum = new long[n];
		long[] rowsum = new long[m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int a = in.nextInt();
				colsum[i] += a;
				rowsum[j] += a;
			}
		}
		
		Comparator<Long> cmp = new Comparator<Long>() {
			public int compare(Long a, Long b) {
				return Long.compare(b, a);
			}
		};
		PriorityQueue<Long> colque = new PriorityQueue<Long>(11, cmp);
		for (int i = 0; i < n; i++) {
			colque.add(colsum[i]);
		}
		PriorityQueue<Long> rowque = new PriorityQueue<Long>(11, cmp);
		for (int j = 0; j < m; j++) {
			rowque.add(rowsum[j]);
		}
		long[] colple = new long[k + 1];
		long[] rowple = new long[k + 1];
		
		for (int l = 1; l <= k; l++) {
			long sum = colque.remove();
			colple[l] = colple[l - 1] + sum;
			colque.add(sum - m * p);
			sum = rowque.remove();
			rowple[l] = rowple[l - 1] + sum;
			rowque.add(sum - n * p);
		}
		
		long ans = Long.MIN_VALUE;
		for (int l = 0; l <= k; l++) {
			ans = Math.max(ans, colple[l] + rowple[k - l] - (long)l * (k - l) * p);
		}
		System.out.println(ans);
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
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		MyScanner in = new MyScanner(System.in);
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		
		ArrayList<int[]> list = new ArrayList<int[]>();
		{
			int i = 0;
			while (i < n) {
				int j = i + 1;
				while (j < n && a[j - 1] < a[j]) {
					j++;
				}
				list.add(new int[]{i, j});
				i = j;
			}
		}
		
		int N = list.size();
		if (N == 1) {
			System.out.println(n);
			return;
		}
		int ans = 0;
		for (int k = 0; k < N; k++) {
			int[] e = list.get(k);
			int i = e[0], j = e[1];
			ans = Math.max(ans, j - i + 1);
		}
		for (int k = 0; k < N - 1; k++) {
			int[] e = list.get(k);
			int i = e[0], j = e[1];
			int[] _e = list.get(k + 1);
			int _i = _e[0], _j = _e[1];
			if (j - i == 1 || _j - _i == 1) {
				continue;
			}
			if (a[_i] - a[_i - 2] >= 2 || a[_i + 1] - a[_i - 1] >= 2) {
				ans = Math.max(ans, _j - i);
			}
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
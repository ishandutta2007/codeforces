

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {

	public static void solve(FastScanner fs) {	
		int n=fs.nextInt();
		int k=fs.nextInt()-1;
		int[] a=fs.readArray(n);
		ArrayList<Integer> lists=new ArrayList<>();
		for (int i:a)
			lists.add(i);
		Collections.sort(lists);
		for (int i=0; i<n; i++)
			a[i]=lists.get(i);
//		Arrays.sort(a);
		if (k==n-1) {
			System.out.println(a[n-1]);
			return;
		}
		if (k>=n) {
			System.out.println(-1);
			return;
		}
		if (k<0) {
			if (a[0]==1) {
				System.out.println(-1);
			}
			else {
				System.out.println(1);
			}
			return;
		}
		if (a[k]==a[k+1]) {
			System.out.println(-1);
		}
		else {
			System.out.println(a[k]);
		}
		
	}

	
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
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
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}
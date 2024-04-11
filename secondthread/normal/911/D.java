

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class D {

	public static void solve(FastScanner fs) {	
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		boolean even=((countInversions(a)&1)==0);
		int q=fs.nextInt();
		for (int i=0; i<q; i++) {
			int start=fs.nextInt();
			int end=fs.nextInt();
			int diff=end-start;
			boolean evenChange=(diff+1)/2%2==0;
			even^=!evenChange;
			System.out.println(even?"even":"odd");
		}
	}
	
	private static int countInversions(int[] a) {
		int c=0;
		for (int i=0; i<a.length; i++) {
			for (int j=i+1; j<a.length; j++)
				if (a[j]<a[i])
					c++;
		}
		return c;
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
	}
}
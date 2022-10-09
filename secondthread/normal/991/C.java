

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class C {

	public static void solve(FastScanner fs) {	
		long n=fs.nextLong();
		long hi=n, low=1;
		while (hi>low) {
			long mid=(hi+low)/2;
			if (count(n, mid)>=(n+1)/2) {
				hi=mid;
			}
			else {
				low=mid+1;
			}
		}
		System.out.println(hi);
	}
	
	public static long count(long n, long takePerTime) {
		long total=0;
		while (n>0) {
			long toTake=Math.min(takePerTime, n);
			total+=toTake;
			n-=toTake;
			n-=n/10;
		}
		return total;
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


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/*
4 35
11 9 10 7
 */
public class B {

	public static void solve(FastScanner fs) {	
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), maxTime=fs.nextInt();
			int[] a=fs.readArray(n);
			int dontSkipAnyCount=0;
			long totalTime=0;
			for (int i=0; i<n; i++) {
				totalTime+=a[i];
				if (totalTime>maxTime) break;
				dontSkipAnyCount=i+1;
			}
			
			long skippedSize=0;
			int skippedIndex=0;
			int skippedCount=0;
			totalTime=0;
			for (int i=0; i<n; i++) {
				totalTime+=a[i];
				boolean set=false;
				if (a[i]>skippedSize) {
					set=true;
					totalTime+=skippedSize;
					totalTime-=a[i];
				}
				if (totalTime>maxTime) break;
				if (set) {
					skippedIndex=i;
					skippedSize=a[i];
				}
				skippedCount=i;
			}
			if (skippedCount>dontSkipAnyCount) {
				System.out.println(skippedIndex+1);
			}
			else {
				System.out.println(0);
			}
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
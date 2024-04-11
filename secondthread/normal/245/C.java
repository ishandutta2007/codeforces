import java.util.*;
import java.io.*;

public class B {
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		if (n<3||n%2==0) {
			System.out.println(-1);
			return;
		}
		int moves=0;
		for (int i=n-1; i>=0; i--) {
			while (a[i]>0) {
				moves++;
				if (i==0) {
					a[i]--;
				} else if ((i+1)%2==1) {
					//i is biggest of 3
					a[i]--;
					a[i-1]--;
					a[(i-1+1)/2-1]--;
				}
				else {
					//i is middle of 3
					a[(i+1)]--;
					a[i]--;
					a[(i+1)/2-1]--;
				}
			}
		}
		System.out.println(moves);
	}
	

	
	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
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
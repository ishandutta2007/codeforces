import java.util.*;
import java.io.*;

public class A {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int m=fs.nextInt();
		int q=fs.nextInt();
		char[] first=fs.next().toCharArray(), second=fs.next().toCharArray();
		if (m>n) {
			for (int i=0; i<q; i++) System.out.println(0);
			return;
		}
		boolean[] matches=new boolean[n-m+1];
		for (int i=0; i<n-m+1; i++) {
			matches[i]=true;
			for (int j=0; j<m; j++)
				if (first[i+j]!=second[j]) matches[i]=false;
		}
		
		int[] cs=new int[matches.length];
		cs[0]=matches[0]?1:0;
		for (int i=1; i<cs.length; i++)
			cs[i]=cs[i-1]+(matches[i]?1:0);
		for (int i=0; i<q; i++) {
			int from=fs.nextInt()-1, to=fs.nextInt()-1-m+1;
			if (to<from) {
				System.out.println(0);
			}
			else {
				System.out.println(from==0?cs[to]:(cs[to]-cs[from-1]));
			}
		}
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
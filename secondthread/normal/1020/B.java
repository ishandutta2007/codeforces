import java.io.*;
import java.util.*;

public class B {
	
	private static final boolean debug=false;

	public static void main(String[] args) {
		//always possible with 2
		
		//check if it is possible with 1
		//chose 3 non-intersecting lines
		
		// AAAA
		//D    B 
		//D    B
		//D    B
		//D    B
		// CCCC
		//
		//Pick some line
		//for each line that doesn't cross it
		//	limit the acceptable range to inside that line
		//
		//for each line that does cross it
		//  have one list of lines on the left side and one on the right side
		//	if the first or last of each list is not contained in the valid range,
		//	set its other half
		//
		//if it is empty, print 2, and then the x
		//otherwise, convert back to points and print that one line
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		for (int i=0; i<n; i++) {
			int cur=i;
			boolean[] used=new boolean[n];
			while (!used[cur]) {
				used[cur]=true;
				cur=a[cur]-1;
			}
			System.out.print((cur+1)+" ");
		}
		System.out.println();
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
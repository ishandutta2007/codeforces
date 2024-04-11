import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		char[] a=fs.next().toCharArray();
		int tc=0, bc=0;
		int[] tcr= {1, 1, 2, 2};
		int[] tcc= {1, 3, 1, 3};
		int[] bcr= {3, 3, 3, 3};
		int[] bcc= {1, 2, 3, 4};
		for (char c:a) {
			if (c=='1') {
				System.out.println(tcr[tc]+" "+tcc[tc]);
				tc++;
				tc%=4;
			}
			else {
				System.out.println(bcr[bc]+" "+bcc[bc]);
				bc++;
				bc%=4;
			}
		}
	}
	
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
			
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}

}
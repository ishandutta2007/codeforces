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
		int n=fs.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++) a[i]=fs.nextInt();
		int gcd=0;
		for (int i:a) gcd=gcd(i, gcd);
		int max=a[0];
		for (int i:a) max=Math.max(max, i);
		max/=gcd;
		int moves=max-n;
		if (moves%2==0) {
			System.out.println("Bob");
		}
		else {
			System.out.println("Alice");
		}
		
	}
	static int gcd(int a, int b) {
		if (b==0) return a;
		return gcd(b, a%b);
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
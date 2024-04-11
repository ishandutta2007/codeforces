import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int aLen=fs.nextInt(), bLen=fs.nextInt();
		a=fs.next().toCharArray(); b=fs.next().toCharArray();
		dp=new int[aLen][bLen];
		for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], -1);
		int best=0;
		for (int i=aLen-1; i>=0; i--) {
			for (int j=bLen-1; j>=0; j--) {
				best=Math.max(best, go(i, j));
			}
		}
		System.out.println(best);
	}
	
	static char[] a, b;
	static int[][] dp;
	
	static int go(int i, int j) {
		if (i==a.length || j==b.length) return 0;
		if (dp[i][j]!=-1) return dp[i][j];
		
		int best=0; //can stop here
		
		//can extend only i
		best=Math.max(best, -1+go(i+1, j));
		best=Math.max(best, -1+go(i, j+1));
		if (a[i]==b[j]) {
			best=Math.max(best, 2+go(i+1, j+1));
		}
		
		return dp[i][j]=best;
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}
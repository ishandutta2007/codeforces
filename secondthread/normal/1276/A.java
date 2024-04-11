

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {

	static char[] a, one, two;
	static int n;
	static int[][][] dp;
	static PrintWriter out;
	
	public static void solve(FastScanner fs) {	
		int T=fs.nextInt();
		out=new PrintWriter(System.out);
		one="one".toCharArray();
		two="two".toCharArray();
		for (int tt=1;tt<=T; tt++) {
			a=fs.next().toCharArray();
			n=a.length;
			dp=new int[n+1][3][3];
			for (int i=0; i<n; i++)
				for (int j=0; j<dp[i].length; j++)
					Arrays.fill(dp[i][j], -1);
			int ans=go(0, 0, 0);
			out.println(ans);
			buildback(0, 0, 0);
			out.println();
		}
		out.close();
		
		
	}
	
	static int go(int index, int oneInd, int twoInd) {
		if (index==n) return 0;
		if (dp[index][oneInd][twoInd]!=-1) return dp[index][oneInd][twoInd];
		//skip it
		int best=go(index+1, oneInd, twoInd)+1;
		
		//take it
		int newOneIndex, newTwoIndex;
		if (one[oneInd]==a[index])
			newOneIndex=oneInd+1;
		else if (a[index]=='o')
			newOneIndex=1;
		else 
			newOneIndex=0;
		if (two[twoInd]==a[index])
			newTwoIndex=twoInd+1;
		else if (a[index]=='t')
			newTwoIndex=1;
		else 
			newTwoIndex=0;
		
		if (Math.max(newOneIndex, newTwoIndex)<3) {
			best=Math.min(best, go(index+1, newOneIndex, newTwoIndex));
		}
		
		return dp[index][oneInd][twoInd]=best;
	}

	static void buildback(int index, int oneInd, int twoInd) {
		if (index==n) return;
		//skip it
		int best=go(index+1, oneInd, twoInd)+1;
		if (best==go(index, oneInd, twoInd)) {
			out.print(index+1+" ");
			buildback(index+1, oneInd, twoInd);
			return;
		}
		
		//take it
		int newOneIndex, newTwoIndex;
		if (one[oneInd]==a[index])
			newOneIndex=oneInd+1;
		else if (a[index]=='o')
			newOneIndex=1;
		else 
			newOneIndex=0;
		if (two[twoInd]==a[index])
			newTwoIndex=twoInd+1;
		else if (a[index]=='t')
			newTwoIndex=1;
		else 
			newTwoIndex=0;
		
		if (Math.max(newOneIndex, newTwoIndex)<3) {
			best=Math.min(best, go(index+1, newOneIndex, newTwoIndex));
		}
		buildback(index+1, newOneIndex, newTwoIndex);
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
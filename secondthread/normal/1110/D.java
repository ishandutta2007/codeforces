import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;
/*
 */
public class D {
	
	
	static int[] cs;
	static int max;
	static int oo=1_000_000_000;
	static int[][][] dp;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		max=fs.nextInt();
		cs=new int[max+2];
		dp=new int[2][5][5];
		for (int i=0; i<n; i++) cs[fs.nextInt()-1]++;
		
		for (int ind=max; ind>=0; ind--) {
			for (int i=0; i<5; i++) {
				for (int j=0; j<5; j++) {
					dp[(ind&1)][i][j]=-1;
					go(ind, i, j);
				}
			}
		}
		int ans=go(0, 0, 0);
		System.out.println(ans);
	}
	
	static int go(int index, int timesUsed, int nextUsed) {
		if (index==max) {
			if (timesUsed==0 && nextUsed==0) {
				return 0;
			}
			else {
				return -oo;
			}
		}
		if (timesUsed>=5 || nextUsed>=5) {
			return -oo;
		}
		if (dp[index&1][timesUsed][nextUsed]!=-1) return dp[index&1][timesUsed][nextUsed];
		int best=-oo;
		for (int take=0; take<3; take++) {
			int nextMe=cs[index]-timesUsed-take;
			if (nextMe<0) continue;
			int ans=go(index+1, nextUsed+take, take)+take+nextMe/3;
			best=Math.max(best, ans);
		}
		return dp[index&1][timesUsed][nextUsed]=best;
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
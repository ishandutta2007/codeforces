import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class G {
	
	static int[][] dp;
	static int[] a;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			a=fs.readArray(n);
			dp=new int[n+1][2_000];
			for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], -1);
			int ans=Integer.MAX_VALUE;
			for (int start=0; start<2000; start++) {
				ans=Math.min(ans, go(0, start));
			}
			System.out.println(ans);
		}
	}

	static int go(int i, int x) {
		if (x>=2_000 || x<0) return Integer.MAX_VALUE/2;
		if (i>=a.length) return x;
		if (dp[i][x]!=-1) return dp[i][x];
		
		int ans=Integer.MAX_VALUE/2;
		ans=Math.min(ans, Math.max(x, go(i+1, x-a[i])));
		ans=Math.min(ans, Math.max(x, go(i+1, x+a[i])));
		
		return dp[i][x]=ans;
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
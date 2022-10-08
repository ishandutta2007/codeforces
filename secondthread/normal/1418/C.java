import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			a=fs.readArray(n);
			dp=new int[2][n+1];
			for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], -1);
			System.out.println(go(0, 0));
		}
	}
	
	static int[] a;
	static int[][] dp;
	
	//dp[position][turn] = min skips
	//might be possible with a greedy, but once you have solved enough dp problems, this requires no mental effort, so might as well
	static int go(int position, int turn) {
		if (position==a.length) return 0;
		if (dp[turn][position]!=-1) return dp[turn][position];
		int best=1_000_000_000;
		if (turn==0) {
			//friend
			best=Math.min(best, go(position+1, 1)+a[position]);
			if (position!=a.length-1) best=Math.min(best, go(position+2, 1)+a[position]+a[position+1]);
		}
		else {
			//my turn
			best=Math.min(best, go(position+1, 0));
			if (position!=a.length-1) best=Math.min(best, go(position+2, 0));
		}
		return dp[turn][position]=best;
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while (!st.hasMoreElements())
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
	}

}
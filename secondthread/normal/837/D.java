import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ed26D {
	
	static int[] twos, fives;
	static int[][][] dp;
	
	static int getTwos(long n) {
		int i=0;
		while (n%2==0) {
			n/=2;
			i++;
		}
		return i;
	}
	static int getFives(long n) {
		int i=0;
		while (n%5==0) {
			n/=5;
			i++;
		}
		return i;
	}
	
	static int max(int a, int b) {
		return a<b?b:a;
	}

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=(int)fs.nextLong(), k=(int)fs.nextLong();
		twos=new int[n];
		fives=new int[n];
		for (int i=0; i<n; i++) {
			long ai=fs.nextLong();
			twos[i]=getTwos(ai);
			fives[i]=getFives(ai);
		}
		dp=new int[2][k+1][30*n];
		for (int picksLeft=0; picksLeft<=k; picksLeft++)
			for (int fivesNeeded=0; fivesNeeded<30*n; fivesNeeded++)
				dp[n&1][picksLeft][fivesNeeded]=fivesNeeded==0?0:-100000000;
		for (int nn=n-1; nn>=0; nn--) {
			for (int picksLeft=0; picksLeft<=k; picksLeft++)
				for (int fivesNeeded=0; fivesNeeded<n*30; fivesNeeded++) {
					if (picksLeft==0)
						dp[nn&1][picksLeft][fivesNeeded]=fivesNeeded==0?0:-100000000;
					else {
						dp[nn&1][picksLeft][fivesNeeded]=max(dp[(nn+1)&1][picksLeft][fivesNeeded], twos[nn]+dp[(nn+1)&1][picksLeft-1][max(0, fivesNeeded-fives[nn])]);
					}
				}
		}
		int best=0;
		for (int fivesNeeded=0; fivesNeeded<30*n; fivesNeeded++) {
			int twos=dp[0][k][fivesNeeded];
			best=Math.max(best, Math.min(twos, fivesNeeded));
		}
		System.out.println(best);
	}
	
	static int go(int index, int picksLeft, int fivesNeeded) {
		if (index==twos.length) {
			if (fivesNeeded==0) return 0;
			else return -100000000;
		}
		if (picksLeft==0) {
			if (fivesNeeded==0) return 0;
			else return -100000000;
		}
		if (dp[index&1][picksLeft][fivesNeeded]!=-1)
			return dp[index&1][picksLeft][fivesNeeded];
		int ans=go(index+1, picksLeft, fivesNeeded);
		int nextFives=Math.max(0, fivesNeeded-fives[index]);
		ans=Math.max(ans, go(index+1, picksLeft-1, nextFives)+twos[index]);
		return dp[index&1][picksLeft][fivesNeeded]=ans;
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
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}

}
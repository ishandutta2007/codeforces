import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class F {

	static char[] line, t;
	static long[][][] dp;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		line=fs.next().toCharArray();
		t=fs.next().toCharArray();
		if (t[0]==t[1]) {
			int count=0;
			for (char c:line) if (c==t[0]) count++;
			count+=k;
			count=Math.min(count, n);
			System.out.println(count*(long)(count-1)/2);
		}
		else {
			dp=new long[n+1][n+1][n+1];
			for (int i=0; i<dp.length; i++)
				for (int j=0; j<dp[i].length; j++)
					Arrays.fill(dp[i][j], -1);
			
			System.out.println(go(0, 0, k));
		}
	}

	static long go(int position, int nT0, int k) {
		if (position>=line.length) return 0;
		if (dp[position][nT0][k]!=-1) return dp[position][nT0][k];
		long ans=0;
		//neither
		ans=Math.max(ans, go(position+1, nT0, k));
		
		//make T0
		int cost=line[position]==t[0]?0:1;
		if (k>=cost) {
			ans=Math.max(ans, go(position+1, nT0+1, k-cost));
		}
		
		//make T1
		cost=line[position]==t[1]?0:1;
		if (k>=cost) {
			ans=Math.max(ans, nT0+go(position+1, nT0, k-cost));
		}
		
		return dp[position][nT0][k]=ans;
	}
	
	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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
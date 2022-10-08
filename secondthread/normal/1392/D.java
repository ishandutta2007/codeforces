import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
/*
1
4
RRLR
 */
public class D {
	
	static int[][][][][] dp;
	static int n;
	static int[] arr;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			n=fs.nextInt();
			char[] line=fs.next().toCharArray();
			dp=new int[2][2][2][2][n+2];
			for (int i=0; i<dp.length; i++)
				for (int j=0; j<dp[i].length; j++)
					for (int k=0; k<dp[i][j].length; k++)
						for (int kk=0; kk<dp[i][j][k].length; kk++)
							Arrays.fill(dp[i][j][k][kk], -1);
			arr=new int[n];
			for (int i=0; i<n; i++) arr[i]=line[i]=='R'?1:0;
			int best=oo;
			best=Math.min(best, cost(0, 0)+go(0, 0, 0, 0, 2));
			best=Math.min(best, cost(0, 1)+go(0, 1, 0, 1, 2));
			best=Math.min(best, cost(1, 0)+go(1, 0, 1, 0, 2));
			best=Math.min(best, cost(1, 1)+go(1, 1, 1, 1, 2));
			System.out.println(best);
		}
	}
	
	static int cost(int a0, int a1) {
		int ans=0;
		if (arr[0]!=a0) ans++;
		if (arr[1]!=a1) ans++;
		return ans;
	}
	
	static int oo=(int)1e9;
	
	static int go(int twoBack, int back, int first, int second, int pos) {
		if (dp[twoBack][back][first][second][pos]!=-1) return dp[twoBack][back][first][second][pos];
		if (pos==n) {
			if (!okay(twoBack, back, first)) return oo;
			if (!okay(back, first, second)) return oo;
			return 0;
		}
		//otherwise we can pick
		int best=oo;
		if (okay(twoBack, back, 0)) {
			int additional=arr[pos]==0?0:1;
			best=Math.min(best, additional+go(back, 0, first, second, pos+1));
		}
		if (okay(twoBack, back, 1)) {
			int additional=arr[pos]==1?0:1;
			best=Math.min(best, additional+go(back, 1, first, second, pos+1));
		}
		return dp[twoBack][back][first][second][pos]=best;
	}
	
	static boolean okay(int twoBack, int back, int first) {
		if (twoBack==1 && back==1 && first==1) return false;
		if (twoBack==0 && back==0 && first==0) return false;
		return true;
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
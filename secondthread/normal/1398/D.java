import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/*
2 2 0
1 2
2 1

 */
public class D {

	static int nr, nb, ng;
	static int[] ra, ba, ga;
	static long[][][] dp;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		nr=fs.nextInt();
		ng=fs.nextInt();
		nb=fs.nextInt();
		
		ra=fs.readArray(nr);
		ga=fs.readArray(ng);
		ba=fs.readArray(nb);
		Arrays.sort(ra);
		Arrays.sort(ba);
		Arrays.sort(ga);
		dp=new long[201][201][201];
		for (int i=0; i<dp.length; i++)
			for (int j=0; j<dp[0].length; j++)
				Arrays.fill(dp[i][j], -1);
		long ans=go(0, 0, 0);
		System.out.println(ans);
	}
	
	static long go(int r, int b, int g) {
		if (dp[r][b][g]!=-1) return dp[r][b][g];
		long best=0;
		if (r<nr) best=Math.max(best, go(r+1, b, g));
		if (b<nb) best=Math.max(best, go(r, b+1, g));
		if (g<ng) best=Math.max(best, go(r, b, g+1));
		if (r<nr && b<nb)
			best=Math.max(ra[r]*ba[b]+go(r+1, b+1, g), best);
		if (b<nb && g<ng)
			best=Math.max(ba[b]*ga[g]+go(r, b+1, g+1), best);
		if (r<nr && g<ng)
			best=Math.max(ra[r]*ga[g]+go(r+1, b, g+1), best);
		return dp[r][b][g]=best;
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
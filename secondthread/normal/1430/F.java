import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class F {

	static int nWaves, magSize;
	static long[][] dp;
	static Wave[] waves;
	static long oo=(long)1e18, SENT=-oo;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		nWaves=fs.nextInt();
		magSize=fs.nextInt();
		waves=new Wave[nWaves];
		dp=new long[nWaves+1][nWaves+1];
		for (int i=0; i<dp.length; i++)
			Arrays.fill(dp[i], SENT);
		for (int i=0; i<nWaves; i++) 
			waves[i]=new Wave(fs.nextInt(), fs.nextInt(), fs.nextInt());
		long ans=magSize+go(0, 0, magSize);
		if (ans>=oo)
			System.out.println(-1);
		else 
			System.out.println(ans);
	}
	
	static long go(int wave, int lastFresh, int bulletsInMag) {
		//TODO: base
		if (wave==nWaves) {
			return -bulletsInMag;
		}
		if (dp[wave][lastFresh]!=SENT) return dp[wave][lastFresh];
		
		int nReloads=(waves[wave].size-bulletsInMag+magSize-1)/magSize;
		if (waves[wave].r-waves[wave].l<nReloads) return oo;
		long bulletsUsed=nReloads*(long)magSize;
		int futureMag=(int) (bulletsUsed+bulletsInMag-waves[wave].size);
		
		long ans=bulletsUsed+go(wave+1, lastFresh, futureMag);
		int startTime=waves[wave].l;
		int endTime=startTime+nReloads;
		if (wave+1<nWaves && endTime<waves[wave+1].l) {
			//can start fresh
			ans=Math.min(ans, bulletsUsed+magSize+go(wave+1, wave+1, magSize));
		}
		return dp[wave][lastFresh]=ans;
	}
	
	static class Wave {
		int l, r, size;
		public Wave(int l, int r, int size) {
			this.l=l;
			this.r=r;
			this.size=size;
		}
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
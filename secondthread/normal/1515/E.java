import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {

	static long mod;
	static long[][] dp;
	static int n;
	static long[] nWaysToPlaceGroupOfSize;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		n=fs.nextInt();
		mod=fs.nextInt();
		precomp();
		dp=new long[n+1][n+1];
		for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], -1);
		
		long ans=0;
		for (int nXsLeft=2; nXsLeft<=n; nXsLeft++) {
			long curAns=go(0, nXsLeft);
			ans=add(ans, curAns);
		}
		System.out.println(ans);
	}
	
	static long go(int position, int nXsLeft) {
		if (position==n) {
			//last thing was skipped, impossible
			return 0;
		}
		if (position==n+1) {
			//last thing was included, 1 way of doing that
			if (nXsLeft==0) return 1;
			return 0;
		}
		if (dp[position][nXsLeft]!=-1) {
			return dp[position][nXsLeft];
		}
		//TODO: brute force number of xs to place
		long ways=0;
		for (int nPlace=1; nPlace<=Math.min(nXsLeft, n-position); nPlace++) {
			long futureWays=go(position+nPlace+1, nXsLeft-nPlace);
			long waysToPlaceMe=nCk(nXsLeft, nPlace);
			if (nPlace>1) waysToPlaceMe=mul(waysToPlaceMe, nWaysToPlaceGroupOfSize[nPlace]);
			ways=add(ways, mul(waysToPlaceMe, futureWays));
		}
		return dp[position][nXsLeft]=ways;
	}
	
	static long nCk(int n, int k) {
		if (k>n) throw null;
		return mul(facts[n], mul(factInvs[k], factInvs[n-k]));
	}
	
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	static long mul(long a, long b) {
		return (a*b)%mod;
	}
	static long fastPow(long base, long e) {
		if (e==0) return 1;
		long half=fastPow(base, e/2);
		if (e%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	
	static long[] facts=new long[1_000_00];
	static long[] factInvs=new long[1_000_00];
	static void precomp() {
		facts[0]=1;
		for (int i=1; i<facts.length; i++) facts[i]=mul(facts[i-1], i);
		for (int i=0; i<factInvs.length; i++) factInvs[i]=fastPow(facts[i], mod-2);
		nWaysToPlaceGroupOfSize=new long[500];
		for (int finalSize=1; finalSize<nWaysToPlaceGroupOfSize.length; finalSize++) {
			for (int firstPos=0; firstPos<finalSize; firstPos++) {
				int l=firstPos, r=finalSize-1-firstPos;
				nWaysToPlaceGroupOfSize[finalSize]=add(nWaysToPlaceGroupOfSize[finalSize], nCk(l+r, l));
			}
		}
		System.err.println("Done with precomp.");
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
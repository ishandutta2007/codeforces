import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {
	
	static final long mod=1_000_000_007;
	static int[] minPrefixSumForPos;
	static int[] aMaxes;
	static long[][] dp;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		dp=new long[101][100_01];
		for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], -1);
		int n=fs.nextInt();
		aMaxes=fs.readArray(n);
		int[] diffs=fs.readArray(n-1);
		int nQueries=fs.nextInt();
		
		int minStart=fs.nextInt();
		minPrefixSumForPos=new int[n];
		minPrefixSumForPos[0]=minStart;
		int lastValue=minStart;
		for (int i=1; i<n; i++) {
			lastValue+=diffs[i-1];
			minPrefixSumForPos[i]=minPrefixSumForPos[i-1]+lastValue;
		}
		
		long ans=dp(0, 0);
		System.out.println(ans);
	}
	
	//100 positions, 10_000 prefix sums
	static long dp(int position, int prefixSum) {
		if (position == aMaxes.length) return 1;
		if (dp[position][prefixSum]!=-1) return dp[position][prefixSum];
		
		int biggestPlace=aMaxes[position];
		//place between 0 and biggestPlace;
		int smallestPlace=Math.max(0, minPrefixSumForPos[position]-prefixSum);
		if (smallestPlace>biggestPlace) return 0;
	
		//TODO: make this part O(1);
		long ans=0;
		for (int toPlace=smallestPlace; toPlace<=biggestPlace; toPlace++) {
			ans=add(ans, dp(position+1, prefixSum+toPlace));
		}
		return dp[position][prefixSum]=ans;
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static long add(long a, long b) {
		return ((a+b)%mod+mod)%mod;
	}
	
	static long mul(long a, long b) {
		return a*b%mod;
	}
	
	static long pow(long base, long exp) {
		if (exp==0) return 1;
		long half=pow(base, exp/2);
		if (exp%2==0) return mul(half, half);
		else return mul(half, mul(half, base));
	}
	
	static long inv(long x) {
		return pow(x, mod-2);
	}
	
	static long[] facts=new long[1_000_00];
	static long[] factsInv=new long[1_000_00];
	
	static void precomp() {
		facts[0]=1;
		for (int i=1; i<facts.length; i++) facts[i]=mul(facts[i-1],i);
		for (int i=0; i<factsInv.length; i++) factsInv[i]=inv(facts[i]);
	}
	
	static long nCk(int n, int k) {
		return mul(facts[n], mul(factsInv[k], factsInv[n-k]));
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
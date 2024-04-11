import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map.Entry;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class D {

	static long[] uniquePrimeFactors;
	static long[][][] dp;
	static int mod=1_000_000_007;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		long n=fs.nextLong();
		int numTurns=fs.nextInt();
		TreeMap<Long, Integer> primeFactors=getPrimeFactorization(n);
		uniquePrimeFactors=new long[primeFactors.size()];
		int index=0;
		for (long l:primeFactors.keySet())
			uniquePrimeFactors[index++]=l;
//		System.out.println(Arrays.toString(uniquePrimeFactors));
		
		dp=new long[65][uniquePrimeFactors.length][numTurns+1];
		for (int i=0; i<dp.length; i++)
			for (int j=0; j<dp[i].length; j++)
				Arrays.fill(dp[i][j], -1);
		long expected=1;
		for (int i=0; i<uniquePrimeFactors.length; i++) {
			long expectedValue=go(primeFactors.get(uniquePrimeFactors[i]), i, numTurns);
//			System.out.println("for prime "+uniquePrimeFactors[i]+" expected value: "+expectedValue);
			expected=(expected*expectedValue)%mod;
		}
		System.out.println(expected);
	}
	
	static long go(int factorsLeft, int factor, int turnsLeft) {
		if (dp[factorsLeft][factor][turnsLeft]!=-1) {
			return dp[factorsLeft][factor][turnsLeft];
		}
		if (turnsLeft==0)
			return fastPow(uniquePrimeFactors[factor], factorsLeft);
		if (factorsLeft==0)
			return 1;
		long expected=0;
		long _1OverN=fastPow(factorsLeft+1, mod-2);
//		System.out.println("1/"+factorsLeft+" = "+_1OverN);
		for (int picked=0; picked<=factorsLeft; picked++) {
			long nextExpected=go(picked, factor, turnsLeft-1);
			expected=(expected+nextExpected)%mod;
		}
		expected=(expected*_1OverN)%mod;
		return dp[factorsLeft][factor][turnsLeft]=expected;
	}
	
	static long fastPow(long base, int pow) {
		if (pow==0) return 1;
		long half=fastPow(base, pow/2);
		if (pow%2==0)
			return half*half%mod;
		else
			return half*half%mod*(base%mod)%mod;
	}
	
	static TreeMap<Long, Integer> getPrimeFactorization(long n) {
		long orig=n;
		TreeMap<Long, Integer> toReturn=new TreeMap<>();
		for (long i=2; i*i<=orig; i++) {
			while (n%i==0) {
				toReturn.put(i, toReturn.getOrDefault(i, 0)+1);
				n/=i;
			}
		}
		if (n!=1) {
			toReturn.put(n, toReturn.getOrDefault(n, 0)+1);
		}
		return toReturn;
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
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

/*
3
2 2 4
 */
public class D {

//	static ArrayList<Integer>[] factorsOf=new ArrayList[5_000_001];
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
//		for (int base=1; base<factorsOf.length; base++)
//			factorsOf[base]=new ArrayList<>();
//		int[] nFactors=new int[5_000_001];
//		for (int i=1; i<nFactors.length; i++)
//			for (int j=i; j<nFactors.length; j+=i)
//				nFactors[j]++;
//		int[][] factorsOf=new int[nFactors.length][];
//		for (int i=0; i<nFactors.length; i++)
//			factorsOf[i]=new int[nFactors[i]];
//		Arrays.fill(nFactors, 0);
//		for (int i=1; i<nFactors.length; i++)
//			for (int j=i; j<nFactors.length; j+=i)
//				factorsOf[j][nFactors[j]++]=i;
		
//		for (int base=1; base<factorsOf.length; base++)
//			for (int j=base; j<factorsOf.length; j+=base)
//				factorsOf[j].add(base);
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		int[] counts=new int[5_000_001];
		for (int i:a) counts[i]++;
		int[] counts2=new int[counts.length];
		for (int i=1; i<counts.length; i++) {
			for (int j=i; j<counts.length; j+=i)
				counts2[i]+=counts[j];
		}
		for (int i:a) counts[i]++;
		long[] dp=new long[counts.length];
		long ans=0;
		for (int gcd=1; gcd<counts.length; gcd++) {
			dp[gcd]+=gcd*(long)counts2[gcd];
			for (int hit=gcd*2; hit<counts.length; hit+=gcd) {
				dp[hit]=Math.max(dp[hit], dp[gcd]-counts2[hit]*(long)gcd);
			}
//			for (int factor:factorsOf[gcd]) {
//				if (factor!=gcd)
//					dp[gcd]=Math.max(dp[gcd], gcd*(long)counts2[gcd] - factor*(long)counts2[gcd]+dp[factor]);
//			}
			ans=Math.max(ans, dp[gcd]);
		}
		System.out.println(ans);
	}
	
	
	static final long mod=1_000_000_007;
	static long mul(long a, long b) {
		return a*b%mod;
	}
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long fastPow(long base, long e) {
		if (e==0) return 1;
		long half=fastPow(base, e/2);
		if (e%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	static long[] facts, invFacts;
	static void precomp() {
		facts=new long[1_100_000];
		invFacts=new long[1_100_000];
		facts[0]=invFacts[0]=1;
		for (int i=1; i<facts.length; i++) {
			facts[i]=mul(i, facts[i-1]);
		}
		invFacts[invFacts.length-1]=fastPow(facts[facts.length-1], mod-2);
		for (int i=invFacts.length-2; i>=0; i--) {
			invFacts[i]=mul(invFacts[i+1], i+1);
		}
		if (mul(facts[6], invFacts[6])!=1) throw null;
	}
	
	static long nCk(int n, int k) {
		return mul(facts[n], mul(invFacts[k], invFacts[n-k]));
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
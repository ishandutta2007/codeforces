import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeSet;
/*

 */
public class C2 {
	
	static long mod=998244353;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), q=fs.nextInt();
		long[] ps=new long[n];
		for (int i=0; i<n; i++) ps[i]=frac(fs.nextInt(), 100);
		
		long[] cumProbs=new long[n+1];
		cumProbs[0]=1;
		for (int i=0; i<n; i++) cumProbs[i+1]=mul(cumProbs[i], ps[i]);
		
		long[] cumProbsCS=new long[n+2];
		for (int i=0; i<cumProbs.length; i++) cumProbsCS[i+1]=add(cumProbsCS[i], cumProbs[i]);
		
		TreeSet<Integer> checkpoints=new TreeSet<Integer>();
		checkpoints.add(0); checkpoints.add(n);
		
		long value=sectionValue(0, n-1, cumProbs, cumProbsCS);
		
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<q; qq++) {
			int toChange=fs.nextInt()-1;
			int before=checkpoints.lower(toChange), after=checkpoints.higher(toChange);
			if (checkpoints.contains(toChange)) {
				//remove
				value=sub(value, sectionValue(before, toChange-1, cumProbs, cumProbsCS));
				value=sub(value, sectionValue(toChange, after-1, cumProbs, cumProbsCS));
				value=add(value, sectionValue(before, after-1, cumProbs, cumProbsCS));
				checkpoints.remove(toChange);
			}
			else {
				//add in
				value=sub(value, sectionValue(before, after-1, cumProbs, cumProbsCS));
				value=add(value, sectionValue(before, toChange-1, cumProbs, cumProbsCS));
				value=add(value, sectionValue(toChange, after-1, cumProbs, cumProbsCS));
				checkpoints.add(toChange);
			}
			out.println((value%mod+mod)%mod);
		}
		out.close();
	}
	
	static long sectionValue(int from, int to, long[] cumProbs, long[] cumProbsCS) {
		long toDivOut=cumProbs[from];
		long cumProb=cumProbsCS[to+1]-cumProbsCS[from];
		long expectedValue=frac(cumProb, toDivOut);
		long chanceThrough=frac(cumProbs[to+1], cumProbs[from]);
		long expectedNumberOfTimes=frac(1, chanceThrough);
		
		long ans=mul(expectedValue, expectedNumberOfTimes);
		return ans;
	}
	
	static long frac(long n, long d) {
		return mul(n, modInv(d));
	}

	static long mul(long a, long b) {
		return a*b%mod;
	}
	
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	
	static long modInv(long n) {
		return fastPow(n, mod-2);
	}
	
	static long fastPow(long base, long exp) {
		long res=1;
		for (int i=0; i<31; i++) {
			if ((exp&(1<<i))!=0) {
				res*=base;
				res%=mod;
			}
			base*=base;
			base%=mod;
		}
		return res;
//		if (exp==0) return 1;
//		long half=fastPow(base, exp/2);
//		if (exp%2==0) return half*half%mod;
//		return half*half%mod*base%mod;
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		String next() {
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
	}
}
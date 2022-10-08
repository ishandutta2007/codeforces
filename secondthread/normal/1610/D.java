import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/*
3
2 2 4
 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		precomp();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		long ans=add(solve(a, true)-1, mod);
		System.out.println(ans);
	}
	
	//lets us pick nothing
	static long solve(int[] a, boolean root) {
		if (a.length==0) return 1;
		int nEven=0, nOdd=0;
		for (int i:a) if (i%2==0) nEven++; else nOdd++;
		long evenWays=fastPow(2, nEven);
		if (root) {
			long ans=0;
			//AT LEAST ONE ODD
			for (int i=1; i<=nOdd; i++) {
				long oddWays=nCk(nOdd, i);
				ans=add(ans, mul(evenWays, oddWays));
			}
			
			//0 ODDS
			int[] newA=new int[nEven];
			nEven=0;
			for (int i:a) if (i%2==0) newA[nEven++]=i/2;
			ans=add(ans, solve(newA, false));
			
			return ans;
		}
		else {
			//PICK EVEN NUMBER OF 1S
			int[] newA=new int[nEven];
			nEven=0;
			for (int i:a) if (i%2==0) newA[nEven++]=i/2;
			//PICK 0 ODDS
			long futureWays=solve(newA, false);
			
			//PICK EVEN NUMBER OF ODDS, any subset of evens
			long oddWays=0;
			for (int i=2; i<=nOdd; i+=2) {
				oddWays=add(oddWays, nCk(nOdd, i));
			}
			long nWays=add(
						mul(oddWays, evenWays), //at least one odd, any evens
						futureWays
					);//all evens
			return nWays;
		}
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
		facts=new long[300_000];
		invFacts=new long[300_000];
		facts[0]=invFacts[0]=1;
		for (int i=1; i<facts.length; i++) {
			facts[i]=mul(i, facts[i-1]);
			invFacts[i]=fastPow(facts[i], mod-2);
		}
//		System.out.println(mul(facts[100], invFacts[100]));
//		System.out.println(facts[3]);
//		if (mul(facts[100], invFacts[100])!=1 || facts[3]!=6) throw null;
		
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
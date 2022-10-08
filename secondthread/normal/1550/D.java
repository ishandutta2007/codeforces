import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/*
4
3 0 3
4 -3 5
42 -33 55
69 -42 146

n=3 l=-1, r=4


 */
public class D2 {
	
	static final long mod=1_000_000_007;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		precomp();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), l=fs.nextInt(), r=fs.nextInt();
			long ans=0;
//			if (n%2==0) {
			// l+offset-1 > 0
			// offset > 1-l
			// OR
			// offset-(r-n) > 0
			// offset > r-n
			int nSkip=Math.min(1-l, r-n);
//			System.out.println("nSkip: "+nSkip);
			if (nSkip>0) {
				long timesEffective=nSkip;
				ans=add(ans, mul(ways(0, 0, n), timesEffective));
			}
//			int nSkip=0;
			
			for (int offset=1+nSkip; true; offset++) {
				int forcedPositive = Math.max(0, l+offset-1);
				int forcedNegative = Math.max(0, offset-(r-n));
				int either=n-forcedPositive-forcedNegative;
//				System.out.println(" a "+forcedPositive+" "+forcedNegative+" "+either);
				if (either<0) break;
				long toAdd=ways(forcedPositive, forcedNegative, either);
				ans=add(ans, toAdd);
			}
//			}
//			else {
//				for (int offset=1; true; offset++) {
//					int forcedPositive = Math.max(0, l+offset-1);
//					int forcedNegative = Math.max(0, offset-(r-n));
//					int either=n-forcedPositive-forcedNegative;
//					if (either<0) break;
//					long toAdd=ways(forcedPositive, forcedNegative, either);
//					ans=add(ans, toAdd);
//				}
//			}
			System.out.println(ans);
		}
	}
	
	static long ways(int forcedPositive, int forcedNegative, int either) {
		int n=forcedPositive+forcedNegative+either;
		if (n%2==0)
			return nCk(n-forcedPositive-forcedNegative, n/2-forcedPositive);
		int k1=n/2;
		int k2=n/2+1;
		long ans=nCk(n-forcedPositive-forcedNegative, k1-forcedPositive);
		ans=add(ans, nCk(n-forcedPositive-forcedNegative, k2-forcedPositive));
//		System.out.println("For forcedPositive: "+forcedPositive+" "+forcedNegative+" "+either+" returning "+ans);
		return ans;
	}
	
	static long add(long a, long b) {
		return (a+b)%mod;
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
	
	static long inv(long x) {
		return fastPow(x, mod-2);
	}
	
	static long[] facts=new long[1_000_001], factInvs=new long[1_000_001];

	static void precomp() {
		facts[0]=1;
		for (int i=1; i<facts.length; i++) {
			facts[i]=mul(facts[i-1], i);
			factInvs[i]=inv(facts[i]);
		}
		factInvs[0]=1;
	}
	
	static long nCk(int n, int k) {
		if (k<0 || k>n) return 0;
		return mul(facts[n], mul(factInvs[k], factInvs[n-k]));
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
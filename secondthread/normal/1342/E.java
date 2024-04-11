import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class E {
	
	static long mod=998244353;
	static long[] facts, factInvs;
	
	public static void main(String[] args) {
		precomp();
		FastScanner fs=new FastScanner();
		try {
		int n=fs.nextInt(), k=fs.nextInt();
		if (k==0) {
			System.out.println(facts[n]);
			return;
		}
		if (k>=n) {
			System.out.println(0);
			return;
		}
		int nUsable=n-k;
		long assignWays=powGo(nUsable, n);
		long pickThese=nCk(n, nUsable);
		long ways=mul(assignWays, pickThese);
		System.out.println(mul(ways, 2));
		}
		catch(Throwable t) {
			System.out.println(0);
		}
	}
	
	static long powGo(int base, long exp) {
		long ans=0;
		for (int sub=0; sub<base; sub++) {
			long delta=fastPow(base-sub, exp)*nCk(base, sub);
			if (sub%2==0) {
				ans=add(ans, delta);
			}
			else {
				ans=sub(ans, delta);
			}
		}
		return ans;
	}
	
	static void precomp() {
		facts=new long[1_000_000];
		factInvs=new long[1_000_000];
		facts[0]=factInvs[0]=1;
		for (int i=1; i<facts.length; i++) facts[i]=mul(facts[i-1], i);
		factInvs[facts.length-1]=fastPow(facts[facts.length-1], mod-2);
		for (int i=factInvs.length-2; i>=0; i--) factInvs[i]=mul(factInvs[i+1], i+1);
	}
	
	static long nCk(int n, int k) {
		long ans=mul(facts[n], mul(factInvs[k], factInvs[n-k]));
		return ans;
	}

	static long add(long a, long b) {
		return (a+b)%mod;
	}
	
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	
	static long mul(long a, long b) {
		return a*b%mod;
	}
	
	static long fastPow(long base, long exp) {
		if (exp==0) return 1;
		long half=fastPow(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreElements())
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
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
	
}
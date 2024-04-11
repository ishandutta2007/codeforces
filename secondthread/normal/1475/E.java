import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=fs.nextInt();
			int[] a=fs.readArray(n);
			Arrays.sort(a);
			int last=a[n-k];
			int count=0;
			int toPick=0;
			for (int i:a) if (i==last) count++;
			for (int i=0; i<k; i++) if (a[n-1-i]==last) toPick++;
			System.out.println(nCk(count, toPick));
		}
	}

	static final int mod=1_000_000_007;
	
	static long mul(long a, long b) {
		return a*b%mod;
	}
	
	static long fact(int x) {
		long ans=1;
		for (int i=2; i<=x; i++) ans=mul(ans, i);
		return ans;
	}
	
	static long fastPow(long base, long exp) {
		if (exp==0) return 1;
		long half=fastPow(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	
	static long modInv(long x) {
		return fastPow(x, mod-2);
	}
	
	static long nCk(int n, int k) {
		return mul(fact(n), mul(modInv(fact(k)), modInv(fact(n-k))));
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
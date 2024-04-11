import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/* 
 * Subscribe to galen_colin!
 * https://tinyurl.com/galencolin
*/
public class E {

	public static void main(String[] args) {
		precomp();
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=fs.nextInt(), rangeSize=fs.nextInt();
			int[] a=fs.readArray(n);
			int[] freq=new int[n+1];
			for (int i:a) freq[i]++;
			int[] cs=new int[freq.length+1];
			for (int i=1; i<cs.length; i++) cs[i]=cs[i-1]+freq[i-1];
			long ways=0;
			for (int max=0; max<freq.length; max++) {
				int nLessThan=cs[max]-cs[Math.max(0, max-rangeSize)];
				for (int toInclude=1; toInclude<=freq[max]; toInclude++) {
					if (nLessThan+toInclude<k) continue;
					long toAdd=nCk(nLessThan+toInclude-1, k-1);
					ways=add(ways, toAdd);
				}
			}
			out.println(ways);
		}
		out.close();
	}
	
	static long mod=1_000_000_007;
	
	static long[] facts=new long[3_000_00];
	//don't care about your feelings
	
	static long mul(long a, long b) {
		return a*b%mod;
	}
	
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	
	static void precomp() {
		facts[0]=1;
		for (int i=1; i<facts.length; i++) facts[i]=mul(facts[i-1], i);
	}
	
	static long exp(long base, long pow) {
		if (pow==0) return 1;
		long half=exp(base, pow/2);
		if (pow%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	
	static long modInv(long x) {
		return exp(x, mod-2);
	}
	
	static long nCk(int n, int k) {
		return mul(facts[n], mul(modInv(facts[k]), modInv(facts[n-k])));
	}

	static void ruffle_sort(int[] a) {
		//shandom_ruffle
		Random r=new Random();
		int n=a.length;
		for (int i=0; i<n; i++) {
			int oi=r.nextInt(i);
			int temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
		}
		
		//sort
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
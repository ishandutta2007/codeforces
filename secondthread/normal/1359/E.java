import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {
	
	static long mod=998244353;
	static long[] facts=new long[1_000_000];
	static long[] factsInv=new long[1_000_000];

	public static void main(String[] args) {
		precomp();
//		for (int i=0; i<n10; i++) {
//			System.out.println(i+" "+facts[i]);
//		}
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		if (n<k) {
			System.out.println(0);
			return;
		}
		long ans=0;
		for (int min=1; min<=n; min++) {
			int size=n/min;
			if (size<k) continue;
			ans+=nCk(size-1, k-1);
			ans%=mod;
		}
		System.out.println(ans);
	}
	
	static void precomp() {
		facts[0]=1;
		for (int i=1; i<facts.length; i++) facts[i]=mul(facts[i-1], i);
		factsInv[factsInv.length-1]=inv(facts[facts.length-1]);
		for (int i=factsInv.length-2; i>=0; i--)
			factsInv[i]=mul(factsInv[i+1], i+1); 
	}
	
	static long nCk(int n, int k) {
		return mul(facts[n], mul(factsInv[k], factsInv[n-k]));
	}
	
	static long mul(long a, long b) {
		return a*b%mod;
	}
	
	static long pow(long base, long e) {
		if (e==0) return 1;
		long half=pow(base, e/2);
		if (e%2==0) return mul(half, half);
		return mul(half, mul(base, half));
	}
	
	static long inv(long x) {
		return pow(x, mod-2);
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
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

/*
3
2 2 4
 */
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		precomp();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			P[] pairs=new P[n];
			for (int i=0; i<n; i++) pairs[i]=new P(fs.nextInt(), i);
			Arrays.sort(pairs);
			long total=0;
			int[] ans=new int[n+1];
			int l=-1, r=1;
			for (int i=n-1; i>=0; i--) {
				P p=pairs[i];
				if (i%2==0) {
					ans[p.j]=l--;
				}
				else {
					ans[p.j]=r++;
				}
				total+=Math.abs(ans[p.j]*(long)p.i);
			}
			out.println(total*2);
			out.print("0 ");
			for (int i=0; i<ans.length-1; i++) {
				out.print(ans[i]+" ");
			}
			out.println();
		}
		out.close();
	}
	
	static class P implements Comparable<P> {
		int i, j;
		public P(int i, int j) {
			this.i=i;
			this.j=j;
		}
		public int compareTo(P o) {
			return Integer.compare(i, o.i);
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
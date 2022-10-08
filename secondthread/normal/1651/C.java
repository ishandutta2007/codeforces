import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

/*

XXXXXXXXXXXXXXX
XXXXXXXXXXXXXXX

1 2 3 4 5 6 7 8
1 8 8 8 8 8 8 4
 */
public class C {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n), b=fs.readArray(n);
			/*
			 * both vertical
			 * X
			 * L, right is free
			 * R, left is free
			 * tl to br, others free
			 * tr to bl, others free
			 */
			
			long ans=Long.MAX_VALUE;
			ans=Math.min(ans, a(a[0], b[0])+a(a[n-1], b[n-1]));
			ans=Math.min(ans, a(a[0], b[n-1])+a(a[n-1], b[0]));
			ans=Math.min(ans, a(a[0], b[0])+minDiff(b, a[n-1])+minDiff(a, b[n-1]));
			ans=Math.min(ans, a(a[n-1], b[n-1])+minDiff(b, a[0])+minDiff(a, b[0]));
			ans=Math.min(ans, a(a[0], b[n-1])+minDiff(b, a[n-1])+minDiff(a, b[0]));
			ans=Math.min(ans, a(a[n-1], b[0])+minDiff(b, a[0])+minDiff(a, b[n-1]));
			ans=Math.min(ans, minDiff(b, a[0])+minDiff(a, b[0])+minDiff(b, a[n-1])+minDiff(a, b[n-1]));
			System.out.println(ans);
		}
	}
	static long a(int a, int b) {
		return Math.abs(a-b);
	}
	
	static long minDiff(int[] a, int x) {
		int ans=Math.abs(a[0]-x);
		for (int i:a) ans=Math.min(Math.abs(i-x), ans);
		return ans;
	}
	
	static final Random random=new Random();
	static final int mod=1_000_000_007;
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	static long mul(long a, long b) {
		return (a*b)%mod;
	}
	static long exp(long base, long exp) {
		if (exp==0) return 1;
		long half=exp(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	static long[] factorials=new long[2_000_001];
	static long[] invFactorials=new long[2_000_001];
	static void precompFacts() {
		factorials[0]=invFactorials[0]=1;
		for (int i=1; i<factorials.length; i++) factorials[i]=mul(factorials[i-1], i);
		invFactorials[factorials.length-1]=exp(factorials[factorials.length-1], mod-2);
		for (int i=invFactorials.length-2; i>=0; i--)
			invFactorials[i]=mul(invFactorials[i+1], i+1);
	}
	
	static long nCk(int n, int k) {
		return mul(factorials[n], mul(invFactorials[k], invFactorials[n-k]));
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
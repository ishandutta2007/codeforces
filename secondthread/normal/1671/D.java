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
1
3 8
7 2 10

 */
public class D {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int x=fs.nextInt();
			int[] a=fs.readArray(n);
			long ans=Long.MAX_VALUE;
			//cost of prefix/suffix starting at i
			long[] plainSuffix=new long[n];
			long[] plainPrefix=new long[n];
			int[] diffs=new int[n-1];
			for (int i=1; i<n; i++) diffs[i-1]=d(a[i], a[i-1]);
			for (int i=1; i<n; i++) plainPrefix[i]=plainPrefix[i-1]+diffs[i-1];
			for (int i=n-2; i>=0; i--) plainSuffix[i]=plainSuffix[i+1]+diffs[i];
			
			//..,1x,..
			ans=Math.min(ans, d(1, x) + d(x, a[0]) + plainSuffix[0]);
			ans=Math.min(ans, d(x, 1) + d(1, a[0]) + plainSuffix[0]);
			ans=Math.min(ans, plainPrefix[n-1]+ d(a[n-1], 1) + d(1, x));
			ans=Math.min(ans, plainPrefix[n-1]+ d(a[n-1], x) + d(x, 1));
			for (int first=0; first<n-1; first++) {
				ans=Math.min(ans, plainPrefix[first] + d(a[first], 1) + d(1, x) + d(x, a[first+1]) + plainSuffix[first+1]);
				ans=Math.min(ans, plainPrefix[first] + d(a[first], x) + d(x, 1) + d(1, a[first+1]) + plainSuffix[first+1]);
			}
			Pair[] firstChoices=new Pair[n+1], secondChoices=new Pair[n+1];
			firstChoices[0]=new Pair(d(1, a[0]), 0);
			firstChoices[n]=new Pair(d(a[n-1], 1), n);
			for (int i=1; i<n; i++) firstChoices[i]=new Pair(d(a[i-1], 1)+d(a[i], 1)-d(a[i-1], a[i]), i);
			
			secondChoices[0]=new Pair(d(x, a[0]), 0);
			secondChoices[n]=new Pair(d(a[n-1], x), n);
			for (int i=1; i<n; i++) secondChoices[i]=new Pair(d(a[i-1], x)+d(a[i], x)-d(a[i-1], a[i]), i);
			Arrays.sort(firstChoices);
			Arrays.sort(secondChoices);
			long additionalCost=Long.MAX_VALUE;
			if (firstChoices[0].index==secondChoices[0].index) {
				additionalCost=Math.min(firstChoices[0].val+secondChoices[1].val, firstChoices[1].val+secondChoices[1].val);
			}
			else {
				additionalCost=firstChoices[0].val+secondChoices[0].val;
			}
			ans=Math.min(plainSuffix[0]+additionalCost, ans);
			System.out.println(ans);
			
		}
	}
	
	static class Pair implements Comparable<Pair> {
		int val;
		int index;
		public Pair(int value, int index) {
			this.val=value;
			this.index=index;
		}
		public int compareTo(Pair o) {
			return Integer.compare(val, o.val);
		}
	}
	
	static int d(int a, int b) {
		return Math.abs(a-b);
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
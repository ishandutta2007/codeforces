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
4
3 6 6 6
2 7 4 1

1
2
1 1
2 2

 */
public class D {

	static int[][] dp;
	static int[] a, b;
	static int OFFSET=20_000;
	static int[] prefixSums;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			a=fs.readArray(n);
			b=fs.readArray(n);
			dp=new int[n][OFFSET*2];
			prefixSums=new int[n+1];
			for (int i=1; i<=n; i++) prefixSums[i]=prefixSums[i-1]+a[i-1]+b[i-1];
			for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], -1);
			long minBaseAns=Long.MAX_VALUE/2;
			for (int offsetToUse=-OFFSET; offsetToUse<OFFSET; offsetToUse++) {
				minBaseAns=Math.min(minBaseAns, go(offsetToUse, n-1));
			}
			long realAns=0;
			for (int i=0; i<n; i++) {
				realAns+=(a[i]*a[i]+b[i]*b[i])*(long)(n-1);
			}
//			System.out.println("DEBUG: "+go(1, 0));
//			realAns+=2*minBaseAns;
//			System.out.println(realAns+" "+minBaseAns);
			System.out.println(realAns+2*minBaseAns);
		}
	}
	
	//returns min pairwise products
	static int go(int topMinusBottom, int pos) {
		if (topMinusBottom<=-OFFSET || topMinusBottom>=OFFSET)
			return Integer.MAX_VALUE/3;
		boolean shouldBeEven = topMinusBottom%2==0;
		boolean isEven=prefixSums[pos+1]%2==0;
		if (shouldBeEven^isEven) {
			return Integer.MAX_VALUE/3;
		}
		if (pos==0) {
			if (topMinusBottom==a[0]-b[0] || topMinusBottom==b[0]-a[0]) {
				return 0;
			}
			return Integer.MAX_VALUE/3;
		}
		if (dp[pos][topMinusBottom+OFFSET]!=-1) return dp[pos][topMinusBottom+OFFSET];
		
		int minAns=Integer.MAX_VALUE/2;
		{
			//keep same order
			int top=a[pos], bottom=b[pos];
			int currentSum=prefixSums[pos+1];
			int currentTopSum=(currentSum+topMinusBottom)/2;
			int currentBottomSum=currentSum-currentTopSum;
			if (currentTopSum-currentBottomSum!=topMinusBottom) throw null;
			int nextTopSum=currentTopSum-top;
			int nextBottomSum=currentBottomSum-bottom;
			int cost=go(nextTopSum-nextBottomSum, pos-1) + top*nextTopSum+bottom*nextBottomSum;
			minAns=Math.min(minAns, cost);
		}
		{
			//b goes on top
			int top=b[pos], bottom=a[pos];
			int currentSum=prefixSums[pos+1];
			int currentTopSum=(currentSum+topMinusBottom)/2;
			int currentBottomSum=currentSum-currentTopSum;
			if (currentTopSum-currentBottomSum!=topMinusBottom) throw null;
			int nextTopSum=currentTopSum-top;
			int nextBottomSum=currentBottomSum-bottom;
			int cost=go(nextTopSum-nextBottomSum, pos-1) + top*nextTopSum+bottom*nextBottomSum;
			minAns=Math.min(minAns, cost);
		}
		
		return dp[pos][topMinusBottom+OFFSET]=minAns;
		
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
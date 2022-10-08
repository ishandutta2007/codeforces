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

Brute force what stays alive

dp2 on 3s -> max number of 3s
we have an l and an r
      
      dp2[whereWeAre] -> nextThingWeKeep (equal to me)
 X X X ...... X  ,,,,, X X 

DP[l][r] = minLengthAfter, and what it is
//do this in n^2 by brute forcing the start

Then use the DP to find the answer

1
7
1 2 3 2 1 3 3

12
1 5 2 3 3 3 4 4 4 4 3 3

6
1 1 1 2 2 2

X X X X X B Y Y Z Z B B

 */
public class DoodleYankey2 {

	static boolean[][] canDelete;
	static int[] dp;
	static int n;
	static int[] a;
	
	static int[][] prefixSumsFor;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			n=fs.nextInt();
			a=fs.readArray(n);
			dp=new int[n];
			Arrays.fill(dp, -1);
			for (int i=0; i<n; i++) a[i]--;
			prefixSumsFor=new int[n][n+1];
			for (int i=1; i<=n; i++) {
				for (int val=0; val<n; val++) {
					prefixSumsFor[val][i]=prefixSumsFor[val][i-1]+(a[i-1]==val?1:0);
				}
			}
			precomp();
			long best=0;
			for (int start=0; start<n; start++) {
				if (start==0 || canDelete[0][start-1]) {
					best=Math.max(best, go(start));
				}
			}
			System.out.println(best);
			
		}
		out.close();
	}
	
	
	static void precomp() {
		canDelete=new boolean[n][n];
		for (int l=0; l<n; l++) {
			int mode=a[l];
			int count=1;
			canDelete[l][l]=count==0;
			for (int r=l+1; r<n; r++) {
				if (a[r]!=mode) {
					count--;
				}
				else {
					count++;
				}
				if (count<0) {
					count=1;
					mode=a[r];
				}
				int realCount=prefixSumsFor[mode][r+1]-prefixSumsFor[mode][l];
				if ((r-l)%2==1 && realCount*2<=(r-l+1)) {
					canDelete[l][r]=true;
				}
			}
		}
	}
	
	static int go(int at) {
		//brute force next
		if (at==n-1) {
			return 1;
		}
		if (dp[at]!=-1) return dp[at];
		int best=Integer.MIN_VALUE/2;
		if (canDelete[at+1][n-1]) best=1;
		for (int next=at+1; next<n; next+=2) {
			if (a[next]!=a[at]) continue;
			if (next==at+1 || canDelete[at+1][next-1]) {
				best=Math.max(best, 1+go(next));
			}
		}
		return dp[at]=best;
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
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

DP[index1][prefixMatch] = minCost,nways



Find the times it occurs

We need to pick at least one of each

1
aaaaa
aa
 */
public class G {


	static Pair[] dp;
	static char[] big;
	static char[] small;
	static ArrayList<Integer> occs=new ArrayList<>();
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			big=fs.next().toCharArray();
			small=fs.next().toCharArray();
			// dp=new Pair[big.length+1][small.length+1][big.length+1];
			occs=new ArrayList<>();
			outer: for (int i=0; i<big.length; i++) {
				for (int j=0; j<small.length; j++) {
					if (i+j>=big.length || big[i+j]!=small[j]) continue outer;
				}
				occs.add(i);
			}
			dp=new Pair[big.length+1];
			Pair ans=go(0);
			out.println(ans.minMoves+" "+ans.nWays%mod);
			
		}
		out.close();
	}
	
	//going to have to speed this up by doing it iteratively... :(
	static Pair go(int atIndex) {
		if (dp[atIndex]!=null) return dp[atIndex];
		if (atIndex==occs.size()) return new Pair(0, 1);
		//otherwise pick someone to lose
		Pair best=null;
		for (int toKill=atIndex; toKill<occs.size(); toKill++) {
			int curPos=occs.get(atIndex), next=occs.get(toKill);

			//killing next wouldn't help us
			if (Math.abs(next-curPos)>=small.length) continue;

			//otherwise kill this
			int firstNotAlive=toKill+1;
			while (firstNotAlive<occs.size() && occs.get(firstNotAlive)-next<small.length) firstNotAlive++;
			Pair future=go(firstNotAlive);
			best=combine(best, new Pair(future.minMoves+1, future.nWays));
		}
		// System.out.println("Go at "+atIndex+" returning "+best);
		return dp[atIndex]=best;
	}

	static final Random random=new Random();
	static final int mod=1_000_000_007;

	static class Pair {
		int minMoves;
		long nWays;
		public Pair(int minMoves, long nWays) {
			this.minMoves=minMoves;
			this.nWays=nWays;
		}
		public String toString() {
			return "$"+minMoves+", nWays: "+nWays;
		}
	}

	static Pair combine(Pair a, Pair b) {
		if (a==null) return b;
		if (b==null) return a;
		if (a.minMoves!=b.minMoves) {
			if (a.minMoves<b.minMoves) return a;
			return b;
		}
		return new Pair(a.minMoves, add(a.nWays, b.nWays));
	}
	
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
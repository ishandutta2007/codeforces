import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.StringTokenizer;
/*

- All primes stay the same.

The only lower bounds we care about are factors of at least one number
For some L, what's the smallest L we can get?

3 3    5   5

How many prime factors in 5 million?

at worst, there are 7 prime factors
2^7 ish factors


most factors: 390

For some number n, if you split it into pieces, what's the min size
of the biggest piece if all pieces are >=X?


Instead, we brute force R, what's the biggest legal L?
dp[number] = best that number can do, or -oo if impossible
Transition => try all factors smaller than R?

What parts of the table change when we change R?
Anything smaller than old R stays the same.
new R will change from something -> R
For all multiples of R in increasing order, we'll recalc in O(1)

We'll have a working table, 


1
5 4
2 4 2 4 2
 */
public class EXPLOSIONS {

	static boolean debug=false;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), max=fs.nextInt();
			boolean[] inInput=new boolean[max+1];
			for (int i=0; i<n; i++) inInput[fs.nextInt()]=true;
			
			int[] dp=new int[max+1];
			Arrays.fill(dp, -1_000_000_000);
			PriorityQueue<State> pq=new PriorityQueue<>();
			for (int i=0; i<=max; i++) {
				if (inInput[i]) {
					State toAdd=new State(i, dp[i]);
					pq.add(toAdd);
					if (debug) System.out.println(toAdd);
				}
			}
			if (debug) System.out.println("pq size "+pq.size());
			
			long best=Long.MAX_VALUE;
			for (int r=1; r<=max; r++) {
				if (debug) System.out.println("Processing "+r);
				//TODO: update DP
				dp[r]=r;
				if (inInput[r]) {
					State toAdd=new State(r, dp[r]);
					pq.add(toAdd);
					if (debug) System.out.println("  Added to pq "+toAdd);
				}
				for (int multiple=r*2; multiple<=max; multiple+=r) {
					// each thing can either stay the same,
					// or get better when it uses r
					int newVal=Math.min(dp[r], dp[multiple/r]);
					if (newVal>dp[multiple]) {
						dp[multiple]=newVal;
						if (inInput[multiple]) {
							State toAdd=new State(multiple, dp[multiple]);
							pq.add(toAdd);
							if (debug) System.out.println("  Added to pq "+toAdd);
						}
					}
				}
				
				//TODO: recalc answer and update best
				
				//remove expired states
				while (true) {
					State peek=pq.peek();
					if (peek.val==dp[peek.num]) {
						break;
					}
					pq.remove();
					if (debug) System.out.println("  Removing from pq "+pq.size()+" "+peek);
				}
				if (debug) System.out.println("For R "+r+" got "+pq.peek().val);
				best=Math.min(best, r-pq.peek().val);
			}
			out.println(best);
		}
		out.close();
	}
	
	static class State implements Comparable<State> {
		int num;
		int val;
		public State(int num, int val) {
			this.num=num;
			this.val=val;
		}
		public int compareTo(State o) {
			return Integer.compare(val, o.val);
		}
		public String toString() {
			return "dp["+num+"] = "+val;
		}
	}
	
	static int nFactors(int x) {
		int ans=0;
		for (int i=1; i*i<=x; i++) {
			if (i*i==x) {
				ans++;
			}
			else if (x%i==0) ans+=2;
		}
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
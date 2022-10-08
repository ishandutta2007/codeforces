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

2 4 2 4
1 1 0
+ + 
+ +
  +
0 1 1
  
  
  
3 5

1110
+++
+++
+++
0111


Swap in a 0 or a 1, 0 -> stay the same forever, 1-> continue to get smaller

3 => for 3 turns, subtract 1 from the next 3

last element:
0 or 1 if initially a 0
else n


We can count the number of 1s in total:
#1s = sum/n

last is a 1, 3 1s in total
2 4 2 4
  + + +

last is ? 2 1s in total
2 3 1 This is what it looked like before


1
4
2 4 2 4
 */
public class D {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			BIT deltas=new BIT(n);
			int[] a=fs.readArray(n);
			long sum=0;
			for (int i:a) sum+=i;
			if (sum%n!=0) throw null;
			int nOnes=(int) (sum/n);
			for (int i=0; i<n; i++) {
				int prev=i==0?0:a[i-1];
				int delta=a[i]-prev;
				deltas.update(i, delta);
			}
			int[] ans=new int[n];
			for (int i=n-1; i>0; i--) {
				int last=deltas.query(0, i);
				//remove the last query
				int nZeros=i+1-nOnes;
				deltas.update(nZeros, -1);
				if (last==i+1) {
					//ends in a 1
					ans[i]=1;
					nOnes--;
				}
				else {
					ans[i]=0;
				}
			}
			ans[0]=nOnes;
			for (int i=0; i<n; i++) out.print(ans[i]+" ");
			out.println();
		}
		out.close();
	}
	

	//range update point query
	//bit stores delta
	static class BIT {
		int n, tree[];
		
		public BIT(int N) {
			n = N;  tree = new int[N + 1];
		}
	
		void update(int i, int val) {
			for (i++; i <= n; i += i & -i) tree[i] += val;
		}
		
		int read(int i) {
			int sum = 0;
			for (i++; i > 0; i -= i & -i) sum += tree[i];
			return sum;
		}
		
		// query sum of [l, r] inclusive
		int query(int l, int r) { return read(r) - read(l - 1); }
		
		// if the BIT is a freq array, returns the index of the
		// kth item (0-indexed), or n if there are <= k items.
		int getKth(int k) {
			if (k < 0) return -1;
			int i = 0;
			for (int pw = Integer.highestOneBit(n); pw > 0; pw >>= 1)
				if (i + pw <= n && tree[i + pw] <= k) k -= tree[i += pw];
			return i;
		}
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
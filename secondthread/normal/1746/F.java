import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

/*
for any particicular number we can see in O(1) how many times it's in the range


Freq of every element
We have a frequency array
Are all nonzero indecies at multiples of k?

if k > sqrt, easy
k < sqrt -> increment count of all factors

runtime is 
n/blockSize * n * nFactors

What if we 


 */
public class F {

	static int NBITS=30;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt(), q=fs.nextInt();
		int[] a=fs.readArray(n);
		Query[] queries=new Query[q];
		for (int qq=0; qq<q; qq++) {
			int type=fs.nextInt();
			if (type==1) {
				queries[qq]=new Query(fs.nextInt(), fs.nextInt());
			}
			else {
				queries[qq]=new Query(fs.nextInt(), fs.nextInt(),fs.nextInt());
			}
		}
		TreeSet<Integer> ts=new TreeSet<>();
		for (int i:a) ts.add(i);
		for (Query qq:queries)
			ts.add(qq.setTo);
		HashMap<Integer, Integer> map=new HashMap<>();
		for (int i:ts) map.put(i, map.size());
		for (int i=0; i<a.length; i++) a[i]=map.get(a[i]);
		for (Query qq:queries)
			if (qq.type==1)
				qq.setTo=map.get(qq.setTo);

		boolean[][] numberInGroup=new boolean[map.size()][NBITS];
		for (int i=0; i<numberInGroup.length; i++)
			for (int j=0; j<NBITS; j++) numberInGroup[i][j]=random.nextBoolean();
		BIT[] bits=new BIT[NBITS];
		for (int i=0; i<bits.length; i++) bits[i]=new BIT(n);
		for (int i=0; i<n; i++) {
			add(a[i], i, numberInGroup, bits);
		}
		for (Query qq:queries) {
			if (qq.type==1) {
				//update
				int index=qq.index;
				int newVal=qq.setTo;
				remove(a[index], index, numberInGroup, bits);
				a[index]=newVal;
				add(a[index], index, numberInGroup, bits);
			}
			else {
				//query
				int l=qq.l, r=qq.r, k=qq.k;
				boolean works=true;
				for (int i=0; i<NBITS; i++) {
					int nThings=bits[i].query(l, r);
					if (nThings%k!=0) {
						works=false;
					}
				}
				out.println(works?"YES":"NO");
			}
		}

		out.close();
	}

	static void add(int value, int index, boolean[][] numberInGroup, BIT[] bits) {
		for (int i=0; i<NBITS; i++) {
			if (numberInGroup[value][i]) {
				bits[i].update(index, 1);
			}
		}

	}
	static void remove(int value, int index, boolean[][] numberInGroup, BIT[] bits) {
		for (int i=0; i<NBITS; i++) {
			if (numberInGroup[value][i]) {
				bits[i].update(index, -1);
			}
		}
	}

	static class Query {
		int type;
		int index;
		int setTo;
		int l, r, k;
		
		public Query(int index, int setTo) {
			this.index=index-1;
			this.setTo=setTo;
			this.type=1;
		}

		public Query(int l, int r, int k) {
			this.type=2;
			this.l=l-1;
			this.r=r-1;
			this.k=k;
		}
	}

	static final Random random=new Random();
	static final int mod=1_000_000_007;

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
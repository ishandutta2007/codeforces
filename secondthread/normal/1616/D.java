import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;

/*


1
10
2 4 2 4 2 4 2 4 2 4

1
2
-1 0
0

1
2
1 -1
0

1
2
-1 1
0
 */
public class D {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			int x=fs.nextInt();
			for (int i=0; i<n; i++) a[i]-=x;
			
			long[] cs=new long[n+1];
			for (int i=1; i<=n; i++) cs[i]=cs[i-1]+a[i-1];
			
			//dp[i] == if we start at i, how many things to we need to delete
			int[] dp=new int[n];
			SegTree st=new SegTree(0, n-1);
			int nextEnd=-1;
			TreeMap<Long, Integer> map=new TreeMap<>();
			for (int i=0; i<n; i++) {
				//find the next required end
				//nextEnd=max(nextEnd, last index with prefix sum greater than us
				
				if (map.higherKey(cs[i+1])!=null) {
					nextEnd=Math.max(map.higherEntry(cs[i+1]).getValue(), nextEnd);
				}
				
				map.put(cs[i], i);
				while (map.lowerKey(cs[i])!=null) {
					map.remove(map.lowerKey(cs[i]));
				}
				
				if (nextEnd==-1) {
					st.update(i, 0);
				}
				else {
					//next skip is somewhere in [nextEnd...i]
					int nextBest=st.query(nextEnd-1, i-1);
					int myBest=nextBest+1;
					dp[i]=myBest;
					st.update(i, myBest);	
				}
			}
//			System.out.println(Arrays.toString(dp));
			System.out.println(n-dp[n-1]);
		}
	}
	
	static class SegTree {
		int leftmost, rightmost;
		int rangeMin;
		SegTree lChild, rChild;
		public SegTree(int leftmost, int rightmost) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
			if (leftmost!=rightmost) {
				int mid=(leftmost+rightmost)/2;
				lChild=new SegTree(leftmost, mid);
				rChild=new SegTree(mid+1, rightmost);
			}
		}
		void recalc() {
			if (leftmost==rightmost) return;
			rangeMin=Math.min(lChild.rangeMin, rChild.rangeMin);
		}
		void update(int index, int setTo) {
			if (leftmost==rightmost) rangeMin=setTo;
			else {
				if (index<=lChild.rightmost) lChild.update(index, setTo);
				else rChild.update(index, setTo);
				recalc();
			}
		}
		int query(int l, int r) {
			if (l<=leftmost && r>=rightmost) {
				return rangeMin;
			}
			if (l>rightmost || r<leftmost) {
				return Integer.MAX_VALUE/2;
			}
			return Math.min(lChild.query(l, r), rChild.query(l, r));
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
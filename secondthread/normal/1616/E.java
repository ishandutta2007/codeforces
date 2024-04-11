import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

/*

1
2
ba
ba


1
3
rll
rrr
 */
public class E {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[] a=fs.next().toCharArray(), b=fs.next().toCharArray();
//			int[][] indexOfNext=new int[26][n];
//			int[] lastSeen=new int[26];
//			Arrays.fill(lastSeen, n);
			ArrayDeque<Integer>[] stacks=new ArrayDeque[26];
			for (int i=0; i<26; i++) stacks[i]=new ArrayDeque<>();
			for (int i=n-1; i>=0; i--) {
//				lastSeen[a[i]-'a']=i;
//				for (int j=0; j<26; j++) indexOfNext[j][i]=lastSeen[j];
				stacks[a[i]-'a'].addFirst(i);
			}
			
			long ans=Long.MAX_VALUE;
			long takenAlready=0;
			BIT left=new BIT(n);
			for (int i=0; i<n; i++) left.update(i, 1);
			
			for (char c:b) {
//				System.out.println("Processing "+c);
				//can beat now
				for (int beatWith=-1+(c-'a'); beatWith>=0; beatWith--) {
					if (stacks[beatWith].isEmpty()) continue;
					int nextInd=stacks[beatWith].peekFirst();
					int realPos=left.query(0, nextInd-1);
//					System.out.println("Trying to beat... "+nextInd+" "+realPos);
					ans=Math.min(ans, takenAlready+realPos);
				}
				
//				System.out.println("Trying to tie");
				//can tie now
				if (stacks[c-'a'].isEmpty()) break;
				int toMove=stacks[c-'a'].removeFirst();
				left.update(toMove, -1);
				takenAlready+=left.query(0, toMove-1);
//				System.out.println("Ans: "+ans);
			}
			
			if (ans==Long.MAX_VALUE) {
				System.out.println(-1);
			}
			else {
				System.out.println(ans);
			}
		}
	}
	
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
		int query(int l, int r) {
			if (l>r) return 0;
			return read(r) - read(l - 1); }
		
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
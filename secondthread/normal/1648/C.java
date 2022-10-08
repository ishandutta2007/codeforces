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

 */
public class C {

	
	public static void main(String[] args) {
		precompFacts();
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
//		int T=fs.nextInt();
		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int m=fs.nextInt();
			int[] a=fs.readArray(n), b=fs.readArray(m);
			ruffleSort(a);
			BIT bit=new BIT(200_001);
			for (int i:a) {
				bit.update(i, 1);
			}
			long divideBy=1;
			for (int i=0; i<bit.n; i++) {
				divideBy=mul(divideBy, factorials[(int) bit.query(i, i)]);
			}
			long waysToTie=1;
			long waysToWin=0;
			for (int pos=0; pos<Math.min(n, m); pos++) {
				long futurePlaceWays=factorials[n-pos-1];
				waysToWin=add(waysToWin, mul(waysToTie, mul(bit.query(0, b[pos]-1), futurePlaceWays)));
				waysToTie=mul(waysToTie, bit.query(b[pos], b[pos]));
				bit.update(b[pos], -1);
			}
			if (n<m) {
				waysToWin=add(waysToWin, waysToTie);
			}
			
			
			System.out.println(mul(waysToWin, exp(divideBy, mod-2)));
		}
	}
	
	static class BIT {
		int n;
		long tree[];
		
		public BIT(int N) {
			n = N;  tree = new long[N + 1];
		}

		void update(int i, long val) {
			for (i++; i <= n; i += i & -i) tree[i] += val;
		}
		
		long read(int i) {
			long sum = 0;
			for (i++; i > 0; i -= i & -i) sum += tree[i];
			return sum;
		}
		
		// query sum of [l, r] inclusive
		long query(int l, int r) { return read(r) - read(l - 1); }
		
	}
	
	static final Random random=new Random();
	static final int mod=998244353;
	
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
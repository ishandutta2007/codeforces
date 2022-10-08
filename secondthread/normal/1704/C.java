import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Random;
import java.util.StringTokenizer;
/*




....XXXX.XXXX...
..|XXXXXXXXX|...
Gap sizes from biggest to smallest
if the biggest gap size == 1 of size==2, save that
Save size-1 over 2 turns.
All other gap sizes decrease by 2.


1
10 3
3 6 8
 */
public class C {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
//		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=fs.nextInt();
			int[] a=fs.readArray(k);
			ruffleSort(a);
			int[] gaps=new int[k];
			for (int i=0; i<k; i++) {
				if (i==0) {
					gaps[i]=a[0]-(a[k-1]-n)-1;
				}
				else {
					gaps[i]=a[i]-a[i-1]-1;
				}
			}
			ruffleSort(gaps);
//			System.out.println(Arrays.toString(gaps));
			int nSave=0;
			int nSub=0;
			a=gaps;
			for (int i=k-1; i>=0; i--) {
				a[i]-=nSub;
				if (a[i]<=0) {
					continue;
				}
				if (a[i]==1 || a[i]==2) {
					nSub+=2;
					nSave++;
					continue;
				}
				nSave+=a[i]-1;
				nSub+=4;
			}
			out.println(n-nSave);
		}
		out.close();
	}
	
//	static int nInfected;
//	static boolean possible(int[] a, int n, int turns) {
//		int lastHit=a[a.length-1]-n + turns;
//		nInfected=0;
//		int nBorders=0;
//		for (int i=0; i<a.length; i++) {
//			int l=a[i]-turns, r=a[i]+turns;
//			l=Math.max(lastHit+1, l);
//			if (l>lastHit+1) {
//				nBorders++;
//			}
//		}
//		
//		return nBorders<=turns+1;
//	}
	
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
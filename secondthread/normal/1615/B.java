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
public class B {

	static int[][] bitLessThan=new int[21][300_000];
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		precomp();
		
		for (int tt=0; tt<T; tt++) {
			int l=fs.nextInt(), r=fs.nextInt();
//			if (Integer.highestOneBit(l)==Integer.highestOneBit(r)) System.out.println(0);
//			else {
//				int bit=Integer.highestOneBit(r);
//				
//			}
			int ans=r-l+1;
			for (int bit=0; bit<=20; bit++) {
				int keep=nLessThanXWithBit(r+1, bit)-nLessThanXWithBit(l, bit);
				ans=Math.min(ans, (r-l+1)-keep);
			}
			System.out.println(ans);
		}
	}
	static void precomp() {
		for (int bit=0; bit<21; bit++) {
			int count=0;
			for (int i=0; i<300_000; i++) {
				bitLessThan[bit][i]=count;
				if ((i&(1<<bit))!=0) count++;
			}
		}
	}
	
	static int nLessThanXWithBit(int x, int bit) {
		return bitLessThan[bit][x];
	}
	static int nLessThanXWithBit(int x, int bit, int offset) {
		if (Integer.bitCount(x)!=1) throw null;
		if (offset>1<<bit || x>1<<bit) {
			return x/2;
		}
		return 0;
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
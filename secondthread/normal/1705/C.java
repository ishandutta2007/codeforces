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
1
4 3 3
mark
1 4
5 7
3 8
1
10
12
1234 5678 90
mark mark mar rkmark
 */
public class C2 {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
//		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), nCopies=fs.nextInt(), nQ=fs.nextInt();
			char[] original=fs.next().toCharArray();
			long[] copyStart=new long[nCopies], copyEnd=new long[nCopies];
			long[] newStart=new long[nCopies];
			long len=n;
			for (int i=0; i<nCopies; i++) {
				copyStart[i]=fs.nextLong()-1;
				copyEnd[i]=fs.nextLong()-1;
				newStart[i]=len;
				len+=copyEnd[i]-copyStart[i]+1;
//				System.out.println("start "+newStart[i]+" "+copyStart[i]);
			}
			Q[] qs=new Q[nQ];
			for (int i=0; i<nQ; i++) {
				qs[i]=new Q(fs.nextLong()-1);
			}
			
			for (Q q:qs) {
				for (int c=nCopies-1; c>=0; c--) {
//					System.out.println("At c: "+c+" q.at: "+q.at);
					if (q.at>=newStart[c]) {
						q.at-=(newStart[c]-copyStart[c]);
					}
				}
				System.out.println(original[(int) q.at]);
			}
		}
		out.close();
	}
	
	static class Q implements Comparable<Q>{
		long at;
		char ans;
		public Q(long at) {
			this.at=at;
		}
		public int compareTo(Q o) {
			return Long.compare(at, o.at);
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
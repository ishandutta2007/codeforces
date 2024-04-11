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
public class A {
	
	static PrintWriter out;

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			
			int n=fs.nextInt();
			int make=fs.nextInt();
//			int n=T;
//			int make=tt;
			
			if (make+1==n && n==4) {
				out.println(-1);
				continue;
			}
			boolean[] used=new boolean[n];
			ArrayList<Pair> printed=new ArrayList<>();
			if (make+1==n) {
				printed.add(print(n-1, (n-2)));
				printed.add(print(1, 3));
				printed.add(print(oppisite(n, 3), 0));
			}
			else if (make!=0) {
				printed.add(print(n-1, make));
				printed.add(print(0, oppisite(n, make)));
			}
			for (Pair p:printed) {
				used[p.a]=used[p.b]=true;
			}
			for (int i=0; i<n/2; i++) {
				if (used[i]) continue;
//				out.println(i+" "+oppisite(n, i));
				printed.add(print(i, oppisite(n, i)));
				used[i]=true;
				used[oppisite(n, i)]=true;
			}
			
			int realSum=0;
			int[] realUsedCount=new int[n];
			for (Pair i:printed) {
				realUsedCount[i.a]++;
				realUsedCount[i.b]++;
				realSum+=i.a&i.b;
			}
//			System.out.println(n+" "+make);
//			for (int i:realUsedCount) if (i!=1) {
//				System.out.println(Arrays.toString(realUsedCount));
//				System.out.println("Got count: "+i);
//				throw null;
//			}
//			if (realSum!=make) {
//				System.out.println("\nExpected "+make+" got "+realSum);
//				System.out.println(n+" "+make);
//				throw null;
//			}
			
		}
		out.close();
	}
	static int oppisite(int n, int x) {
		return (n-1)^x;
	}
	
	static Pair print(int a, int b) {
		out.println(a+" "+b);
		return new Pair(a, b);
	}
	
	static class Pair {
		int a, b;
		public Pair(int a, int b) {
			this.a=a;
			this.b=b;
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
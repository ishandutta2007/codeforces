import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
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

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		// int T=fs.nextInt();
		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int m=fs.nextInt();
			char[] a=fs.next().toCharArray(), b=fs.next().toCharArray();
			int aLen=0;
			boolean aContains=false;
			for (char c:a) if (c!='*') aLen++; else aContains=true;
			if (!aContains) {
				boolean eq=n==m;
				if (eq) {
					for (int i=0; i<n; i++) eq&=a[i]==b[i];
				}
				out.println(eq?"YES":"NO");
				continue;
			}
			if (aLen>m) {
				out.println("NO");
				continue;
			}
			int prefix=0;
			int suffix=0;
			for (int i=0; i<a.length; i++) {
				if (a[i]=='*') break;
				if (a[i]!=b[i]) break;
				prefix++;
			}
			for (int i=0; i<a.length; i++) {
				if (a[n-1-i]=='*') break;
				if (a[n-i-1]!=b[m-1-i]) break;
				suffix++;
			}
			if (prefix+suffix==aLen) {
				out.println("YES");
			}
			else {
				out.println("NO");
			}
		}
		out.close();
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

		public FastScanner() {
			try {
				String filename=this.getClass().getEnclosingClass().getSimpleName();
				br=new BufferedReader(new FileReader(new File(filename+".in")));
			}
			catch (Exception e) {
				System.err.println("Using standard input instead.");
				br=new BufferedReader(new InputStreamReader(System.in));
			}
		}
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
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

22 3 22

 X X X X X X
  | . . | .
  5 8 9 8 5
 
 

 | | | |
 
 
10 | 10 + 6 + 3 + 1




5 0
1 2 2 4 5
 | . | |
 4   6 4
5 4 3 2 1

 *
 *
 */
public class C {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt(), nQ=fs.nextInt();
		int[] a=fs.readArray(n);
		boolean[] isFlip=new boolean[n];
		for (int i=0; i<n-1; i++) isFlip[i]=a[i]!=a[i+1];
		long[] valueOf=new long[n-1];
		for (int i=0; i<n-1; i++) {
			valueOf[i]=(i+1)*(long)(n-1-i);
		}
		long ans=0;
		for (int i=0; i<n-1; i++)
			ans+=valueOf[i]*(isFlip[i]?1:0);
		long offset=(n+1)*(long)n/2;
		for (int qq=0; qq<nQ; qq++) {
			int index=fs.nextInt()-1, setTo=fs.nextInt();
			if (index!=0)
				ans-=v(valueOf, isFlip, index-1);
			if (index!=n-1)
				ans-=v(valueOf, isFlip, index);
			
			a[index]=setTo;
			if (index!=0) isFlip[index-1] = a[index-1]!=a[index];
			if (index!=n-1) isFlip[index] = a[index]!=a[index+1];
			
			if (index!=0)
				ans+=v(valueOf, isFlip, index-1);
			if (index!=n-1)
				ans+=v(valueOf, isFlip, index);
			out.println(ans+offset);
		}
		out.close();
	}
	static long v(long[] valueOf, boolean[] isFlip, int index) {
		return valueOf[index]*(long)(isFlip[index]?1:0);
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
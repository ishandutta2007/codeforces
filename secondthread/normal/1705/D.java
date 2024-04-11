import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

public class D {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
//		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[] a=fs.next().toCharArray(),b=fs.next().toCharArray();
			if (a[0]!=b[0]) {
				out.println(-1);
				continue;
			}
			int[][] ca=compress(a), cb=compress(b);
			if (ca.length!=cb.length) {
				out.println(-1);
				continue;
			}
			long ans=0;
			for (int i=0; i<ca.length; i++) {
				ans+=Math.abs(ca[i][0]-cb[i][0]) + Math.abs(ca[i][1]-cb[i][1]);
			}
			out.println(ans/2);
			
		}
		out.close();
	}
	static int[][] compress(char[] c) {
		ArrayList<Integer> lengths=new ArrayList<>();
		int current=0;
		int at='?';
		for (char cc:c) {
			if (cc!=at) {
				lengths.add(current);
				at=cc;
				current=1;
			}
			else {
				current++;
			}
		}
		lengths.add(current);
		
		
		//TODO: convert to 2D array
		int len=0;
		int[][] ans=new int[lengths.size()][];
		for (int i=0; i<ans.length; i++) {
			ans[i]=new int[] {len, len+lengths.get(i)-1};
			len+=lengths.get(i);
		}
		return ans;
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
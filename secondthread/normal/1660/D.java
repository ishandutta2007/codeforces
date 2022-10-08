import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

/*
5
4
1 2 -1 2
3
1 1 -2
5
2 0 -2 2 -1
3
-2 -1 -1
3
-1 -2 -2


1
3
-1 -2 -2
 */
public class D {

	
	static int[][] cs;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			cs=new int[5][n+1];
			for (int val=0; val<5; val++)
				for (int i=1; i<=n; i++)
					cs[val][i]=cs[val][i-1]+(a[i-1]==val-2?1:0);
//			for (int i=0; i<5;i++) {
//				System.out.println(Arrays.toString(cs[i]));
//			}
			TreeSet<Integer> negIndecies=new TreeSet<>();
			for (int i=0; i<n; i++) if (a[i]<0) negIndecies.add(i);
			TreeSet<Integer> zeroIndecies=new TreeSet<>();
			for (int i=0; i<n; i++) if (a[i]==0) zeroIndecies.add(i);
			negIndecies.add(-1);
			zeroIndecies.add(n);
			int bestL=0, bestR=-1;
			for (int l=0; l<n; l++) {
				int nextzero=zeroIndecies.ceiling(l);
				if (eval(l, nextzero-1)>eval(bestL, bestR)) {
					bestL=l;
					bestR=nextzero-1;
				}
				int beforeNeg=negIndecies.floor(nextzero);
				if (beforeNeg>l) {
					if (eval(l, beforeNeg-1)>eval(bestL, bestR)) {
						bestL=l;
						bestR=beforeNeg-1;
					}
				}
			}
			System.out.println(bestL+" "+(n-bestR-1));
		}
	}
	
	//if negative or 0 return -1
	//if 1 return 0
	//else return power of 2
	static int eval(int l, int r) {
		if (r<l) return 0;
		//check if negitive or 0
		if (cs[2][r+1]-cs[2][l]>0) return -1;
		if ((cs[0][r+1]-cs[0][l]+cs[1][r+1]-cs[1][l])%2==1) return -1;
		int res=cs[4][r+1]-cs[4][l]+cs[0][r+1]-cs[0][l];
		return res;
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
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

TODO: also in the problem description say that you need to determine how to do so

// need to sort each row
Look at pairwise differences, when we have an adjacent inversion, we need to swap one of them



1
1 7
1 2 4 3 3 3 5

 */
public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int h=fs.nextInt(), w=fs.nextInt();
			int[][] grid=new int[h][];
			for (int y=0; y<h; y++) grid[y]=fs.readArray(w);

			int inversionL=-1, inversionR=-1;
			for (int y=0; y<h; y++) {
				for (int x=0; x+1<w; x++) {
					if (grid[y][x]>grid[y][x+1]) {
						inversionL=x;
						inversionR=x+1;
					}
				}
			}
			if (inversionL==-1) {
				out.println("1 1");
				continue;
			}
//			System.out.println(inversionL+" "+inversionR);
			
			// otherwise we have an inversion
			// check if keeping l works
			{
				int r=inversionR;
				for (int y=0; y<grid.length; y++)
					for (int x=r+1; x<grid[0].length; x++)
						if (grid[y][x]<grid[y][inversionL])
							r=x;
				swap(inversionL, r, grid);
				if (check(grid)) {
					out.println((inversionL+1)+" "+(r+1));
					continue;
				}
				swap(inversionL, r, grid);
			}
			{
				int l=inversionL;
				for (int y=0; y<grid.length; y++)
					for (int x=l-1; x>=0; x--)
						if (grid[y][x]>grid[y][inversionR])
							l=x;
				swap(l, inversionR, grid);
				if (check(grid)) {
					out.println(l+1+" "+(inversionR+1));
					continue;
				}
			}
			out.println(-1);

		}
		out.close();
	}

	static void swap(int l, int r, int[][] grid) {
		for (int y=0; y<grid.length; y++) {
			int temp=grid[y][l];
			grid[y][l]=grid[y][r];
			grid[y][r]=temp;
		}
	}

	static boolean check(int[][] grid) {
//		System.out.println("Checking "+Arrays.toString(grid[0]));
		for (int[] a:grid) {
			for (int i=0; i<a.length-1; i++) {
				if (a[i+1]<a[i]) return false;
			}
		}
		return true;
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
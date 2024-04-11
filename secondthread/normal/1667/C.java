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

X-------
--X-----
-.--X---
-.----X-
-.-.----
-.-.----
-.-.-.--
-.-.-.--


8
X-------
--X-----
-X--X---
-.----X-
-.-.----
-.-X----
-.-.-F--
-.-.-F-F

10
X.........
..X.......
.X..X.....
......X...
........X.
..........
...X......
.....X....
..........
..........

9
X--------
--X------
----X----
------X--
-.-.----.
-.-.---.-
-.-.-.--.
-.-.-.---
-.-.-.-.-

9
X--------
--X------
----X----
------X--
-X-.----.
-.-X---.-
-.-.-X--.
-.-.-.---
-.-.-.-.-



 */
public class CSol2 {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt();
		if (n==1) {
			System.out.println(1);
			System.out.println("1 1");
			return;
		}
		if (n==2) {
			System.out.println(1);
			System.out.println("1 1");
			return;
		}
		if (n==3) {
			System.out.println(2);
			System.out.println("1 1");
			System.out.println("1 2");
			return;
		}
/*
10
.........X
........X.
..........
.......X..
.....X....
..........
....X.....
..X.......
..........
.X........
 */
		ArrayList<Integer> xs=new ArrayList<>(), ys=new ArrayList<>();
		int x=1;
		int y=n-1;
		boolean jumpUp=true;
		while (true) {
			xs.add(Math.min(x, n-1));
			ys.add(Math.max(y, 0));
			x++;
			y--;
			if (jumpUp) y--;
			else x++;
			jumpUp^=true;
			if (x>=n && y<0) break;
		}
		out.println(xs.size());
		for (int i=0;i<xs.size(); i++) {
			out.println(ys.get(i)+1+" "+(xs.get(i)+1));
		}
		out.close();
		
		
	}
	
	static boolean[][] getRand(int n, int toPlace) {
		boolean[][] grid=new boolean[n][n];
		while (toPlace>0) {
			int x=random.nextInt(n), y=random.nextInt(n);
			if (grid[x][y]) continue;
			grid[x][y]=true;
			toPlace--;
		}
		return grid;
	}
	
	static boolean works(boolean[][] grid,int n) {
//		boolean[][] covered=new boolean[n][n];
		for (int x=0; x<n; x++) {
			next: for (int y=0; y<n; y++) {
				for (int xx=0; xx<n; xx++) {
					if (grid[xx][y]) continue next;
				}
				for (int yy=0; yy<n; yy++) {
					if (grid[x][yy]) continue next;
				}
				for (int diag=-Math.min(x, y); x+diag<n && y+diag<n; diag++) {
					if (grid[x+diag][y+diag]) continue next;
				}
				return false;
			}
		}
		return true;
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
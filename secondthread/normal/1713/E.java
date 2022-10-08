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
3 3 1 2
1 1 3 1
3 2 3 2
2 3 3 1

3 1 3 2
3 1 3 1
1 2 3 2
2 3 3 1

3 1 1 2
3 1 2 1
3 3 3 3
2 3 2 1

Does order matter? No.

Brute force whether or not we flip the top left
Iterate through column by column on top left
 

.AC
B.E
DF

.BD
A.E
CF.

.AD
B.F
CE.

.BC
A.F
DE.

.AC
B.E
DF.

1000 nodes
A bunch of edges either different or same
we want to lexicalgraphically maximize the number of edges we satisfy

1
3
2 1 2
2 1 2
1 1 2
 */
public class E {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
//		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[][] a=new int[n][];
			for (int i=0; i<n; i++) {
				a[i]=fs.readArray(n);
			}
			//a not a, b not b
			DisjointSet dj=new DisjointSet(n*2);
			for (int i=0; i<n; i++) {
				for (int j=i+1; j<n; j++) {
					if (a[i][j] == a[j][i]) continue;
					if (a[i][j] < a[j][i]) {
						//same
						if (canJoin(i, j, dj)) {
//							System.out.println("Joining "+i+" "+j);
							dj.union(i<<1, j<<1);
							dj.union((i<<1)+1, (j<<1)+1);
						}
					}
					else {
						//opposite
						if (canSeperate(i, j, dj)) {
//							System.out.println("Seperating "+i+" "+j);
							dj.union(i<<1, (j<<1)+1);
							dj.union((i<<1)+1, j<<1);
						}
					}
				}
			}
			for (int i=0; i<n; i++)
				if (dj.find(i<<1) == dj.find((i<<1)+1)) throw null;
			
			
			int[][] ans=new int[n][n];
			for (int i=0; i<n; i++) {
				ans[i][i]=a[i][i];
				for (int j=i+1; j<n; j++) {
					if (a[i][j]==a[j][i]) {
						ans[i][j]=ans[j][i]=a[i][j];
					}
					else {
						//i THINK they're either connected or cut here...
						if (dj.find(i<<1) == dj.find(j<<1)) {
							ans[i][j]=a[i][j];
							ans[j][i]=a[j][i];
						}
						else {
							ans[i][j]=a[j][i];
							ans[j][i]=a[i][j];
						}
					}
				}
			}
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					out.print(ans[i][j]+" ");
				}
				out.println();
			}
		}
		out.close();
	}
	
	static boolean canJoin(int i, int j, DisjointSet dj) {
		if (dj.find(i<<1)==dj.find((j<<1)+1)) {
			return false;
		}
		return true;
	}
	
	static boolean canSeperate(int i, int j, DisjointSet dj) {
		if (dj.find(i<<1)==dj.find(j<<1)) {
			return false;
		}
		return true;
	}
	
	static class DisjointSet {
		int[] s;
		
		public DisjointSet(int n) {
			Arrays.fill(s = new int[n], -1);
		}
		
		public int find(int i) {
			return s[i] < 0 ? i : (s[i] = find(s[i]));
		}
		
		public boolean union(int a, int b) {
			if ((a = find(a)) == (b = find(b))) return false;
			if(s[a] == s[b]) s[a]--;
			if(s[a] <= s[b]) s[b] = a; 
			else s[a] = b;
			return true;
		}
	}
	
	static int[][] getMin(int[][] a, int[][] b) {
		for (int i=0; i<a.length; i++) {
			for (int j=0; j<a.length; j++) {
				if (a[i][j]!=b[i][i]) {
					if (a[i][j]<b[i][j]) return a;
					return b;
				}
			}
		}
		return a;
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
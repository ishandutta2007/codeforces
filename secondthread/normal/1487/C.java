import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

//Good morning!
/*
0 0 1 -1
  0 -1 1
    0  0
 */
public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			if (n%2==0) {
				//hard
				int[][] grid=new int[n][n];
				for (int i=0; i<n; i+=2) {
					grid[i][i+1]=grid[i+1][i]=0;
					for (int j=i+2; j<n; j+=2) {
						grid[i][j]=1;
						grid[i][j+1]=-1;
						grid[i+1][j]=-1;
						grid[i+1][j+1]=1;
					}
				}
				for (int i=0; i<n; i++) 
					for (int j=i+1; j<n; j++)
						out.print((grid[i][j])+" ");
			}
			else {
				//easy
				for (int i=0; i<n; i++) 
					for (int j=i+1; j<n; j++)
						out.print(((i+j)%2==0?1:-1)+" ");
			}
			out.println();
		}
		out.close();
	}

	// Use this instead of Arrays.sort() on an array of ints. Arrays.sort() is n^2
	// worst case since it uses a version of quicksort. Although this would never
	// actually show up in the real world, in codeforces, people can hack, so
	// this is needed.
	static void ruffleSort(int[] a) {
		//ruffle
		int n=a.length;
		Random r=new Random();
		for (int i=0; i<a.length; i++) {
			int oi=r.nextInt(n), temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
		}
		
		//then sort
		Arrays.sort(a);
	}
	
	// Use this to input code since it is faster than a Scanner
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
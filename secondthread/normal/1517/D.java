import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/*
height == 2, width == 3

2 3 2
1 1
1 1
1 1 1
 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int h=fs.nextInt(), w=fs.nextInt(), k=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		if (k%2==1) {
			for (int y=0; y<h; y++) {
				for (int x=0; x<w; x++) {
					if (x!=0) out.print(" ");
					out.print(-1);
				}
				out.println();
			}
			out.close();
			return;
		}
		k/=2;
		
		int[][] rightCost=new int[w-1][h];
		int[][] downCost=new int[w][h-1];
		for (int y=0; y<h; y++) 
			for (int x=0; x<w-1; x++)
				rightCost[x][y]=fs.nextInt();
		for (int y=0; y<h-1; y++)
			for (int x=0; x<w; x++)
				 downCost[x][y]=fs.nextInt();
		
		long[][] dp=new long[w][h];
		long[][] dpNext=new long[w][h];
		for (int i=0; i<k; i++) {
			for (int x=0; x<w; x++) {
				for (int y=0; y<h; y++) {
					long ans=(long)1e18;
					if (x!=0) ans=Math.min(ans, dp[x-1][y]+rightCost[x-1][y]);
					if (y!=0) ans=Math.min(ans, dp[x][y-1]+downCost[x][y-1]);
					if (x!=w-1) ans=Math.min(ans, dp[x+1][y]+rightCost[x][y]);
					if (y!=h-1) ans=Math.min(ans, dp[x][y+1]+downCost[x][y]);
					dpNext[x][y]=ans;
				}
			}
			dp=dpNext;
			dpNext=new long[w][h];
		}
		//TODO: double answer
		for (int y=0; y<h; y++) {
			for (int x=0; x<w; x++) {
				if (x!=0) out.print(" ");
				out.print(2*dp[x][y]);
			}
			out.println();
		}
		out.close();
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
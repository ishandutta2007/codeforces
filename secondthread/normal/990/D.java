

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	public static void solve(FastScanner fs) {	
		int n=fs.nextInt();
		int a=fs.nextInt();
		int b=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		
		if (Math.min(a, b)!=1||Math.max(a, b)>n) {
			out.println("NO");
			out.close();
			return;
		}
		if (a==1&&b==1) {
			if (n==2||n==3) {
				out.println("NO");
			}
			else {
				out.println("YES");
				boolean[][] edges=new boolean[n][n];
				for (int i=0; i<n-1; i++)
					edges[i][i+1]=edges[i+1][i]=true;
				for (int i=0; i<n; i++) 
					edges[i][i]=false;
				for (int i=0; i<n; i++) {
					for (int j=0; j<n; j++)
						out.print(edges[i][j]?1:0);
					out.println();
				}
				
			}
			out.close();
			return;
		}
		boolean[][] edges=new boolean[n][n];
		int connections=n-(Math.max(a, b));
		for (int i=0; i<=connections; i++) {
			for (int j=0; j<=connections; j++) {
				edges[i][j]=true;
			}
		}
		for (int i=0; i<n; i++) 
			edges[i][i]=false;
		if (a==1) 
			edges=compliment(edges);
		out.println("YES");
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++)
				out.print(edges[i][j]?1:0);
			out.println();
		}
		out.close();
	}
	
	private static boolean[][] compliment(boolean[][] graph) {
		int n=graph.length;
		boolean[][] toReturn=new boolean[n][n];
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				toReturn[i][j]=!graph[i][j];
		for (int i=0; i<n; i++) toReturn[i][i]=false;
		return toReturn;
	}

	
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		//width, startIndex;
		int[][] total=new int[n][];
		total[0]=a;
		for (int width=1; width<n; width++) {
			total[width]=new int[n-width];
			int halfWidth=Integer.highestOneBit(width);
			int earlierPart=width-halfWidth;
			for (int x=0; x<total[width].length; x++) {
				total[width][x]=total[earlierPart][x] ^ total[earlierPart][x+halfWidth];
			}
		}
		
		int nQueries=fs.nextInt();
		int[][] max=new int[n][n];
		for (int i=0; i<max.length; i++)
			max[i][i]=a[i];
		for (int diff=1; diff<n; diff++) {
			for (int i=0; i+diff<n; i++) {
				int j=i+diff;
				max[i][j]=total[diff][i];
				max[i][j]=Math.max(max[i][j], Math.max(max[i][j-1], max[i+1][j]));
			}
		}
		PrintWriter out=new PrintWriter(System.out);
		for (int q=0; q<nQueries; q++) {
			int from=fs.nextInt()-1;
			int to=fs.nextInt()-1;
			out.println(max[from][to]);
		}
		out.close();
	}

	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
			
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}
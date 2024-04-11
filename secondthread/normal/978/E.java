import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int maxCap=fs.nextInt();
		int[] deltas=fs.readArray(n);
		long[] totals=new long[n];
		for (int i=0; i<n; i++)
			totals[i]=deltas[i]+((i!=0)?totals[i-1]:0);
		long max=totals[0], min=totals[0];
		for (long i:totals) {
			max=Math.max(max, i);
			min=Math.min(min, i);
		}
		long minPossiblePeople=Math.max(0, -min);
		max=Math.max(max, 0);
		long maxPossiblePeople=maxCap-max;
		long ans=maxPossiblePeople-minPossiblePeople+1;
		System.out.println(Math.max(ans, 0));
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
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
	}
	
}
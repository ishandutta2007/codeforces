import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int r=fs.nextInt();
		int[] values=fs.readArray(1<<n);
		n=1<<n;
		long total=0;
		for (int i:values) total+=i;
		PrintWriter out=new PrintWriter(System.out);
		for (int i=0; i<r; i++) {
			out.printf("%.10f\n", total/(double)n);
			int nextIndex=fs.nextInt();
			int nextValue=fs.nextInt();
			total-=values[nextIndex];
			total+=nextValue;
			values[nextIndex]=nextValue;
		}
		out.printf("%.10f\n", total/(double)n);
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
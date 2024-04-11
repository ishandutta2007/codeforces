import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int k=fs.nextInt();
		int[] values=fs.readArray(n);
		int[] awakes=fs.readArray(n);
		long total=0;
		for (int i=0; i<n; i++)
			if (awakes[i]==1) {
				total+=values[i];
				values[i]=0;
			}
		
		int[] cs=new int[n+1];
		for (int i=1; i<=n; i++)
			cs[i]=cs[i-1]+values[i-1];
		
		long best=0;
		for (int i=0; i<=n-k; i++) {
			best=Math.max(best, cs[i+k]-cs[i]);
		}
		System.out.println(total+best);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreElements())
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
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		
	}

}
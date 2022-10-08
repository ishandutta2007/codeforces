import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			long[] as=new long[n], bs=new long[n];
			for (int i=0; i<n; i++) {
				as[i]=fs.nextLong(); bs[i]=fs.nextLong();
			}
			long total=0;
			for (int i=0; i<n; i++) {
				long shots=as[i];
				shots-=bs[(i-1+n)%n];
				shots=Math.max(shots, 0);
				total+=shots;
			}
			long ans=Long.MAX_VALUE;
			for (int i=0; i<n; i++) {
				long shots=as[i];
				shots-=bs[(i-1+n)%n];
				shots=Math.max(shots, 0);
				ans=Math.min(ans, total-shots+as[i]);
			}
			out.println(ans);
		}
		out.close();
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
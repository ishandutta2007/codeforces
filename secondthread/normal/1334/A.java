import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[][] in=new int[n+1][2];
			for (int i=0; i<n; i++) {
				in[i+1][0]=fs.nextInt();
				in[i+1][1]=fs.nextInt();
			}
			for (int i=1; i<=n; i++) {
				int d0=in[i][0]-in[i-1][0];
				int d1=in[i][1]-in[i-1][1];
				if (d0<0||d1<0||d0<d1) {
					System.out.println("NO");
					continue outer;
				}
			}
			System.out.println("YES");
		}
		
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
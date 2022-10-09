import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int c=0;
		for (int i=1; i<=n; i++) {
			for (int j=i+1; j<=n ;j++) {
				int k=i^j;
				if (k<=j||k>n) {
					continue;
				}
				if (i+j<=k)
					continue;
//				System.out.println(i+" "+j+" "+k);
				c++;
			}
		}
		System.out.println(c);
	}
	
	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			br=new BufferedReader(new InputStreamReader(System.in));
			st=new StringTokenizer("");
		}
		
		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {}
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
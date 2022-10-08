import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B2 {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		long a=fs.nextLong(), b=fs.nextLong(), c=fs.nextLong(), d=fs.nextLong();
		long gcd=gcd(c,d);
		c/=gcd;
		d/=gcd;
		if (a<c||b<d) {
			System.out.println(0);
			return;
		}
		else {
			System.out.println(Math.min(a/c, b/d));
		}
		
	}
	
	static long gcd(long a, long b) {
		return b==0?a:gcd(b, a%b);
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
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}
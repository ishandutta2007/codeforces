import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int a=fs.nextInt(), b=fs.nextInt();
			int lcm=a*b/gcd(a, b);
			boolean[] special=new boolean[lcm];
			for (int i=0; i<lcm; i++)
				special[i]=i%a%b != i%b%a;
			int[] cs=new int[lcm+1];
			for (int i=1; i<=lcm; i++)
				cs[i]=cs[i-1]+(special[i-1]?1:0);
			int nQ=fs.nextInt();
			for (int qq=0; qq<nQ; qq++) {
				long l=fs.nextLong(), r=fs.nextLong();
				System.out.print(countFor(r, cs)-countFor(l-1, cs)+" ");
			}
			System.out.println();
		}
	}
	
	static int gcd(int a, int b) {
		return b==0? a: gcd(b, a%b);
	}
	
	static long countFor(long x, int[] cs) {
		int lcm=cs.length-1;
		long full=x/lcm;
		long ans=full*cs[lcm]+cs[(int) (x%lcm+1)];
		return ans;
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
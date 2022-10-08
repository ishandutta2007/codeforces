import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		int aDist=fs.nextInt(), bDist=fs.nextInt();
		long totalSpots=n*(long)k;
		long min=totalSpots, max=0;
		long dk=Math.abs(aDist-bDist);
		for (int dn=0; dn<n; dn++) {
			long move=dn*(long)(k)+dk;
			long hit=totalSpots/gcd(totalSpots, move);
			min=Math.min(min, hit);
			max=Math.max(max, hit);
		}
		dk=(aDist+bDist);
		for (int dn=0; dn<n; dn++) {
			long move=dn*(long)(k)+dk;
			long hit=totalSpots/gcd(totalSpots, move);
			min=Math.min(min, hit);
			max=Math.max(max, hit);
		}
		
		System.out.println(min+" "+max);
	}
	
	static long gcd(long a, long b) {
		return b==0?a:gcd(b, a%b);
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
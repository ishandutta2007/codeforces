import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class B {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		long n=fs.nextLong();
		long div=0;
		boolean found=false;
		for (div=2; div*div<=n; div++) {
			if (n%div==0) {
				found=true;
				break;
			}
		}
		if (!found) {
			System.out.println(1);
			return;
		}
		else {
			long counter=0;
			while (n!=0) {
				if (div==2) {
					counter+=n/2;
					n=0;
					break;
				}
				n-=div;
				counter++;
				div=getLargestDiv(n, div);
			}
			System.out.println(counter);
		}
	}
	
	static long getLargestDiv(long n, long max) {
		for (long i=2; i<max; i++) {
			if (n%i==0) {
				return i;
			}
		}
		return max;
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
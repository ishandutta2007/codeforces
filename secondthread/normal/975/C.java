import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int q=fs.nextInt();
		int[] a=fs.readArray(n);
		long[] presums=new long[n];
		presums[0]=a[0];
		for (int i=1; i<n; i++)
			presums[i]=presums[i-1]+a[i];
		long total=presums[n-1];
		long prevArrows=0;
		for (int Q=0; Q<q; Q++) {
			long nextArrows=(prevArrows+fs.nextLong());
			if (nextArrows>=total)
				nextArrows=0;
			System.out.println(n-bs(presums, nextArrows));
				
			prevArrows=nextArrows;
		}
	}
	
	static int bs(long[] presums, long targetSum) {
		int min=0, max=presums.length-1;
		while (min<max) {
			int mid=(min+max)/2;
			if (presums[mid]<=targetSum) {
				min=mid+1;
			}
			else {
				max=mid;
			}
		}
		return min;
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
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class D {
	
	private static int oo=100_000_000;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		long[] a=fs.readLongArray(n);
		if (n==1||n==2) {
			System.out.println(0);
			return;
		}
		long diff=a[1]-a[0];
		int min=oo;
		for (long d=diff-2; d<=diff+2; d++) {
			min=Math.min(min, countChanges(a, d));
		}
		if (min>=oo) {
			System.out.println(-1);
			return;
		}
		System.out.println(min);
	}
	
	static int countChanges(long[] a, long diff) {
//		System.out.println("Trying diff "+diff);
		int best=oo;
		outer: for (long startVal=a[0]-1; startVal<=a[0]+1; startVal++) {
			int changeCount=startVal==a[0]?0:1;
			long lastVal=startVal;
			for (int i=1; i<a.length; i++) {
				long target=lastVal+diff;
				if (Math.abs(target-a[i])>=2)
					continue outer;
				if (target!=a[i])
					changeCount++;
				lastVal=target;
			}
			best=Math.min(best, changeCount);
		}
		return best;
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
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
	}
	
}
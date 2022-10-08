import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nBroken=fs.nextInt();
		fs.next();
		int needToSkip=nBroken-fs.nextInt();
		
		int[] a=new int[nBroken];
		for (int i=0; i<nBroken; i++) {
			a[i]=fs.nextInt();
		}
		long ans=nBroken;
		PriorityQueue<Integer> pq=new PriorityQueue<>();
		for (int i=1; i<nBroken; i++) pq.add(a[i]-a[i-1]-1);
		while (needToSkip-->0) {
			ans+=pq.remove();
		}
		System.out.println(ans);
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
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}

}
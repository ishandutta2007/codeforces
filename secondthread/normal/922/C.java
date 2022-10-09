import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		long n=fs.nextLong();
		long k=fs.nextLong();
		if (k>=n&&n>1) {
			System.out.println("No");
			return;
		}
		HashSet<Integer> set=new HashSet<>();
		for (int i=1; i<=k; i++) {
			if (set.contains((int)(n%i))) {
				System.out.println("No");
				return;
			}
			set.add((int)(n%i));
		}
		System.out.println("Yes");
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
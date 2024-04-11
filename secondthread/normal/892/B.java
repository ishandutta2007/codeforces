import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++) {
			a[i]=fs.nextInt();
		}
		int firstDead=Integer.MAX_VALUE;
		boolean[] dead=new boolean[n];
		for (int i=n-1; i>=0; i--) {
			if (firstDead<=i) {
				dead[i]=true;
			}
			firstDead=Math.min(firstDead, i-a[i]);
		}
		int c=0;
		for (boolean b:dead) {
			if (!b) c++;
		}
		System.out.println(c);
	}

	private static class FastScanner {
		private BufferedReader br;
		private StringTokenizer st;
		
		public FastScanner() {
			st=new StringTokenizer("");
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next() {
			if (st.hasMoreTokens()) {
				return st.nextToken();
			}
			while (!st.hasMoreTokens()) {
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return null;
		}
	}
	
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int k=fs.nextInt();
		if (n==0) {
			System.out.println("YES");
			return;
		}
		long t=0;
		for (int i=0; i<n; i++) {
			t+=fs.nextInt();
		}
		if (t+n-1==k) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}

	}
	
	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		
		public FastScanner() {
			br=new BufferedReader(new InputStreamReader(System.in));
			st=new StringTokenizer("");
		}
		
		public String next() {
			if (st.hasMoreTokens()) {
				return st.nextToken();
			}
			while (!st.hasMoreTokens()) {
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			
			return st.nextToken();
		}
		
		public String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return null;
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}

}
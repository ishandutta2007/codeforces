import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int t=fs.nextInt();
		for (int i=0; i<n; i++) {
			if (t<=0) {
				System.out.println(i);
				return;
			}
			t-=(86400-fs.nextInt());
			if (t<=0) {
				System.out.println(i+1);
				return;
			}
		}
		int counter=n;
		while (t>0) {
			counter++;
			t-=(86400);
		}
		System.out.println(counter);

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
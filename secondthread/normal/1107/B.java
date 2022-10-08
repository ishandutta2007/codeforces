import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BGen {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
//		for (int x=0; x<1000; x++) {
//			System.out.println(x+" "+root(x+""));
//		}
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			long x=fs.nextLong()-1, root=fs.nextLong();
			System.out.println(root+9*x);
		}
	}
	
	static int root(String s) {
		int ans=0;
		for (char c:s.toCharArray()) ans+=c-'0';
		if (ans<10) return ans;
		return root(ans+"");
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
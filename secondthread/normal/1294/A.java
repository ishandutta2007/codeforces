import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int t=fs.nextInt();
		for (int tt=0; tt<t; tt++) {
		int a=fs.nextInt(), b=fs.nextInt(), c=fs.nextInt(), n=fs.nextInt();
		int total=a+b+c+n;
		if (total%3!=0) {
			System.out.println("NO");
		}
		else {
			int res=total/3;
			if (a>res || b>res || c>res) {
				System.out.println("NO");
			}
			else {
				System.out.println("YES");
			}
		}
		}
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
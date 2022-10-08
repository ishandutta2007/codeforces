import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++ ) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			int max=0, ans=0;
			max=a[0];
			for (int i:a) {
				max=Math.max(max, i);
				int diff=max-i;
				if (diff==0) continue;
				if (diff==1) ans=Math.max(ans, 1);
				else {
					ans=Math.max(ans, check(diff));
				}
			}
			out.println(ans);
		}
		out.close();
	}
	
	static int check(int i) {
		long made=0;
		for (int test=0; true; test++) {
			if (made>=i) return test;
			made+=1l<<test;
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
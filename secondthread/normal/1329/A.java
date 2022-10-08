import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
/*
6 2
4 2

10
4
6 6 6 6
 */
public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int m=fs.nextInt();
		int[] a=fs.readArray(m);
		long sum=0;
		long start=0;
		
		for (int i:a) {
			long end=start+i;
			start++;
			if (end>n) {
				System.out.println(-1);
				return;
			}
			sum+=i;
		}
		if (sum<n) {
			System.out.println(-1);
			return;
		}
		long[] pos=new long[m];
		long end=n;
		for (int i=m-1; i>=0; i--) {
			start=Math.max(i, end-a[i]);
			end=start;
			pos[i]=start;
		}
		PrintWriter out=new PrintWriter(System.out);
		for (long i:pos) {
			out.print(i+1+" ");
		}
		out.println();
		out.close();
		
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
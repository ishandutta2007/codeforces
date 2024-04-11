import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*

 */
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] c=fs.readArray(n);
		long[] mid=new long[n+1];
		for (int i=1; i<=n; i++) mid[i]=mid[i-1]+Math.max(c[i-1], 0);
		long[] a=new long[n];
		for (int i=0; i<n; i++) a[i]=mid[i]+c[i];
		
		PrintWriter out=new PrintWriter(System.out);
		for (int i=0; i<n; i++) {
			out.print(a[i]+" ");
		}
		out.println();
		out.close();
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		boolean hasNext() {
			String next=null;
			try {
				next = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (next==null) {
				return false;
			}
			st=new StringTokenizer(next);
			return true;
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}

}
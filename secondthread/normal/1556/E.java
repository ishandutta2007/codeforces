import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		
		int n=fs.nextInt(), q=fs.nextInt();
		long[] a=fs.readArray(n), b=fs.readArray(n);
		long[] diffs=new long[n];
		for (int i=0; i<n; i++) diffs[i]=a[i]-b[i];
		long[] cs=new long[n+1];
		for (int i=1; i<=n; i++) cs[i]=diffs[i-1]+cs[i-1];
		
		RMaxQ maxQ=new RMaxQ(cs);
		RMinQ minQ=new RMinQ(cs);
		
		for (int qq=0; qq<q; qq++) {
			int l=fs.nextInt()-1, r=fs.nextInt()-1;
			long startCS=cs[l], endCS=cs[r+1];
			if (startCS!=endCS) {
				out.println(-1);
				continue;
			}
			long maxCS=maxQ.query(l+1, r+1);
			if (maxCS>startCS) {
				out.println(-1);
				continue;
			}
			long minCS=minQ.query(l+1, r+1);
			out.println(startCS-minCS);
		}
		
		out.close();
	}
	
	static class RMaxQ {
		long[] vs;
		long[][] lift;

		public RMaxQ(long[] vs) {
			this.vs = vs;
			int n = vs.length;
			int maxlog = Integer.numberOfTrailingZeros(Integer.highestOneBit(n)) + 2;
			lift = new long[maxlog][n];
			for (int i = 0; i < n; i++)
				lift[0][i] = vs[i];
			int lastRange = 1;
			for (int lg = 1; lg < maxlog; lg++) {
				for (int i = 0; i < n; i++) {
					lift[lg][i] = Math.max(lift[lg - 1][i], lift[lg - 1][Math.min(i + lastRange, n - 1)]);
				}
				lastRange *= 2;
			}
		}

		public long query(int low, int hi) {
			int range = hi - low + 1;
			int exp = Integer.highestOneBit(range);
			int lg = Integer.numberOfTrailingZeros(exp);
			return Math.max(lift[lg][low], lift[lg][hi - exp + 1]);
		}
	}
	

	static class RMinQ {
		long[] vs;
		long[][] lift;
	
		public RMinQ(long[] vs) {
			this.vs = vs;
			int n = vs.length;
			int maxlog = Integer.numberOfTrailingZeros(Integer.highestOneBit(n)) + 2;
			lift = new long[maxlog][n];
			for (int i = 0; i < n; i++)
				lift[0][i] = vs[i];
			int lastRange = 1;
			for (int lg = 1; lg < maxlog; lg++) {
				for (int i = 0; i < n; i++) {
					lift[lg][i] = Math.min(lift[lg - 1][i], lift[lg - 1][Math.min(i + lastRange, n - 1)]);
				}
				lastRange *= 2;
			}
		}
	
		public long query(int low, int hi) {
			int range = hi - low + 1;
			int exp = Integer.highestOneBit(range);
			int lg = Integer.numberOfTrailingZeros(exp);
			return Math.min(lift[lg][low], lift[lg][hi - exp + 1]);
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		long[] readArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}
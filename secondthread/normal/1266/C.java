

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	public static void solve(FastScanner fs) {	
		PrintWriter out=new PrintWriter(System.out);
//		for (int h=1; h<100; h++) {
//			for (int w=1; w<100; w++) {
				
				int h=fs.nextInt(), w=fs.nextInt();
				if (Math.max(w, h)==1) {
					System.out.println(0);
					return;
//					continue;
				}
				if (w==1) {
					for (int i=0; i<h; i++) {
						System.out.println(i+2);
					}
					return;
				}
				int[] xs=new int[w], ys=new int[h];
				for (int i=0; i<h; i++) {
					ys[i]=i+1;
				}
				for (int i=0; i<w; i++)
					xs[i]=i+1+h;
				int[][] ans=new int[w][h];
				for (int y=0; y<h; y++) {
					for (int x=0; x<w; x++) {
						ans[x][y]=(int) (xs[x]*ys[y]/gcd(xs[x], ys[y]));
						out.print(ans[x][y]+" ");
					}
					
					out.println();
				}
				out.close();
//				check(ans, w, h);
		
//			}
//		}
//		out.close();
	}
	
	static void check(int[][] ans, int w, int h) {
		for (int y=0; y<h; y++) {
			long gcd=0;
			for (int x=0; x<w; x++) gcd=gcd(gcd, ans[x][y]);
			if (gcd!=y+1) {
				System.out.println("Broke on "+w+" "+h);
				throw null;
			}
		}
		for (int x=0; x<w; x++) {
			long gcd=0;
			for (int y=0; y<h; y++) gcd=gcd(gcd, ans[x][y]);
			if (gcd!=x+1+h) {
				System.out.println("Broke on "+w+" "+h);
				throw null;
			}
		}
	}
	
	static long gcd(long a, long b) {
		if (b==0) return a;
		return gcd(b, a%b);
	}

	
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {

	public static void solve(FastScanner fs) {	
		int n=fs.nextInt();
		int a=fs.nextInt();
		int b=fs.nextInt();
		int max=0;
		for (int i=1; i<10000; i++) {
			if (works(n, a, b, i))
				max=i;
		}
		System.out.println(max);
	}
	
	private static boolean works(int numberOfPlates, int a, int b, int piecesPerPlate) {
		if (a<piecesPerPlate||b<piecesPerPlate)
			return false;
		int aPlates=a/piecesPerPlate;
		int bPlates=b/piecesPerPlate;
		return aPlates+bPlates>=numberOfPlates;
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
	}
}


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {

	public static void solve(FastScanner fs) {
		int width=fs.nextInt();
		int k=fs.nextInt();
		
		boolean[][] board=new boolean[width][width];
		for (int y=0; y<width; y++) {
			String line=fs.next();
			for (int x=0; x<width; x++) {
				board[x][y]=line.charAt(x)=='#';
			}
		}
		int[][] counter=new int[width][width];
		for (int y=0; y<width; y++) {
			for (int x=0; x<width; x++) {
				if (canPlaceH(x, y, k, board)) {
					for (int i=0; i<k; i++) {
						counter[x+i][y]++;
					}
				}
				if (canPlaceV(x, y, k, board)) {
					for (int i=0; i<k; i++) {
						counter[x][y+i]++;
					}
				}
			}
		}
		int max=0;
		int xx=0, yy=0;
		for (int x=0; x<width; x++) {
			for (int y=0; y<width; y++) {
				if (counter[x][y]>max) {
					max=counter[x][y];
					xx=x;
					yy=y;
				}
			}
		}
		xx++;
		yy++;
		System.out.println(yy+" "+xx);
	}
	
	private static boolean canPlaceH(int x, int y, int k, boolean[][] board) {
		if (k==0)
			return true;
		if (!legal(x, y, board))
			return false;
		return canPlaceH(x+1, y, k-1, board);
	}
	
	private static boolean canPlaceV(int x, int y, int k, boolean[][] board) {
		if (k==0)
			return true;
		if (!legal(x, y, board))
			return false;
		return canPlaceV(x, y+1, k-1, board);
	}

	private static boolean legal(int x, int y, boolean[][] board) {
		if (x<0||y<0||x>=board.length||y>=board.length||board[x][y])
			return false;
		return true;
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
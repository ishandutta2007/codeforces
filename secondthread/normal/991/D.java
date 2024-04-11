

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {

	static int n;
	static boolean[][] board;
	//dp[x][topFalse][bottomFalse]
	static int dp[][][];
	
	public static void solve(FastScanner fs) {	
		String l1=fs.next()+"XXX", l2=fs.next()+"XXX";
		n=l1.length();
		board=new boolean[2][n];
		for (int i=0; i<n; i++) {
			board[0][i]=l1.charAt(i)=='X';
			board[1][i]=l2.charAt(i)=='X';
		}
		dp=new int[n][2][2];
		for (int i=0; i<dp.length; i++)
			for (int j=0; j<dp[i].length; j++)
				Arrays.fill(dp[i][j], -1);
		int ans=go(0, 0, 0);
		System.out.println(ans);
	}
	
	private static int go(int x, int topFalse, int bottomFalse) {
		if (x>=n-2) {
			return dp[x][topFalse][bottomFalse]=0;
		}
		if (board[0][x]) topFalse=1;
		if (board[1][x]) bottomFalse=1;
		if (dp[x][topFalse][bottomFalse]!=-1)
			return dp[x][topFalse][bottomFalse];
		int best=0;
		if (topFalse==0&&bottomFalse==0) {
			if (!board[0][x+1]) {
				best=Math.max(best, 1+go(x+1, 1, 0));
			}
			if (!board[1][x+1]) {
				best=Math.max(best, 1+go(x+1, 0, 1));
			}
		}
		if (!board[0][x+1]&&!board[1][x+1]) {
			if (topFalse==0) {
				best=Math.max(best, 1+go(x+1, 1, 1));
			}
			if (bottomFalse==0) {
				best=Math.max(best, 1+go(x+1, 1, 1));
			}
		}
		best=Math.max(best, go(x+1, 0, 0));
		return dp[x][topFalse][bottomFalse]=best;
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


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {

	public static void solve(FastScanner fs) {	
		char[][] board=new char[9][9];
		for (int y=0; y<9; y++) {
			String line1=fs.next();
			String line2=fs.next();
			String line3=fs.next();
			board[0][y]=line1.charAt(0);
			board[1][y]=line1.charAt(1);
			board[2][y]=line1.charAt(2);
			
			board[3][y]=line2.charAt(0);
			board[4][y]=line2.charAt(1);
			board[5][y]=line2.charAt(2);
			
			board[6][y]=line3.charAt(0);
			board[7][y]=line3.charAt(1);
			board[8][y]=line3.charAt(2);
		}
		int boardy=(fs.nextInt()-1)%3;
		int boardx=(fs.nextInt()-1)%3;
		
		if (full(board, boardx, boardy)) {
			replaceAll(board);
		}
		else {
			replaceBoard(board, boardx, boardy);
		}
		for (int y=0; y<9; y++) {
			if (y%3==0&&y!=0)
				System.out.println();
			for (int x=0; x<9; x++) {
				if (x!=0&&x%3==0) {
					System.out.print(" ");
				}
				System.out.print(board[x][y]);
			}
			System.out.println();
		}
	}
	
	private static boolean full(char[][] board, int boardX, int boardY) {
		boardX*=3;
		boardY*=3;
		for (int x=0; x<3; x++) {
			for (int y=0; y<3; y++) {
				if (board[x+boardX][y+boardY]=='.')
					return false;
			}
		}
		return true;
	}
	
	private static void replaceBoard(char[][] board, int boardX, int boardY) {
		boardX*=3;
		boardY*=3;
		for (int x=0; x<3; x++) {
			for (int y=0; y<3; y++) {
				if (board[x+boardX][y+boardY]=='.')
					board[x+boardX][y+boardY]='!';
			}
		}
	}
	
	private static void replaceAll(char[][] board) {
		for (int x=0; x<9; x++) {
			for (int y=0; y<9; y++) {
				if (board[x][y]=='.')
					board[x][y]='!';
			}
		}
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
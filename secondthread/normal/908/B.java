

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {

	static boolean[][] board;
	private static int[] dx={0, 1, 0, -1};
	private static int[] dy={1, 0, -1, 0};
	
	
	public static void solve(FastScanner fs) {	
		int height=fs.nextInt();
		int width=fs.nextInt();
		board=new boolean[width][height];
		int sX=0, sY=0, eX=0, eY=0;
		for (int y=0; y<height; y++) {
			char[] line=fs.next().toCharArray();
			for (int x=0; x<width; x++) {
				switch (line[x]) {
					case 'S':
						sX=x;
						sY=y;
						board[x][y]=true;
						break;
					case 'E':
						eX=x;
						eY=y;
						board[x][y]=true;
						break;
					case '.':
						board[x][y]=true;
						break;
					case '#':
						break;
				}
			}
		}
		String original=fs.next();
		int ans=countAll(original, new int[4], 0, new boolean[4], sX, sY, eX, eY, board);
		System.out.println(ans);
	}
	
	private static int countAll(String original, int[] replaceWith, int index, boolean[] used, int sX, int sY, int eX, int eY, boolean[][] board) {
		if (!hasFalse(used)) {
			String toPass="";
			for (int i=0; i<original.length(); i++)
				toPass+=replaceWith[original.charAt(i)-'0'];
//			System.out.println("trying: "+toPass);
			if (works(toPass, board, sX, sY, eX, eY))
				return 1;
			return 0;
		}
		int c=0;
		for (int i=0; i<4; i++) {
			if (used[i])
				continue;
			replaceWith[index]=i;
			used[i]=true;
			c+=countAll(original, replaceWith, index+1, used, sX, sY, eX, eY, board);
			used[i]=false;
		}
		return c;
	}
	
	private static boolean hasFalse(boolean[] a) {
		for (boolean b:a)
			if (!b)
				return true;
		return false;
	}
	
	private static boolean isLegalSpot(int x, int y) {
		if (x<0||y<0||x>=board.length||y>=board[x].length||!board[x][y])
			return false;
		return true;
	}

	private static boolean works(String movements, boolean[][] board, int sX, int sY, int eX, int eY) {
		if (sX==eX&&sY==eY)
			return true;
		if (!isLegalSpot(sX, sY)||movements.isEmpty())
			return false;
		return works(movements.substring(1), board, sX+dx[movements.charAt(0)-'0'], sY+dy[movements.charAt(0)-'0'], eX, eY);
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
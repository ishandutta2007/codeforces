import java.io.*;
import java.util.*;

public class R327qC {

	static int n,m;
	static char g[][];
	static int ans[][][];
	static int oo = (int)1e8;
	static int dx[] = new int[]{-1,1,0,0};
	static int dy[] = new int[]{0,0,-1,1};
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
		m = in.nextInt();
		
		g = new char[n][m];
		for(int i=0;i<n;i++)
			g[i] = in.readString().toCharArray();
		
		ans = new int[4][n][m];
		for(int i=1;i<=3;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<m;k++)
					ans[i][j][k] = oo;
		
		for(int i=1;i<=3;i++)
			bfs(i);
		
		int mainAns = oo;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(g[i][j] == '.')
					mainAns = Math.min(mainAns, ans[1][i][j] + ans[2][i][j] + ans[3][i][j] - 2);
		
		int wow[][] = new int[4][4];
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
				wow[i][j] = oo;
	
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int src = g[i][j] - '0';
				if(src >= 1 && src <= 3)
					for(int k = 1;k <= 3; k++)
						wow[src][k] = wow[k][src] = Math.min(wow[src][k], ans[k][i][j]);
				}
			}
	
		for(int i=1;i<=3;i++)
			mainAns = Math.min(mainAns, wow[i][1] + wow[i][2] + wow[i][3] - 2);
		
		w.println(mainAns >= oo/2 ? -1 : mainAns);
		w.close();
	}
	
	static void bfs(int src){
		char strt = (char)('0' + src);
		Queue<Integer> q = new LinkedList<Integer>();
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(g[i][j] == strt){
					ans[src][i][j] = 0;
					q.add(i);
					q.add(j);
				}
		
		while(!q.isEmpty()){
			int x = q.remove();
			int y = q.remove();
			for(int dk=0;dk<4;dk++){
				if(h(x + dx[dk],y + dy[dk],src)){
					ans[src][x + dx[dk]][y + dy[dk]] = ans[src][x][y] + 1;
					q.add(x + dx[dk]);
					q.add(y + dy[dk]);
				}
			}
		}
		
	}
	
	static boolean h(int x,int y,int src){
		return x >= 0  && y >= 0 && x < n && y < m && g[x][y] != '#' && ans[src][x][y] == oo;
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			int res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}
		
		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			long res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}
		
		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}
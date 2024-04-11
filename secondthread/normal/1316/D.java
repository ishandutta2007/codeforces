import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
/*
2
-1 -1 -1 -1
1 1 -1 -1

2
-1 -1 -1 -1
2 1 -1 -1
 */
public class D {
	
	static int n;
	static Vec[][] board;
	static char[][] ans;
	static char[] directions="DURL".toCharArray();
	static int[] dx= {0, 0, -1, 1};
	static int[] dy= {-1, 1, 0, 0};
	static boolean[][] visited;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		n=fs.nextInt();
		board=new Vec[n][n];
		visited=new boolean[n][n];
		for (int y=0; y<n; y++)
			for (int x=0; x<n; x++) {
				int yy=fs.nextInt()-1, xx=fs.nextInt()-1;
				board[x][y]=new Vec(xx, yy);
			}
	
		ans=new char[n][n];
		for (int x=0; x<n; x++)
			for (int y=0; y<n; y++)
				if (board[x][y].x==x && board[x][y].y==y) {
					dfsFrom(x, y, 'X');
				}
		for (int x=0; x<n; x++) {
			space:for (int y=0; y<n; y++) {
				if (visited[x][y]) continue;
				if (!visited[x][y] && !board[x][y].eq(new Vec(-2, -2))) {
					System.out.println("INVALID");
					return;
				}
				for (int d=0; d<4; d++) {
					int nx=x+dx[d], ny=y+dy[d];
					if (!valid(nx, ny)) continue;
					if (visited[nx][ny]) continue;
					ans[x][y]=directions[d^1];
					continue space;
				}
				System.out.println("INVALID");
				return;
			}
		}
		PrintWriter out=new PrintWriter(System.out);
		out.println("VALID");
		for (int y=0; y<n; y++) {
			for (int x=0; x<n; x++) out.print(ans[x][y]);
			out.println();
		}
		out.close();
	}
	
	static void dfsFrom(int x, int y, char cameFrom) {
		if (visited[x][y]) return;
		visited[x][y]=true;
		ans[x][y]=cameFrom;
		for (int d=0; d<4; d++) {
			int nx=x+dx[d], ny=y+dy[d];
			if (!valid(nx, ny)) continue;
			if (board[x][y].eq(board[nx][ny]))
				dfsFrom(nx, ny, directions[d]);
		}
	}
	
	static boolean valid(int x, int y) {
		if (x<0 || y<0 || x>=n || y>=n) return false;
		return true;
	}

	static class Vec {
		int x,y;
		public Vec(int x, int y) {
			this.x=x;
			this.y=y;
		}
		boolean eq(Vec o) {
			return x==o.x && y==o.y;
		}
		
		public String toString() {
			return "("+x+", "+y+")";
		}
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
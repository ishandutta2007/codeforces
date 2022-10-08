import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int qx=fs.nextInt()-1, qy=fs.nextInt()-1;
		int sx=fs.nextInt()-1, sy=fs.nextInt()-1;
		int ex=fs.nextInt()-1, ey=fs.nextInt()-1;
		boolean[][] safe=new boolean[n][n];
		for (int i=0; i<n; i++)
			Arrays.fill(safe[i], true);
		for (int i=0; i<n; i++) {
			safe[i][qy]=safe[qx][i]=false;
		}
		for (int dx=-n; dx<=n; dx++) {
			if (valid(qx-dx, qy-dx, safe))
				safe[qx-dx][qy-dx]=false;
			if (valid(qx-dx, qy+dx, safe))
				safe[qx-dx][qy+dx]=false;
			if (valid(qx+dx, qy-dx, safe))
				safe[qx+dx][qy-dx]=false;
			if (valid(qx+dx, qy+dx, safe))
				safe[qx+dx][qy+dx]=false;
		}
		ArrayDeque<Integer> xs=new ArrayDeque<>();
		ArrayDeque<Integer> ys=new ArrayDeque<>();
		boolean[][] hit=new boolean[n][n];
		int[] dx= {1, 1, 0, -1, -1, -1, 0, 1}, dy= {0, 1, 1, 1, 0, -1, -1, -1};
		hit[sx][sy]=true;
		xs.add(sx);
		ys.add(sy);
		while (!xs.isEmpty()) {
			int x=xs.remove();
			int y=ys.remove();
			for (int d=0; d<dx.length; d++) {
				int nx=x+dx[d], ny=y+dy[d];
				if (valid(nx, ny, safe) && !hit[nx][ny]) {
					xs.add(nx);
					ys.add(ny);
					hit[nx][ny]=true;
				}
			}
		}
		System.out.println(hit[ex][ey]?"YES":"NO");
	}
	
	static boolean valid(int x, int y, boolean[][] board) {
		if (x<0||y<0||x>=board.length||y>=board[x].length||!board[x][y])
			return false;
		return true;
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
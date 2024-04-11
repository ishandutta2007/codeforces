import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int h=fs.nextInt(), w=fs.nextInt(), nQueries=fs.nextInt();
		boolean[][] board=new boolean[w][h];
		for (int y=0; y<h; y++) {
			char[] line=fs.next().toCharArray();
			for (int x=0; x<w; x++) board[x][y]=line[x]=='1';
		}
		
		//TODO: bfs
		int[][] change=new int[w][h];
		for (int x=0; x<w; x++)
			Arrays.fill(change[x], -1);
		
		int[] dx= {0, 0, 1, -1};
		int[] dy= {1, -1, 0, 0};
		ArrayDeque<Integer> xs=new ArrayDeque<>(), ys=new ArrayDeque<>();
		for (int x=0; x<w; x++) {
			outer: for (int y=0; y<h; y++) {
				for (int d=0; d<4; d++) {
					int nx=x+dx[d], ny=y+dy[d];
					if (!legal(nx, ny, board)) continue;
					if (board[nx][ny]!=board[x][y]) continue;
//					System.out.println("Can start at "+x+" "+y+" "+d);
					xs.add(x);
					ys.add(y);
					change[x][y]=0;
					continue outer;
				}
			}
		}
		
		while (!xs.isEmpty()) {
			int x=xs.removeFirst(), y=ys.removeFirst();
			for (int d=0; d<4; d++) {
				int nx=x+dx[d], ny=y+dy[d];
				if (!legal(nx, ny, board)) continue;
				if (change[nx][ny]!=-1) continue;
				change[nx][ny]=change[x][y]+1;
				xs.add(nx);
				ys.add(ny);
			}
		}
		
//		System.out.println(" "+change[0][0]);
		//TODO: printwriter
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQueries; qq++) {
			int y=fs.nextInt()-1, x=fs.nextInt()-1;
			long time=fs.nextLong();
			if (time<=change[x][y] || change[x][y]==-1) {
				out.println(board[x][y]?'1':'0');
			}
			else {
				long changed=time-change[x][y];
				if (board[x][y])
					out.println(1-changed%2);
				else
					out.println(changed%2);
			}
		}
		out.close();
	}
	
	static boolean legal(int x, int y, boolean[][] board) {
		if (x<0||y<0||x>=board.length||y>=board[x].length) return false;
		return true;
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
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}
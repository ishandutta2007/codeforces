import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringTokenizer;
/*
5 5
.....
.###.
....#
.....
.....


 * 
 * 
 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int h=fs.nextInt(), w=fs.nextInt();
		boolean[][] board=new boolean[w][h];
		for (int y=0; y<h; y++) {
			char[] line=fs.next().toCharArray();
			for (int x=0; x<w; x++) 
				board[x][y]=line[x]=='.';
		}
		int[][] dist=new int[w][h], distRev=new int[w][h];
		for (int i=0; i<w; i++) Arrays.fill(dist[i], -1);
		int[] dx= {0, 1}, dy= {1, 0};
		ArrayDeque<Integer> xs=new ArrayDeque<>(), ys=new ArrayDeque<>();
		dist[0][0]=0;
		xs.add(0); ys.add(0);
		while (!xs.isEmpty()) {
			int curX=xs.remove(), curY=ys.remove();
//			System.out.println(curX+" "+curY+" "+dist[curX][curY]);
			for (int d=0; d<2; d++) {
				int nextX=curX+dx[d], nextY=curY+dy[d];
				if (nextX>=w||nextY>=h||!board[nextX][nextY]||dist[nextX][nextY]!=-1) continue;
				dist[nextX][nextY]=dist[curX][curY]+1;
				xs.add(nextX);
				ys.add(nextY);
			}
		}
		for (int i=0; i<w; i++)
			Arrays.fill(distRev[i], -1);
		distRev[w-1][h-1]=0;
		xs.add(w-1);
		ys.add(h-1);
		while (!xs.isEmpty()) {
			int curX=xs.remove(), curY=ys.remove();
//			System.out.println(curX+" "+curY);
			for (int d=0; d<2; d++) {
				int nextX=curX-dx[d], nextY=curY-dy[d];
				if (nextX<0||nextY<0||!board[nextX][nextY]||distRev[nextX][nextY]!=-1) continue;
				distRev[nextX][nextY]=distRev[curX][curY]+1;
				xs.add(nextX);
				ys.add(nextY);
			}
		}
		int[] cs=new int[w+h-1];
		for (int x=0; x<w; x++) {
			for (int y=0; y<h; y++) {
				if (dist[x][y]!=-1 && distRev[x][y]!=-1) {
//					System.out.println("reachable: "+x+" "+y+" "+dist[x][y]);
					cs[dist[x][y]]++;
				}
			}
		}
		if (cs[w+h-2]!=1) {
			System.out.println(0);
			return;	
		}
		for (int i=1; i<w+h-2; i++) {
			if (cs[i]==1) {
				System.out.println(1);
				return;
			}
		}
		System.out.println(2);
	}

	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}
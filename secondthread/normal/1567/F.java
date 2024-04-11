import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int h=fs.nextInt(), w=fs.nextInt();
		char[][] grid=new char[w][h];
		for (int y=0; y<h; y++) {
			char[] line=fs.next().toCharArray();
			for (int x=0; x<w; x++) {
				grid[x][y]=line[x];
			}
		}
		int[][] dist=new int[w][h];
		ArrayDeque<Integer> xs=new ArrayDeque<>(), ys=new ArrayDeque<>();
		int[] dx= {1, -1, 0, 0};
		int[] dy= {0, 0, 1, -1};
		int[] d2x= {1, -1, 0, 0, 1, 1, -1, -1};
		int[] d2y= {0, 0, 1, -1, 1, -1, 1, -1};
		for (int x=0; x<w; x++) {
			for (int y=0; y<h; y++) {
				int count=0;
				for (int d=0; d<4; d++) {
					int nx=x+dx[d];
					int ny=y+dy[d];
					if (nx>=0 && ny>=0 && nx<w && ny<h && grid[nx][ny]=='.' && grid[x][y]=='X') count++;
				}
				if (count%2==1) {
					System.out.println("NO");
					return;
				}
			}
		}
		System.out.println("YES");
		
		for (int x=0; x<w; x++) Arrays.fill(dist[x], -1);
		xs.add(0);
		ys.add(0);
		dist[0][0]=0;
		while (!xs.isEmpty()) {
			int sx=xs.removeFirst();
			int sy=ys.removeFirst();
			int sd=dist[sx][sy];
			for (int d=0; d<8; d++) {
				int nx=sx+d2x[d], ny=sy+d2y[d];
				if (nx<0||ny<0||nx>=w || ny>=h) continue;
				int nd=grid[nx][ny]=='.'?sd:sd+1;
				if (d>=4 && grid[nx][ny]!='.') continue;
				if (dist[nx][ny]==-1 || dist[nx][ny]>nd) {
					//then add this to the queue
					dist[nx][ny]=nd;
					if (sd==nd) {
						xs.addFirst(nx);
						ys.addFirst(ny);
					}
					else {
						xs.addLast(nx);
						ys.addLast(ny);
					}
				}
			}
		}
		
		int[][] ans=new int[w][h];
		for (int x=0; x<w; x++) {
			for (int y=0; y<h; y++) {
				if (grid[x][y]=='X') continue;
				int normal=(y)%2*3+1;
				if(dist[x][y]%2==0) {
					ans[x][y]=normal;
				}
				else {
					ans[x][y]=normal==4?1:4;
				}
			}
		}
		
		for (int x=0; x<w; x++) {
			for (int y=0; y<h; y++) {
				if (grid[x][y]=='X') {
					for (int d=0; d<4; d++) {
						int nx=x+dx[d], ny=y+dy[d];
						if (grid[nx][ny]=='.')
							ans[x][y]+=ans[nx][ny];
					}
					if (ans[x][y]%5!=0) {
						System.out.println(x+" "+y+" "+ans[x][y]);
//						throw null;
					}
				}
			}
		}
		for (int y=0; y<h; y++) {
			for (int x=0; x<w; x++) {
				System.out.print(ans[x][y]+" ");
			}
			System.out.println();
		}
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
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
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class G {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int h=fs.nextInt(), w=fs.nextInt(), walkCost=fs.nextInt();
		int[][] grid=new int[w][h];
		for (int y=0; y<h; y++)
			for (int x=0; x<w; x++) grid[x][y]=fs.nextInt();
		int[][] fromStart=walkBFS(0, 0, grid);
		int[][] fromEnd=walkBFS(w-1, h-1, grid);
		long ans=Long.MAX_VALUE;
		
		//walk directly
		if (fromEnd[0][0]!=-1) {
			ans=Math.min(ans, walkCost*(long)fromEnd[0][0]);
		}
		
		//or use one teleporter
		long minStart=Long.MAX_VALUE/3, minEnd=Long.MAX_VALUE/3;
		for (int x=0; x<w; x++)
			for (int y=0; y<h; y++) {
				if (grid[x][y]==-1 || grid[x][y]==0) continue;
				long startCost=fromStart[x][y]*(long)walkCost + grid[x][y];
				long endCost=fromEnd[x][y]*(long)walkCost + grid[x][y];
				if (fromStart[x][y]!=-1) minStart=Math.min(minStart, startCost);
				if (fromEnd[x][y]!=-1) minEnd=Math.min(minEnd, endCost);
			}
		ans=Math.min(ans, minStart+minEnd);
		if (ans>Long.MAX_VALUE/5) {
			System.out.println(-1);
		}
		else {
			System.out.println(ans);
		}
	}
	
	static int[][] walkBFS(int fromX, int fromY, int[][] grid) {
		ArrayDeque<Integer> xq=new ArrayDeque<>(), yq=new ArrayDeque<>();
		xq.add(fromX); yq.add(fromY);
		int[] dx= {-1, 1, 0, 0};
		int[] dy= {0, 0, -1, 1};
		int[][] res=new int[grid.length][grid[0].length];
		for (int x=0; x<res.length; x++)
			Arrays.fill(res[x], -1);
		res[fromX][fromY]=0;
		
		while (!xq.isEmpty()) {
			int curx=xq.removeFirst();
			int cury=yq.removeFirst();
			int curD=res[curx][cury];
			for (int d=0; d<4; d++) {
				int newX=curx+dx[d], newY=cury+dy[d];
				if (newX<0 || newY<0 || newX>=grid.length || newY>=grid[newX].length 
						|| grid[newX][newY]==-1) continue;
				if (res[newX][newY]==-1) {
					res[newX][newY]=curD+1;
					xq.addLast(newX);
					yq.addLast(newY);
				}
			}
		}
		return res;
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
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int height=fs.nextInt();
		int width=fs.nextInt();
		int startY=fs.nextInt()-1, startX=fs.nextInt()-1;
		int moveLeftTimes=fs.nextInt(), moveRightTimes=fs.nextInt();
		boolean[][] board=new boolean[width][height];
		for (int y=0; y<height; y++) {
			char[] line=fs.next().toCharArray();
			for (int x=0; x<width; x++)
				board[x][y]=line[x]=='*';
		}
		long[][] xMoves=new long[width][height];
		long oo=1_000_000_000_000_000_000l;
		for (int x=0; x<width; x++)
			Arrays.fill(xMoves[x], oo);
		
		PriorityQueue<Spot> pq=new PriorityQueue<>();
		xMoves[startX][startY]=0;
		pq.add(new Spot(startX, startY, 0));
		while (!pq.isEmpty()) {
			Spot next=pq.remove();
			if (xMoves[next.x][next.y]!=next.xMoves)
				continue;
			if (valid(next.x, next.y-1, board) && xMoves[next.x][next.y-1]>next.xMoves) {
				xMoves[next.x][next.y-1]=next.xMoves;
				pq.add(new Spot(next.x, next.y-1, next.xMoves));
			}
			if (valid(next.x, next.y+1, board) && xMoves[next.x][next.y+1]>next.xMoves) {
				xMoves[next.x][next.y+1]=next.xMoves;
				pq.add(new Spot(next.x, next.y+1, next.xMoves));
			}
			if (valid(next.x-1, next.y, board) && xMoves[next.x-1][next.y]>next.xMoves+1) {
				xMoves[next.x-1][next.y]=next.xMoves+1;
				pq.add(new Spot(next.x-1, next.y, next.xMoves+1));
			}
			if (valid(next.x+1, next.y, board) && xMoves[next.x+1][next.y]>next.xMoves+1) {
				xMoves[next.x+1][next.y]=next.xMoves+1;
				pq.add(new Spot(next.x+1, next.y, next.xMoves+1));
			}
		}
		
	/*	for (int y=0; y<height; y++) {
			for (int x=0; x<width; x++) {
				System.out.print(xMoves[x][y]+" ");
			}
			System.out.println();
		}*/
		int totalCount=0;
		for (int x=0; x<width; x++) {
			for (int y=0; y<height; y++) {
				long dx=xMoves[x][y];
				int diff=Math.abs(startX-x);
				long other=(dx-diff)/2;
				if (moveLeftTimes<other || moveRightTimes<other)
					continue;
				if (x<startX) {
					if (moveLeftTimes<other+diff)
						continue;
				}
				else {
					if (moveRightTimes<other+diff)
						continue;
				}
				totalCount++;
			}
		}
		System.out.println(totalCount);
	}
	
	static class Spot implements Comparable<Spot> {
		int xMoves, x, y;
		public Spot(int x, int y, int xMoves) {
			this.x=x;
			this.y=y;
			this.xMoves=xMoves;
		}
		
		public int compareTo(Spot o) {
			return Integer.compare(xMoves, o.xMoves);
		}
	}
	
	static boolean valid(int x, int y, boolean[][] board) {
		if (x<0||y<0||x>=board.length||y>=board[x].length||board[x][y])
			return false;
		return true;
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
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
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}
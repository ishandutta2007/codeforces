import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int height=fs.nextInt(), width=fs.nextInt();
		boolean[][] board=new boolean[width][height];
		for (int y=0; y<height; y++) {
			char[] line=fs.next().toCharArray();
			for (int x=0; x<width; x++)
				board[x][y]=line[x]=='*';
		}
		
		int[][] starLineLeft=new int[width][height], starLineRight=new int[width][height];
		int[][] starLineUp=new int[width][height], starLineDown=new int[width][height];
		for (int x=0; x<width; x++) {
			for (int y=0; y<height; y++) {
				if (x==0)
					starLineLeft[x][y]=board[x][y]?1:0;
				else
					starLineLeft[x][y]=board[x][y]?1+starLineLeft[x-1][y]:0;
				if (y==0)
					starLineUp[x][y]=board[x][y]?1:0;
				else
					starLineUp[x][y]=board[x][y]?1+starLineUp[x][y-1]:0;
			}
		}
		for (int x=width-1; x>=0; x--) {
			for (int y=height-1; y>=0; y--) {
				if (x==width-1)
					starLineRight[x][y]=board[x][y]?1:0;
				else
					starLineRight[x][y]=board[x][y]?1+starLineRight[x+1][y]:0;
				if (y==height-1)
					starLineDown[x][y]=board[x][y]?1:0;
				else
					starLineDown[x][y]=board[x][y]?1+starLineDown[x][y+1]:0;
			}
		}
		
		ArrayList<Event>[] eventsOnX=new ArrayList[width];
		for (int i=0; i<width; i++)
			eventsOnX[i]=new ArrayList<>();
		ArrayList<Event>[] eventsOnY=new ArrayList[height];
		for (int i=0; i<height; i++)
			eventsOnY[i]=new ArrayList<>();
		
		int starCount=0;
		for (int x=0; x<width; x++) {
			for (int y=0; y<height; y++) {
				int radius=Math.min(Math.min(starLineLeft[x][y], starLineRight[x][y]), Math.min(starLineUp[x][y], starLineDown[x][y]));
				if (radius>=2) {
					starCount++;
					int startX=x-radius+1;
					int endX=x+radius-1;
					int startY=y-radius+1;
					int endY=y+radius-1;
					eventsOnX[x].add(new Event(startY, 1));
					eventsOnX[x].add(new Event(endY+1, -1));
					eventsOnY[y].add(new Event(startX, 1));
					eventsOnY[y].add(new Event(endX+1, -1));
				}
			}
		}
		
		boolean[][] painted=new boolean[width][height];
		for (int x=0; x<width; x++) {
			Collections.sort(eventsOnX[x]);
			int index=0;
			int numIn=0;
			for (int y=0; y<height; y++) {
				while (index<eventsOnX[x].size()&&eventsOnX[x].get(index).pos==y) {
					numIn+=eventsOnX[x].get(index).delta;
					index++;
				}
				if (numIn>0) {
					painted[x][y]=true;
				}
			}
		}
		for (int y=0; y<height; y++) {
			Collections.sort(eventsOnY[y]);
			int index=0;
			int numIn=0;
			for (int x=0; x<width; x++) {
				while (index<eventsOnY[y].size()&&eventsOnY[y].get(index).pos==x) {
					numIn+=eventsOnY[y].get(index).delta;
					index++;
				}
				if (numIn>0) {
					painted[x][y]=true;
				}
			}
		}
		
		for (int x=0; x<width; x++) {
			for (int y=0; y<height; y++) {
				if (board[x][y]^painted[x][y]) {
					System.out.println(-1);
					return;
				}
			}
		}
		PrintWriter out=new PrintWriter(System.out);
		out.println(starCount);
		for (int x=0; x<width; x++) {
			for (int y=0; y<height; y++) {
				int radius=Math.min(Math.min(starLineLeft[x][y], starLineRight[x][y]), Math.min(starLineUp[x][y], starLineDown[x][y]));
				if (radius>=2) {
					out.println((y+1)+" "+(x+1)+" "+(radius-1));
				}
			}
		}
		out.close();
	}
	
	static class Event implements Comparable<Event> {
		int pos;
		int delta;
		
 		public Event(int pos, int delta) {
 			this.pos=pos;
 			this.delta=delta;
 		}
 		
 		public int compareTo(Event o) {
 			return Integer.compare(pos, o.pos);
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
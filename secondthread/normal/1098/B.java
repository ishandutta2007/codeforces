import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class NiceTable {

	static int[][] bestAns;
	static int leastChanged;
	static int w, h;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		h=fs.nextInt(); w=fs.nextInt();
		int[][] board=new int[w][h];
		String letters="ACGT";
		for (int y=0; y<h; y++) {
			String next=fs.next();
			for (int x=0; x<w; x++) {
				board[x][y]=letters.indexOf(next.charAt(x)+"");
			}
		}
		leastChanged=w*h;
		solveHLines(board, 0, 1);
		solveHLines(board, 0, 2);
		solveHLines(board, 0, 3);
		solveHLines(board, 1, 2);
		solveHLines(board, 1, 3);
		solveHLines(board, 2, 3);
		solveVLines(board, 0, 1);
		solveVLines(board, 0, 2);
		solveVLines(board, 0, 3);
		solveVLines(board, 1, 2);
		solveVLines(board, 1, 3);
		solveVLines(board, 2, 3);
		PrintWriter out=new PrintWriter(System.out);
		for (int y=0; y<h; y++) {
			for (int x=0; x<w; x++) {
				char toPrint=letters.charAt(bestAns[x][y]);
				out.print(toPrint);
			}
			out.println();
		}
		out.close();
//		System.err.println(leastChanged);
	}
	
	static void solveHLines(int[][] board, int topA, int topB) {
		boolean[] isTop=new boolean[4];
		isTop[topA]=isTop[topB]=true;
		int bottomA=-1, bottomB=-1;
		int[][] myAns=new int[board.length][board[0].length];
		for (int i=0; i<4; i++) if (!isTop[i]) if (bottomA==-1) bottomA=i; else bottomB=i;
		for (int y=0; y<h; y+=2) {
			int stayCount=0, moveCount=0;
			for (int x=0; x<w; x++) {
				if (board[x][y]==topA&&x%2==0) stayCount++;
				if (board[x][y]==topB&&x%2==1) stayCount++;
				if (board[x][y]==topA&&x%2==1) moveCount++;
				if (board[x][y]==topB&&x%2==0) moveCount++;
			}
			if (stayCount>=moveCount) {
				for (int x=0; x<w; x++)
					myAns[x][y]=x%2==0?topA:topB;
			}
			else {
				for (int x=0; x<w; x++)
					myAns[x][y]=x%2==0?topB:topA;
			}
			if (y+1<h) {
			stayCount=moveCount=0;
			for (int x=0; x<w; x++) {
				if (board[x][y+1]==bottomA&&x%2==0) stayCount++;
				if (board[x][y+1]==bottomB&&x%2==1) stayCount++;
				if (board[x][y+1]==bottomA&&x%2==1) moveCount++;
				if (board[x][y+1]==bottomB&&x%2==0) moveCount++;
			}
			if (stayCount>=moveCount) {
				for (int x=0; x<w; x++)
					myAns[x][y+1]=x%2==0?bottomA:bottomB;
			}
			else {
				for (int x=0; x<w; x++)
					myAns[x][y+1]=x%2==0?bottomB:bottomA;
			}
			}
		}
		int missCount=0;
		for (int x=0; x<w; x++) 
			for (int y=0; y<h; y++)
				if (myAns[x][y]!=board[x][y]) missCount++;
		if (missCount<leastChanged) {
			leastChanged=missCount;
			bestAns=myAns;
		}
	}
	static void solveVLines(int[][] board, int topA, int topB) {
		boolean[] isTop=new boolean[4];
		isTop[topA]=isTop[topB]=true;
		int bottomA=-1, bottomB=-1;
		int[][] myAns=new int[board.length][board[0].length];
		for (int i=0; i<4; i++) if (!isTop[i]) if (bottomA==-1) bottomA=i; else bottomB=i;
		for (int y=0; y<w; y+=2) {
			int stayCount=0, moveCount=0;
			for (int x=0; x<h; x++) {
				if (board[y][x]==topA&&x%2==0) stayCount++;
				if (board[y][x]==topB&&x%2==1) stayCount++;
				if (board[y][x]==topA&&x%2==1) moveCount++;
				if (board[y][x]==topB&&x%2==0) moveCount++;
			}
			if (stayCount>=moveCount) {
				for (int x=0; x<h; x++)
					myAns[y][x]=x%2==0?topA:topB;
			}
			else {
				for (int x=0; x<h; x++)
					myAns[y][x]=x%2==0?topB:topA;
			}
			if (y+1<w) {
			stayCount=moveCount=0;
			for (int x=0; x<h; x++) {
				if (board[y+1][x]==bottomA&&x%2==0) stayCount++;
				if (board[y+1][x]==bottomB&&x%2==1) stayCount++;
				if (board[y+1][x]==bottomA&&x%2==1) moveCount++;
				if (board[y+1][x]==bottomB&&x%2==0) moveCount++;
			}
			if (stayCount>=moveCount) {
				for (int x=0; x<h; x++)
					myAns[y+1][x]=x%2==0?bottomA:bottomB;
			}
			else {
				for (int x=0; x<h; x++)
					myAns[y+1][x]=x%2==0?bottomB:bottomA;
			}
			}
		}
		int missCount=0;
		for (int x=0; x<w; x++) 
			for (int y=0; y<h; y++)
				if (myAns[x][y]!=board[x][y]) missCount++;
		if (missCount<leastChanged) {
			leastChanged=missCount;
			bestAns=myAns;
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
	}

}
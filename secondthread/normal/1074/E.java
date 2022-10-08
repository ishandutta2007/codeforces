import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class _LiftLevel5E {

	static boolean[][] locked;
	static int[][] board;
	static int[][] solved;
	static int w, h;
	static ArrayList<String> answer=new ArrayList<>();
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		h=fs.nextInt(); w=fs.nextInt();
		board=new int[w][h];
		solved=new int[w][h];
		locked=new boolean[w][h];
		for (int y=0; y<h; y++) {
			for (int x=0; x<w; x++) {
				board[x][y]=fs.nextInt();
				solved[x][y]=x+y*w+1;	
			}
		}
		//solve ys [0, h-2)
		for (int yToSolveFor=0; yToSolveFor<h-2; yToSolveFor++) {
			for (int xToSolveFor=0; xToSolveFor<w-1; xToSolveFor++) {
				naiveMoveToXFirst(solved[xToSolveFor][yToSolveFor], xToSolveFor, yToSolveFor);
				locked[xToSolveFor][yToSolveFor]=true;
			}
			//now handle the rightmost position
			if (board[w-1][yToSolveFor]==solved[w-1][yToSolveFor]) {
				locked[w-1][yToSolveFor]=true;
				continue;
			}
			naiveMoveToXFirst(solved[w-1][yToSolveFor], w-1, h-1);
			hardCW4(w-2, yToSolveFor);
			naiveMoveToXFirst(solved[w-1][yToSolveFor], w-1, yToSolveFor+1);
			hardCCW4(w-2, yToSolveFor);
			locked[w-2][yToSolveFor]=locked[w-1][yToSolveFor]=true;
		}
//		print(board);
		
		//now we only have the last two ys left
		for (int x=0; x<w-2; x++) {
//			print(board);
			naiveMoveToXFirst(solved[x][h-1], x, h-1);
			if (solved[x][h-2]==board[x][h-2]) {
				locked[x][h-1] = locked[x][h-2]=true;
				continue;
			}
			locked[x][h-2] = true;
			naiveMoveToXFirst(solved[x][h-2], w-1, h-1);
			hardCW4(x, h-2);
			naiveMoveToXFirst(solved[x][h-2], x+1, h-2);
			hardCCW4(x, h-2);
			locked[x][h-1]=true;
		}
		
		//TODO: handle the last 4 spaces
		while (board[w-2][h-2]!=solved[w-2][h-2]) {
			hardCW4(w-2, h-2);
		}
		int target=solved[w-1][h-2];
		if (board[w-1][h-2]==target) {
			
		}
		else if (board[w-2][h-1]==target) {
			swapBottom2();
			swapRight2();
		}
		else {
			swapRight2();
		}
		target=solved[w-2][h-1];
		if (board[w-2][h-1]==target) {
			
		}
		else {
			swapBottom2();
		}
		System.out.println(answer.size());
		for (String s:answer) {
			System.out.println(s);
		}
//		print(board);
	}
	
	static void sixCycle() {
		hardCCW4(w-2, h-2);
		hardCCW4(w-3, h-2);
		moveNoWarnings(w-3, h-2, w-2, h-2, w-1, h-2,
				w-1, h-1, w-2, h-1, w-3, h-1);
	}
	
	static void swapRight2() {
		hardCCW4(w-2, h-2);
		sixCycle();
		hardCW4(w-2, h-2);
	}
	
	static void swapLeft2() {
		hardCW4(w-2, h-2);
		sixCycle();
		hardCCW4(w-2, h-2);
	}
	
	static void swaptTop2() {
		sixCycle();
	}
	
	static void swapBottom2() {
		hardCW4(w-2, h-2);
		hardCW4(w-2, h-2);
		sixCycle();
		hardCCW4(w-2, h-2);
		hardCCW4(w-2, h-2);
	}
	
	static boolean movable(int x, int y) {
		if (x< 0 || x>=locked.length || y<0 || y>=locked[x].length) return false;
		return !locked[x][y];
	}
	
	//moves x first then y
	static void naiveMoveToXFirst(int toMove, int targetX, int targetY) {
		Point curPos=locationOf(toMove);
		int curX=curPos.x;
		int curY=curPos.y;
		while (curX<targetX) {
			moveRight(curX, curY);
			curX++;
		}
		while (curX>targetX) {
			moveLeft(curX, curY);
			curX--;
		}
		while (curY<targetY) {
			moveDown(curX, curY);;
			curY++;
		}
		while (curY>targetY) {
			moveUp(curX, curY);
			curY--;
		}
	}
	
	static void moveLeft(int x, int y) {
		if (!movable(x, y) || !movable(x-1, y)) {
			throw null;
		}
		if (movable(x-1, y+1) && movable(x, y+1)) {
			move(x, y, x-1, y, x-1, y+1, x, y+1);
			return;
		}
		if (movable(x-1, y-1) && movable(x-1, y-1)) {
			move(x, y, x-1, y, x-1, y-1, x, y-1);
			return;
		}
		throw null;
	}
	
	static void moveRight(int x, int y) {
		if (!movable(x, y) || !movable(x+1, y)) {
			throw null;
		}
		if (movable(x+1, y+1) && movable(x, y+1)) {
			move(x, y, x+1, y, x+1, y+1, x, y+1);
			return;
		}
		if (movable(x+1, y-1) && movable(x, y-1)) {
			move(x, y, x+1, y, x+1, y-1, x, y-1);
			return;
		}
//		System.out.println("Trying to move right on pos: "+x+" "+y+" but it is impossible");
//		print(locked);
		throw null;
	}
	
	static void moveDown(int x, int y) {
		if (!movable(x, y) || !movable(x, y+1)) {
			throw null;
		}
		if (movable(x-1, y+1) && movable(x-1, y)) {
			move(x, y, x, y+1, x-1, y+1, x-1, y);
			return;
		}
		if (movable(x+1, y+1) && movable(x+1, y)) {
			move(x, y, x, y+1, x+1, y+1, x+1, y);
			return;
		}
		throw null;
	}

	static void moveUp(int x, int y) {
		if (!movable(x, y) || !movable(x, y-1)) {
			throw null;
		}
		if (movable(x-1, y-1) && movable(x-1, y)) {
			move(x, y, x, y-1, x-1, y-1, x-1, y);
			return;
		}
		if (movable(x+1, y-1) && movable(x+1, y)) {
			move(x, y, x, y-1, x+1, y-1, x+1, y);
			return;
		}
		throw null;
	}
	
	static void move(int ...input) {
		if (input.length%2!=0) throw null;
		int[] xs=new int[input.length/2], ys=new int[input.length/2];
		for (int i=0; i<input.length; i+=2) {
			xs[i/2]=input[i];
			ys[i/2]=input[i+1];
		}
		int nPoints=input.length/2;
		for (int i=0; i<nPoints; i++) {
			if (!movable(xs[i], ys[i])) throw null;
		}
		int[] old=new int[nPoints];
		for (int i=0; i<nPoints; i++) old[i]=board[xs[i]][ys[i]];
		for (int i=0; i<nPoints; i++) board[xs[i]][ys[i]] = old[(i-1+nPoints)%nPoints];
		StringBuilder sb=new StringBuilder(nPoints+" ");
		for (int i:old) {
			sb.append(i+" ");
		}
		answer.add(sb.toString());
	}
	
	static void moveNoWarnings(int ...input) {
		if (input.length%2!=0) throw null;
		int[] xs=new int[input.length/2], ys=new int[input.length/2];
		for (int i=0; i<input.length; i+=2) {
			xs[i/2]=input[i];
			ys[i/2]=input[i+1];
		}
		int nPoints=input.length/2;
		int[] old=new int[nPoints];
		for (int i=0; i<nPoints; i++) old[i]=board[xs[i]][ys[i]];
		for (int i=0; i<nPoints; i++) board[xs[i]][ys[i]] = old[(i-1+nPoints)%nPoints];
		StringBuilder sb=new StringBuilder(nPoints+" ");
		for (int i:old) {
			sb.append(i+" ");
		}
		answer.add(sb.toString());
	}
	
	static void hardCW4(int topLeftX, int topLeftY) {
		moveNoWarnings(topLeftX, topLeftY, topLeftX+1, topLeftY, topLeftX+1, topLeftY+1, topLeftX, topLeftY+1);
	}
	
	static void hardCCW4(int topLeftX, int topLeftY) {
		moveNoWarnings(topLeftX, topLeftY, topLeftX, topLeftY+1, topLeftX+1, topLeftY+1, topLeftX+1, topLeftY);
	}
	
	static Point locationOf(int i) {
		for(int x=0; x<w; x++) {
			for (int y=0; y<h; y++) {
				if (board[x][y]==i) return new Point(x, y);
			}
		}
//		System.out.println("Couldn't find location of "+i+" in ");
//		print(board);
		throw null;
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreElements()) {
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
	}
	
	static class Point {
		int x, y;
		public Point(int x, int y) {
			this.x=x;
			this.y=y;
		}
	}
	
	static void print(int[][] board) {
		for (int y=0; y<board[0].length; y++) {
			for (int x=0; x<board.length; x++) System.out.print(board[x][y]+" ");
			System.out.println();
		}
		System.out.println();
	}
	static void print(boolean[][] board) {
		for (int y=0; y<board[0].length; y++) {
			for (int x=0; x<board.length; x++) System.out.print((board[x][y]?"*":"_")+" ");
			System.out.println();
		}
		System.out.println();
	}
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class A {

	static ArrayDeque<Move> moves=new ArrayDeque<>();
	static int n, nCars;
	static int[][] board;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		n=fs.nextInt();
		nCars=fs.nextInt();
		board=new int[n][4];
		for (int i=0; i<4; i++) {
			for (int j=0; j<n; j++) {
				board[j][i]=fs.nextInt();
			}
		}
		int totalFilled=0;
		if (nCars==2*n) {
			totalFilled+=fillSpaces();
			if (totalFilled==0) {
				System.out.println(-1);
				return;
			}
		}
		while (totalFilled<nCars) {
			totalFilled+=fillSpaces();
			rotateClock();
		}
		System.out.println(moves.size());
		while (!moves.isEmpty()) {
			System.out.println(moves.remove());
		}
	}
	
	static void rotateClock() {
		int openX=0, openY=1;
		while (board[openX][openY]!=0) {
			openX++;
			if (openX>=n) {
				openX=0;
				openY++;
			}
		}
		
		int oOpenX=openX, oOpenY=openY;
		int lastX=openX, lastY=openY;
		if (openY==1) {
			openX++;
			if (openX==n) {
				openX=n-1;
				openY=2;
			}
		}
		else {
			openX--;
			if (openX==-1) {
				openX=0;
				openY=1;
			}
		}
		while (!(openX==oOpenX&&openY==oOpenY)) {
			if (board[openX][openY]!=0) {
				board[lastX][lastY]=board[openX][openY];
				board[openX][openY]=0;
				moves.add(new Move(board[lastX][lastY], lastY, lastX));
			}
			lastX=openX;
			lastY=openY;
			if (openY==1) {
				openX++;
				if (openX==n) {
					openX=n-1;
					openY=2;
				}
			}
			else {
				openX--;
				if (openX==-1) {
					openX=0;
					openY=1;
				}
			}
		}
	}
	
	static int fillSpaces() {
		int count=0;
		for (int i=0; i<n; i++) {
			if (board[i][0]!=0&&board[i][0]==board[i][1]) {
				moves.add(new Move(board[i][0], 0, i));
				count++;
				board[i][1]=0;
			}
			if (board[i][2]!=0&&board[i][2]==board[i][3]) {
				count++;
				moves.add(new Move(board[i][2], 3, i));
				board[i][2]=0;
			}
		}
		return count;
	}
	
	static class Move {
		int car;
		int toR, toC;
		public Move(int car, int toR, int toC) {
			this.car=car;
			this.toR=toR;
			this.toC=toC;
		}
		
		public String toString() {
			return car+" "+(toR+1)+" "+(toC+1);	
		}
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
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}

}
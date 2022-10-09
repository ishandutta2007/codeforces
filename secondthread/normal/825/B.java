import java.util.Scanner;

public class FiveInARow {
	
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		char[][] board=new char[10][10];
		for (int y=0; y<10; y++) {
			String line=s.nextLine();
			for (int x=0; x<10; x++) {
				board[x][y]=line.charAt(x);
			}
		}
		
		for (int x=0; x<10; x++) {
			for (int y=0; y<10; y++) {
				if (board[x][y]=='.') {
					board[x][y]='X';
					if (gameOver(board)) {
						System.out.println("YES");
						return;
					}
					board[x][y]='.';
				}
			}
		}
		System.out.println("NO");
	}

	private static boolean gameOver(char[][] board) {
		for (int topLeftX=0; topLeftX<10; topLeftX++) {
			for (int topLeftY=0; topLeftY<10; topLeftY++) {
				if (checkHorizontalWin(board, topLeftX, topLeftY)) {
					return true;
				}
				if (checkVerticalWin(board, topLeftX, topLeftY)) {
					return true;
				}
				if (checkDiagonalLeftWin(board, topLeftX, topLeftY)) {
					return true;
				}
				if (checkDiagonalRightWin(board, topLeftX, topLeftY)) {
					return true;
				}
			}
		}
		return false;
	}
	
	private static boolean checkHorizontalWin(char[][] board, int x, int y) {
		for (int i=0; i<5; i++) {
			if (!isX(board, x+i, y)) {
				return false;
			}
		}
		return true;
	}
	
	private static boolean checkVerticalWin(char[][] board, int x, int y) {
		for (int i=0; i<5; i++) {
			if (!isX(board, x, y+i)) {
				return false;
			}
		}
		return true;
	}
	
	private static boolean checkDiagonalRightWin(char[][] board, int x, int y) {
		for (int i=0; i<5; i++) {
			if (!isX(board, x+i, y+i)) {
				return false;
			}
		}
		return true;
	}
	
	private static boolean checkDiagonalLeftWin(char[][] board, int x, int y) {
		for (int i=0; i<5; i++) {
			if (!isX(board, x+i, y-i)) {
				return false;
			}
		}
		return true;
	}
	
	private static boolean isX(char[][] board, int x, int y) {
		if (x<0||y<0||x>=board.length||y>=board[0].length) {
			return false;
		}
		return board[x][y]=='X';
	}
	
}
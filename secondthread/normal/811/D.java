import java.awt.Point;
import java.util.Scanner;

public class Maze {

	private static boolean xFlipped=false, yFlipped=false;
	
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int height=s.nextInt();
		int width=s.nextInt();
		int finishX=0, finishY=0;
		s.nextLine();
		char[][] board=new char[width][height];
		for (int y=0; y<height; y++) {
			String line=s.nextLine();
			for (int x=0; x<width; x++) {
				board[x][y]=line.charAt(x);
				if (board[x][y]=='F') {
					finishX=x;
					finishY=y;
				}
			}
		}
		
		int[][] distance=new int[width][height];
		for (int i=0; i<width; i++) {
			for (int j=0; j<height; j++) {
				distance[i][j]=Integer.MAX_VALUE;
			}
		}
		search(distance, board, finishX, finishY, 0);
		
		for (int y=0; y<board[0].length; y++) {
			for (int x=0; x<board.length; x++) {
				//System.out.print(distance[x][y]%10+" ");
			}
			//System.out.println();
		}
		
		int playerX=0, playerY=0;
		while (playerX!=finishX||playerY!=finishY) {
			if (playerX>0&&distance[playerX][playerY]>distance[playerX-1][playerY]) {
				Point newPosition=move("left", playerX, playerY, s);
				playerX=newPosition.x;
				playerY=newPosition.y;
			}
			else if (playerY>0&&distance[playerX][playerY]>distance[playerX][playerY-1]) {
				Point newPosition=move("up", playerX, playerY, s);
				playerX=newPosition.x;
				playerY=newPosition.y;
			}
			else if (playerX<width-1&&distance[playerX][playerY]>distance[playerX+1][playerY]) {
				Point newPosition=move("right", playerX, playerY, s);
				playerX=newPosition.x;
				playerY=newPosition.y;
			}
			else if (playerY<height-1&&distance[playerX][playerY]>distance[playerX][playerY+1]) {
				Point newPosition=move("down", playerX, playerY, s);
				playerX=newPosition.x;
				playerY=newPosition.y;
			}
		}
		
	}
	
	private static void search(int[][] distance, char[][] board, int x, int y, int distanceCount) {
		if (x<0||y<0||x>=distance.length||y>=distance[0].length||board[x][y]=='*'||distance[x][y]<=distanceCount) {
			return;
		}
		distance[x][y]=distanceCount++;
		search(distance, board, x-1, y, distanceCount);
		search(distance, board, x+1, y, distanceCount);
		search(distance, board, x, y-1, distanceCount);
		search(distance, board, x, y+1, distanceCount);
	}

	public static Point move(String direction, int playerX, int playerY, Scanner s) {
		int newX, newY;
		switch(direction) {
			case "up":
				if (!yFlipped) {
					System.out.println("U");
				}
				else {
					System.out.println("D");
				}
				System.out.flush();
				newY=s.nextInt();
				newX=s.nextInt();
				if (newY!=playerY) {
					yFlipped^=true;
				}
				return new Point(newX-1, newY-1);
			case "down":
				if (!yFlipped) {
					System.out.println("D");
				}
				else {
					System.out.println("U");
				}
				System.out.flush();
				newY=s.nextInt();
				newX=s.nextInt();
				if (newY!=playerY+2) {
					yFlipped^=true;
				}
				return new Point(newX-1, newY-1);
			case "left":
				if (!xFlipped) {
					System.out.println("L");
				}
				else {
					System.out.println("R");
				}
				System.out.flush();
				newY=s.nextInt();
				newX=s.nextInt();
				if (newX!=playerX) {
					xFlipped^=true;
				}
				return new Point(newX-1, newY-1);
			case "right":
				if (!xFlipped) {
					System.out.println("R");
				}
				else {
					System.out.println("L");
				}
				System.out.flush();
				newY=s.nextInt();
				newX=s.nextInt();
				if (newX!=playerX+2) {
					xFlipped^=true;
				}
				return new Point(newX-1, newY-1);
				
		}
		return null;
	}
}
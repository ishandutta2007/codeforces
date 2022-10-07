import java.util.Scanner;

public class B038 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		boolean[][] board = new boolean[8][8];
		String rook = in.next(), knight = in.next();
		int rx = rook.charAt(0) - 'a', ry = rook.charAt(1) - '1';
		int kx = knight.charAt(0) - 'a', ky = knight.charAt(1) - '1';
		board[rx][ry] = board[kx][ky] = true;
		for (int x = 0; x < 8; x++) {
			board[rx][x] = board[x][ry] = true;
		}
		int[] mx = { -2, -1, 1, 2, 2, 1, -1, -2 };
		int[] my = { 1, 2, 2, 1, -1, -2, -2, -1 };
		for (int i = 0; i < 8; i++) {
			int x = kx + mx[i], y = ky + my[i];
			if (x < 0 || y < 0 || x >= 8 || y >= 8)
				continue;
			board[x][y] = true;
		}
		for (int i = 0; i < 8; i++) {
			int x = rx + mx[i], y = ry + my[i];
			if (x < 0 || y < 0 || x >= 8 || y >= 8)
				continue;
			board[x][y] = true;
		}
		int sum = 0;
		for(int x = 0;x<8;x++) {
			for(int y =0;y<8;y++) {
				if(!board[x][y]) sum++;
			}
		}
		System.out.println(sum);
	}
}
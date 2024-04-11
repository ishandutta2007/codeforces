import java.util.Scanner;

public class A014 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int r = in.nextInt(), c = in.nextInt();
		int minx = r, maxx = 0, miny = c, maxy = 0;
		boolean[][] grid = new boolean[r][c];
		for (int x = 0; x < r; x++) {
			String next = in.next();
			for (int y = 0; y < c; y++) {
				grid[x][y]=next.charAt(y)=='*';
				if (next.charAt(y) == '*') {
					if (x < minx)
						minx = x;
					if (x > maxx)
						maxx = x;
					if (y < miny)
						miny = y;
					if (y > maxy)
						maxy = y;
				}
			}
		}
		for(int x=minx;x<=maxx;x++) {
			for(int y = miny;y<=maxy;y++) {
				System.out.print(grid[x][y]?'*':'.');
			}
			System.out.println();
		}
	}
}
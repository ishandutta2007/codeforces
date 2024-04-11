import java.util.Scanner;

public class B006 {
	static boolean[][] visited;
	static int[][] grid;
	static boolean[] counted;
	static int count;
	static int n, m;
	static int pres;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		m = in.nextInt();
		pres = in.next().charAt(0);
		grid = new int[n][m];
		counted = new boolean[9001];
		visited = new boolean[n][m];
		count = 0;
		for (int x = 0; x < n; x++) {
			String line = in.next();
			for (int y = 0; y < m; y++) {
				grid[x][y] = line.charAt(y);
			}
		}
		c: for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (grid[x][y] == pres) {
					visit(x, y);
					break c;
				}
			}
		}
		System.out.println(count);
	}

	static void visit(int x, int y) {
		if (x < 0 || y < 0 || x >= n || y >= m) {
			return;
		}

		if (visited[x][y]) {
			return;
		}
		visited[x][y] = true;
		int k = grid[x][y];
		if (k == '.') {
			return;
		}
		if (k == pres) {
			int[] mx = { 0, 0, -1, 1 };
			int[] my = { 1, -1, 0, 0 };
			for (int i = 0; i < 4; i++) {
				int xx = mx[i] + x;
				int yy = my[i] + y;
				visit(xx, yy);
			}
		} else {
			if (!counted[k]) {
				counted[k] = true;
				count++;
			}
		}
	}
}
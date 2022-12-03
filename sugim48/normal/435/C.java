import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		
		int x = 0, y = 0;
		int minY = 0, maxY = 0;
		for (int i = 0; i < n; i++) {
			x += a[i];
			if (i % 2 == 0) {
				y += a[i];
				maxY = Math.max(maxY, y);
			} else {
				y -= a[i];
				minY = Math.min(minY, y);
			}
		}
		
		int h = maxY - minY, w = x;
		boolean[][] b = new boolean[h + 1][w + 1];
		x = 0;
		y = -minY;
		b[y][x] = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < a[i]; j++) {
				x += 1;
				if (i % 2 == 0) {
					y += 1;
				} else {
					y -= 1;
				}
				b[y][x] = true;
			}
		}
		
		for (int i = 0; i < h; i++) {
			String s = "";
			for (int j = 0; j < w; j++) {
				if (b[h - i][j] && b[h - i - 1][j + 1]) {
					s += '\\';
				} else if (b[h - i - 1][j] && b[h - i][j + 1]) {
					s += '/';
				} else {
					s += ' ';
				}
			}
			System.out.println(s);
		}
	}
}

/*

import java.util.*;

public class Main {
	public static void main(String[] args) {
		int[] dy = {0, 1, 1, 1, 0, -1, -1, -1};
		int[] dx = {1, 1, 0, -1, -1, -1, 0, 1};
		
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		boolean[][] a = new boolean[n][m];
		for (int i = 0; i < n; i++) {
			String line = in.next();
			for (int j = 0; j < m; j++) {
				a[i][j] = (line.charAt(j) == '1');
			}
		}
		
		int[][][] b = new int[n][m][8];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 8; k++) {
					b[i][j][k] = -1;
					int y = i, x = j;
					while (y >= 0 && y < n && x >= 0 && x < m && !a[y][x]) {
						b[i][j][k]++;
						y += dy[k];
						x += dx[k];
					}
				}
			}
		}
		
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 8; k++) {
					int k1 = k;
					int k2 = (k + 2) % 8;
					int k3 = (k + 3) % 8;
					for (int l = 1; l <= b[i][j][k1] && l <= b[i][j][k2]; l++) {
						if (b[i + l * dy[k1]][j + l * dx[k1]][k3] >= l) {
							ans++;
						}
					}
				}
			}
		}
		
		System.out.println(ans);
	}
}

*/
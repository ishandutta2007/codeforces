import java.util.Scanner;

public class B048 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		boolean[][] tree = new boolean[n][m];
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				tree[x][y] = in.nextInt() == 1;
			}
		}
		int a = in.nextInt();
		int b = in.nextInt();
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < 2; i++) {
			if (i == 1) {
				int c = a;
				a = b;
				b = c;
			}
			for (int x = 0; x + a - 1 < n; x++) {
				for (int y = 0; y + b - 1 < m; y++) {
					int sum = 0;
					for (int xx = x; xx < x + a; xx++) {
						for (int yy = y; yy < y + b; yy++) {
							if (tree[xx][yy])
								sum++;
						}
					}
					if (sum < min)
						min = sum;
				}
			}
		}
		System.out.println(min);
	}
}
import java.util.Scanner;

public class A102 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), m = in.nextInt();
		int[] prices = new int[n];
		boolean[][] adj = new boolean[n][n];
		for (int x = 0; x < n; x++) {
			prices[x] = in.nextInt();
		}
		for (int x = 0; x < m; x++) {
			int a = in.nextInt() - 1, b = in.nextInt() - 1;
			adj[a][b] = adj[b][a] = true;
		}
		int min = -1;
		for (int a = 0; a < n; a++) {
			for (int b = a + 1; b < n; b++) {
				for (int c = b + 1; c < n; c++) {
					if (adj[a][b] && adj[a][c] && adj[b][c]) {
						int sum = prices[a] + prices[b] + prices[c];
						if (min==-1||sum < min)
							min = sum;
					}
				}
			}
		}
		System.out.println(min);
	}
}
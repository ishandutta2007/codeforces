import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int[] v = new int[n];
		for (int i = 0; i < n; i++) {
			v[i] = in.nextInt();
		}
		boolean[][] adj = new boolean[n][n];
		for (int j = 0; j < m; j++) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			adj[x][y] = true;
			adj[y][x] = true;
		}
		
		int[][] a = new int[n][2];
		for (int i = 0; i < n; i++) {
			a[i][0] = i;
			a[i][1] = v[i];
		}
		Comparator<int[]> cmp = new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -Integer.compare(a[1], b[1]);
			}
		};
		Arrays.sort(a, cmp);
		
		long ans = 0;
		for (int i = 0; i < n; i++) {
			int _i = a[i][0];
			for (int j = 0; j < n; j++) {
				if (adj[_i][j]) {
					adj[_i][j] = false;
					adj[j][_i] = false;
					ans += v[j];
				}
			}
		}
		
		System.out.println(ans);
	}
}
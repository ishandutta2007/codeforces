import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		char[][] a = new char[n][m];
		for (int i = 0; i < n; i++) {
			String s = in.next();
			for (int j = 0; j < m; j++) {
				a[i][j] = s.charAt(j);
			}
		}
		
		for (int j = 0; j < m; j++) {
			int ans = 0;
			for (int l = 1; l < n; l++) {
				if (l * 2 < n && a[l * 2][j] == 'U') {
					ans++;
				}
				if (j - l >= 0 && a[l][j - l] == 'R') {
					ans++;
				}
				if (j + l < m && a[l][j + l] == 'L') {
					ans++;
				}
			}
			System.out.print(ans + " ");
		}
		System.out.print("\n");
	}
}
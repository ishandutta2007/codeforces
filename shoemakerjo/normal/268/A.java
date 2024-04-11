import java.util.Scanner;

public class Games {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[][] col = new int[n][2];
		for (int i = 0; i < n; i++) {
			col[i][0] = s.nextInt();
			col[i][1] = s.nextInt();
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j!=i) {
					if (col[i][0] == col[j][1]) ans++;
				}
			}
		}
		System.out.println(ans);

	}

}
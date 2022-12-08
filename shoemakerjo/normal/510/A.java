import java.util.Scanner;

public class FoxAndSnake {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		char[][] ans = new char[n][m];
		for (int i = 0; i < n; i++) {
			if (i%4==1) {
				for (int j = 0; j < m; j++) ans[i][j] = '.';
				ans[i][m-1]='#';
			}
			else if (i%4==3) {
				for (int j = 0; j < m; j++) ans[i][j] = '.';
				ans[i][0]='#';
			}
			else {
				for (int j = 0; j < m; j++) ans[i][j] = '#';
				
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				System.out.print(ans[i][j]);
			}
			System.out.println();
		}

	}

}
import java.util.Arrays;
import java.util.Scanner;

public class GravityFlip {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[] original = new int[n+1];
		int rows = 0;
		for (int i = 1; i <= n; i++) {
			original[i] = s.nextInt();
			rows = Math.max(rows, original[i]);
		}
		int[] row = new int[rows+1];
		int[] ans = new int[n+1];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= original[i]; j++) {
				row[j]++;
			}
		}
		for (int i = 1; i <= rows; i++) {
			for (int j = 1; j <= row[i]; j++) {
				ans[j]++;
			}
		}
		for (int i = n; i >= 1; i--) {
			System.out.print(ans[i]);
			if (i> 1) System.out.print(" ");
		}
		System.out.println();

	}

}
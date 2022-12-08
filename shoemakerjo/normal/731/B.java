import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class coupons {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[] nums = new int[n];
		for (int i = 0; i < n; i++) {
			nums[i] = s.nextInt();
		}
		boolean good = true;
		for (int j = 0; j < n; j++) {
			if (nums[j] % 2 == 1) {
				if (j==n-1) good = false;
				else if (j < n - 1 && nums[j+1] > 0) {
					nums[j+1]--;
				}
				else {
					good = false;
					break;
				}
			}
		}
		if (good) {
			System.out.println("YES");
		}
		else System.out.println("NO");

	}

}
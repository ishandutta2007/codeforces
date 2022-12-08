import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int n1 = s.nextInt();
		int n2 = s.nextInt();
		int lower = Math.min(n1, n2);
		int higher = Math.max(n1, n2);
		int[] nums = new int[n];
		for (int i = 0; i < n; i++) {
			nums[i] = s.nextInt();
		}
		Arrays.sort(nums);
		double ans = 0;
		for (int i = nums.length-1; i > nums.length-1-lower; i--){
			ans += (double)nums[i]/lower;
		}
		for (int i = nums.length-1-lower; i > nums.length-1 - lower-higher; i--) {
			ans += (double)nums[i]/higher;
		}
		System.out.printf("%.8f\n",ans);

	}

}
import java.util.Arrays;
import java.util.Scanner;

public class Twins {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[] nums = new int[n];
		int sum = 0;
		for (int i  = 0; i < n; i++) {
			int cur = s.nextInt();
			sum+=cur;
			nums[i] = cur;
		}
		Arrays.sort(nums);
		int cs = 0;
		int amount = 0;
		while (cs <= sum-cs) {
			cs+=nums[n-amount-1];
			amount++;
		}
		System.out.println(amount);
	
	}

}
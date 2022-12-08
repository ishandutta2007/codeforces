import java.util.Scanner;

public class Boredom {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		final int t5 = 100000;
		long[] nums = new long[t5+1];
		for (int i = 0; i < n; i++) {
			nums[s.nextInt()]++;
		}
		long[] dp = new long[t5+1];
		dp[0] = 0;
		dp[1] = 1*nums[1];
		for (int i = 2; i <= t5; i++) {
			dp[i] = Math.max(dp[i-1], dp[i-2]+nums[i]*i);
		}
		System.out.println(dp[t5]);
	}

}
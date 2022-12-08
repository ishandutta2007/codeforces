import java.util.Scanner;

public class CheapTravel {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		int a = s.nextInt();
		int b = s.nextInt();
		int[] ans = new int[n+m+1];
		ans[0] = 0;
		for (int i = 1; i <= n+m; i++) {
			ans[i] = Integer.MAX_VALUE;
			if (i-1 >= 0) {
				ans[i] = Math.min(ans[i], ans[i-1]+a);
			}
			if (i-m >= 0) {
				ans[i] = Math.min(ans[i], ans[i-m]+b);
			}
		}
		int answer = ans[n];
		for (int i = n+1; i <= n+m; i++) {
			answer = Math.min(answer, ans[i]);
		}
		System.out.println(answer);
	}

}
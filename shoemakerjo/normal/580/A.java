import java.util.Scanner;

public class KefaFirstSteps {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int ans = 0;
		int cur = 0;
		int prev = 0;
		for (int i = 0; i < n; i++) {
			int temp = s.nextInt();
			if (temp >= prev) cur++;
			else cur = 1;
			prev = temp;
			ans = Math.max(ans, cur);
		}
		System.out.println(ans);

	}

}
import java.util.Scanner;

public class NewYearHurry {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt(); //problems
		int k = s.nextInt();
		int left = 240-k;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (5*i <= left) {
				ans++;
				left-=5*i;
			}
			else break;
		}
		System.out.println(ans);

	}

}
import java.util.Scanner;

public class GeorgeAcc {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int p = s.nextInt();
			int q = s.nextInt();
			if (q-p >= 2) ans++;
		}
		System.out.println(ans);

	}

}
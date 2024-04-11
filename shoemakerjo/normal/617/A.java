import java.util.Scanner;

public class Elephant {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int x = s.nextInt();
		int[] ans = new int[x+1];
		for (int j = 0; j <=x;j ++) {
			ans[j] = Integer.MAX_VALUE/2;
		}
		ans[0] = 0;
		for (int i = 1; i <=x; i++) {
			if (i-1 >= 0) ans[i] = Math.min(ans[i-1]+1, ans[i]);
			if (i-2 >= 0) ans[i] = Math.min(ans[i-2]+1, ans[i]);
			if (i-3 >= 0) ans[i] = Math.min(ans[i-3]+1, ans[i]);
			if (i-4 >= 0) ans[i] = Math.min(ans[i-4]+1, ans[i]);
			if (i-5 >= 0) ans[i] = Math.min(ans[i-5]+1, ans[i]);

		}
		System.out.println(ans[x]);

	}

}
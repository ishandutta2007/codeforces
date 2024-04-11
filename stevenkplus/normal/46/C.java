import java.util.Scanner;

public class C046 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		String line = in.next();
		int[] k = new int[n];
		int sum = n;
		for (int x = 0; x < line.length(); x++) {
			sum -= k[x] = line.charAt(x) == 'T' ? 1 : 0;
		}
		int tot = sum;
		int min = Integer.MAX_VALUE;
		for (int x = 0; x < n; x++) {
			int s = 0;
			for (int y = 0; y < tot; y++) {
				int kk = x + y;
				kk %= n;
				s += k[kk];
			}
			if (s < min)
				min = s;
		}
		System.out.println(min);
	}
}
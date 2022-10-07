import java.util.Scanner;

public class A111 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long y = in.nextLong();
		int z = in.nextInt();
		long sum = n - 1;
		long diff = z - sum;
		if (diff <= 0) {
			System.out.println("-1");
			return;
		} else
			sum += diff * diff;
		if (sum < y) {
			System.out.println("-1");
		} else {
			for (int x = 0; x < n - 1; x++) {
				System.out.println(1);
			}
			System.out.println(diff);
		}
	}
}
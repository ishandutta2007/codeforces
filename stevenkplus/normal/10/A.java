import java.util.Scanner;

public class A010 {
	public static void main(String[] arsg) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), P1 = in.nextInt(), P2 = in.nextInt(), P3 = in
				.nextInt(), T1 = in.nextInt(), T2 = in.nextInt();
		long sum = 0;
		int prev = -1;
		for (int x = 0; x < n; x++) {
			int start = in.nextInt(), end = in.nextInt();
			if (prev == -1)
				prev = start;
			int diff = end - start;
			sum += diff * P1;
			diff = start - prev;
			if (diff > T1) {
				sum += T1 * P1;
				diff -= T1;
				if (diff > T2) {
					sum += T2 * P2;
					diff -= T2;
					sum += diff * P3;
				} else {
					sum += diff * P2;
				}
			} else {
				sum += diff * P1;
			}
			prev = end;
		}
		System.out.println(sum);
	}
}
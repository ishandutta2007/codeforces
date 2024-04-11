import java.util.Scanner;

public class A015 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), t = in.nextInt();
		int[] centers = new int[n], sides = new int[n];
		for (int x = 0; x < n; x++) {
			centers[x] = in.nextInt();
			sides[x] = in.nextInt();
		}
		int count = 0;

		big: for (int x = -4000; x <= 4000; x++) {
			boolean touch = false;
			for (int i = 0; i < n; i++) {
				int d = 2*centers[i] - x;
				d = d > 0 ? d : -d;
				int s = t + sides[i];
				if (s == d) {
					touch = true;
				} else if (s > d) {
					continue big;
				}
			}
			if (touch)
				count++;
		}
		System.out.println(count);
	}
}
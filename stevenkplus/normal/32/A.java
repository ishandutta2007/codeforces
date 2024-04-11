import java.util.Scanner;

public class A032 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), dist = in.nextInt();
		int count = 0;
		int[] ar = new int[n];
		for (int x = 0; x < n; x++) {
			int k = in.nextInt();
			for (int y = 0; y < x; y++) {
				int d = k - ar[y];
				if (d < 0)
					d = -d;
				if (d <= dist)
					count++;
			}
			ar[x] = k;
		}
		System.out.println(count*2);
	}
}
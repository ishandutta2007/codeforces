import java.util.Scanner;

public class B041 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), b = in.nextInt();
		int[] ar = new int[n];
		for (int x = 0; x < n; x++) {
			ar[x] = in.nextInt();
		}
		int max = 0;
		for (int x = 0; x < n; x++) {
			for (int y = x; y < n; y++) {
				int d = b / ar[x];
				int k = b - d * ar[x] + d * ar[y];
				if (k > max)
					max = k;
			}
		}
		System.out.println(max);
	}
}
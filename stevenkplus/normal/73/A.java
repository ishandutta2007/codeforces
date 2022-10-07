import java.util.Arrays;
import java.util.Scanner;

public class A073 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] ar = new int[3];
		for (int i = 0; i < 3; i++) {
			ar[i] = in.nextInt();
		}
		int k = in.nextInt();
		Arrays.sort(ar);
		long prod = 1;
		for (int x = 0; x < 3; x++) {
			int want = k / (3 - x);
			if (want >= ar[x]) {
				want = ar[x]-1;
			}
			prod *= (want + 1);
			k -= want;
		}
		System.out.println(prod);
	}
}
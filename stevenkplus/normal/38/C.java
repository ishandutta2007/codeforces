import java.util.Scanner;

public class C038 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), l = in.nextInt();
		int[] ar = new int[n];
		for (int x = 0; x < n; x++) {
			ar[x] = in.nextInt();
		}
		int max = 0;
		for (int length = l; length <=100; length++) {
			int count = 0;
			for (int p : ar) {
				count += p / length;
			}
			int are = count * length;
			if (are > max)
				max = are;
		}
		System.out.println(max);
	}
}
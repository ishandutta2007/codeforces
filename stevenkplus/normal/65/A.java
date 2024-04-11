import java.util.Scanner;

public class A065 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = 1, b = 1;
		int[] ar = new int[6];
		int j = 0;
		for (int i = 0; i < 3; i++) {
			a *= ar[j++] = in.nextInt();
			b *= ar[j++] = in.nextInt();
		}
		if (a == 0 && b == 0) {
			if (ar[3] > 0 && (ar[2] == 0 || (ar[0] == 0 && ar[1] > 0))) {
				System.out.println("Ron");
			} else
				System.out.println("Hermione");
		} else
			System.out.println(a < b ? "Ron" : "Hermione");
	}
}
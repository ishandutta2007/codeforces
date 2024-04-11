import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner fs = new Scanner(System.in);
		int n = fs.nextInt();
		int[] a = new int[n];
		boolean posContr = false, negContr = false;
		for (int i = 0; i < n; i++)
			a[i] = fs.nextInt();
		for (int i : a) {
			int res = i / 2;
			if (i % 2 != 0) {
				if (i > 0) {
					if (posContr) {
						res++;
					}
					posContr ^= true;
				} else {
					if (negContr) {
						res--;
					}
					negContr ^= true;
				}
			}
			System.out.println(res);
		}

	}

}
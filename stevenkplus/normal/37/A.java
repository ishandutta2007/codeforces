import java.util.Scanner;

public class A037 {
	public static void main(String[] args) throws Exception {
		int[] a = new int[5222];
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for (int x = 0; x < n; x++)
			a[in.nextInt()]++;
		int count = 0;
		int max = 0;
		for (int x = 0; x < a.length; x++)
			if (a[x] > 0) {
				count++;
				if (a[x] > max)
					max = a[x];
			}
		System.out.printf("%d %d\n", max, count);
	}
}
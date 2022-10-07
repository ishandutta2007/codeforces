import java.util.Scanner;

public class C009 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int c = 0;
		for (int x = 1; x < 2000; x++) {
			long k = Long.parseLong(Integer.toString(x, 2));
			if (k > n) {
				break;
			}
			c++;
		}
		System.out.println(c);
	}
}
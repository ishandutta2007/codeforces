import java.util.Arrays;
import java.util.Scanner;

public class A056 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		String[] ar = "ABSINTH, BEER, BRANDY, CHAMPAGNE, GIN, RUM, SAKE, TEQUILA, VODKA, WHISKEY, WINE"
				.split("\\s*,\\s*");
		int c = 0;
		for (int x = 0; x < n; x++) {
			String next = in.next();
			if (Character.isLetter(next.charAt(0))) {
				if (Arrays.binarySearch(ar, next) >= 0) {
					c++;
				}

			} else

			{
				int nn = Integer.parseInt(next);
				if(nn<18) c++;
			}
		}
		System.out.println(c);
	}
}
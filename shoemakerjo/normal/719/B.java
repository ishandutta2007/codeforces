import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class cockroach {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		s.nextLine();
		String line = s.nextLine();
		int odd_red = 0;
		int odd_blue = 0;
		int even_red = 0;
		int even_blue = 0;
		for (int i = 0; i < n; i++) {
			if (i%2==0) {
				if (line.charAt(i)=='r') even_red++;
				else even_blue++;
			}
			else {
				if (line.charAt(i)=='r') odd_red++;
				else odd_blue++;
			}
		}
		int red_blue = Math.max(even_red, odd_blue);
		int blue_red = Math.max(even_blue, odd_red);
		System.out.println(Math.min(red_blue, blue_red));

	}

}
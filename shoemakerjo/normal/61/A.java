import java.util.Scanner;

public class UltraFastMath {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String top = s.nextLine();
		String bot = s.nextLine();
		for (int i  = 0; i < top.length(); i++) {
			if (top.charAt(i)!=bot.charAt(i)) {
				System.out.print("1");
			}
			else System.out.print("0");
		}
		System.out.println();

	}

}
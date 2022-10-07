import java.util.Scanner;

public class A106 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String ranks = "6789TJQKA";
		char trump = in.next().charAt(0);
		String card1 = in.next();
		int r1 = ranks.indexOf(card1.charAt(0));
		char suit1 = card1.charAt(1);
		String card2 = in.next();
		int r2 = ranks.indexOf(card2.charAt(0));
		char suit2 = card2.charAt(1);
		if (suit1 == suit2) {
			System.out.println(r1 > r2 ? "YES" : "NO");
		} else if (suit1 == trump)
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}
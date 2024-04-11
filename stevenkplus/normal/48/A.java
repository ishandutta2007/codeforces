import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class A048 {
	public static void main(String[] args) {
		System.out.println(ans());
	}

	public static String ans() {
		Scanner in = new Scanner(System.in);
		ArrayList<String> str = new ArrayList<String>(
				Arrays.asList(new String[] { "rock", "scissors", "paper" }));
		int a = str.indexOf(in.next()), b = str.indexOf(in.next()), c = str
				.indexOf(in.next());
		if (a == b) {
			if (c == (b + 2) % 3)
				return "S";
		}
		if (a == c) {
			if (b == (a + 2) % 3)
				return "M";
		}
		if (b == c) {
			if (a == (b + 2) % 3)
				return "F";
		}
		return "?";
	}
}
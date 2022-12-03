import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s = in.next();
		int k = in.nextInt();
		for (; k > 0; k--) {
			s += "?";
		}
		for (int n = s.length() / 2; n >= 1; n--) {
			for (int j = 0; j <= s.length() - n * 2; j++) {
				boolean b = true;
				for (int i = 0; i < n; i++) {
					if (s.charAt(j + i + n) != '?' && s.charAt(j + i) != s.charAt(j + i + n)) {
						b = false;
					}
				}
				if (b) {
					System.out.println(n * 2);
					return;
				}
			}
		}
	}
}
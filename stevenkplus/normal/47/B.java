import java.util.Scanner;

public class B047 {
	public static void main(String[] args) {
		String[] pos = { "ABC", "ACB", "BAC", "BCA", "CAB", "CBA" };
		Scanner in = new Scanner(System.in);
		String[] first = new String[3], last = new String[3];
		boolean[] boo = new boolean[3];
		for (int x = 0; x < 3; x++) {
			String s = in.next();
			first[x] = s.charAt(0) + "";
			boo[x] = s.charAt(1) == '<';
			last[x] = s.charAt(2) + "";
		}
		big: for (int x = 0; x < 6; x++) {
			String s = pos[x];
			for (int i = 0; i < 3; i++) {
				if (s.indexOf(first[i]) < s.indexOf(last[i]) ^ boo[i]) {
					continue big;
				}
			}
			System.out.println(s);
			return;
		}
		System.out.println("Impossible");

	}
}
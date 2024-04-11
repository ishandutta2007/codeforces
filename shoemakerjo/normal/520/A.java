import java.util.Scanner;

public class Pangram {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		s.nextLine();
		String line = s.nextLine();
		boolean[] ans = new boolean[26];
		String low = "abcdefghijklmnopqrstuvwxyz";
		String up = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		for (int i = 0; i < n; i++) {
			int li = low.indexOf(line.charAt(i));
			int hi = up.indexOf(line.charAt(i));
			if (li >= 0) ans[li] = true;
			if (hi >= 0) ans[hi] = true;
		}
		boolean ok = true;
		for (int i = 0; i < 26; i++) {
			if (!ans[i]) ok = false;
		}
		if (ok) System.out.println("YES");
		else System.out.println("NO");

	}

}
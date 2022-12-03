import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s = in.nextLine();
		int n = s.length() / 3;
		boolean[] a = new boolean[26];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			char c = s.charAt(i * 3 + 1);
			if (!a[c - 'a']) {
				a[c - 'a'] = true;
				ans++;
			}
		}
		System.out.println(ans);
	}
}
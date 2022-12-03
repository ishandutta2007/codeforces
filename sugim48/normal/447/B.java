import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s = in.next();
		int k = in.nextInt();
		int[] w = new int[26];
		for (int c = 0; c < 26; c++) {
			w[c] = in.nextInt();
		}
		
		int f = 0;
		for (int i = 1; i <= s.length(); i++) {
			int c = s.charAt(i - 1) - 'a';
			f += w[c] * i;
		}
		Arrays.sort(w);
		for (int i = s.length() + 1; i <= s.length() + k; i++) {
			f += w[25] * i;
		}
		
		System.out.println(f);
	}
}
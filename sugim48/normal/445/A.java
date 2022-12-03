import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		for (int i = 0; i < n; i++) {
			String s = in.next();
			char[] c = s.toCharArray();
			for (int j = 0; j < m; j++) {
				if (c[j] == '.') {
					c[j] = ((i + j) % 2 == 0) ? 'W' : 'B';
				}
			}
			System.out.println(new String(c));
		}
	}
}
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int v = in.nextInt();
		
		int p = 0;
		StringBuilder s = new StringBuilder("");
		for (int i = 1; i <= n; i++) {
			int k = in.nextInt();
			boolean b = false;
			for (int j = 1; j <= k; j++) {
				if (in.nextInt() < v) {
					b = true;
				}
			}
			if (b) {
				p++;
				if (s.length() > 0) {
					s.append(" ");
				}
				s.append(i);
			}
		}
		
		System.out.println(p);
		System.out.println(s);
	}
}
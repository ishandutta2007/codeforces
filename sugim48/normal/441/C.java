import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		
		StringBuilder s = new StringBuilder("");
		int x = 1;
		int y = 1;
		for (int j = 1; j <= k; j++) {
			int r;
			if (j == k) {
				r = n * m - 2 * (k - 1);
			} else {
				r = 2;
			}
			s.append(r);
			
			for (int i = 0; i < r; i++) {
				s.append(" ");
				s.append(x);
				s.append(" ");
				s.append(y);
				
				if (x % 2 == 1) {
					if (y == m) {
						x++;
					} else {
						y++;
					}
				} else {
					if (y == 1) {
						x++;
					} else {
						y--;
					}
				}
			}
			
			s.append("\n");
		}
		
		System.out.print(s);
	}
}
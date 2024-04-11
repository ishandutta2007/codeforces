import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int sum = in.nextInt();
		int limit = in.nextInt();
		
		int size = 0;
		StringBuilder s = new StringBuilder("");
		for (int i = 65536; i >= 1; i /= 2) {
			for (int j = i; j <= limit; j += i * 2) {
				if (i <= sum) {
					sum -= i;
					if (size != 0) {
						s.append(" ");
					}
					s.append(j);
					size++;
				}
			}
		}
		
		if (sum == 0) {
			System.out.println(size);
			System.out.println(s);
		} else {
			System.out.println(-1);
		}
	}
}
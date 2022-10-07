import java.util.Scanner;

public class A053 {
	public static void main(String[] arsg) {
		Scanner in = new Scanner(System.in);
		String line = in.next();
		int num = in.nextInt();
		String best = null;
		for (int x = 0; x < num; x++) {
			String next = in.next();
			if (next.indexOf(line) == 0) {
				if (best == null || next.compareTo(best) < 0) {
					best = next;
				}
			}
		}
		if (best == null)
			best = line;
		System.out.println(best);
	}
}
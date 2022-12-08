import java.util.Scanner;

public class Magnets {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		String cur = s.nextLine();
		cur = s.nextLine();
		int groups = 1;
		String type = cur;
		for (int i = 0; i < n-1; i++) {
			cur = s.nextLine();
			if (!cur.equals(type)) {
				type = cur;
				groups++;
			}
		}
		System.out.println(groups);
	}

}
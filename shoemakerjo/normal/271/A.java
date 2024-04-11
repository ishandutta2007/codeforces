import java.util.Scanner;

public class BeautifulYear {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int cur = n+1;
		boolean found = false;
		while (!found) {
			String line = Integer.toString(cur);
			boolean good = true;
			for (int i = 0; i < line.length(); i++) {
				if (line.indexOf(line.charAt(i),i+1) >= 0) {
					good = false;
					break;
				}
			}
			if (good) {
				System.out.println(cur);
				found = true;
				break;
			}
			cur++;
		}

	}

}
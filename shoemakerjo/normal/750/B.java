import java.util.Scanner;

public class NewYearNorthPole {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		boolean pass = true;
		int x = 0;
		int y = 0;
		for (int i = 0; i < n; i++) {
			int dist = s.nextInt();
			String type = s.next();
//			System.out.println(x + " " + y);
			if (y==0 && !type.equals("South")) {
				pass = false;
				break;
			}
			if (y < -20000 || y > 0) {
				pass = false;
				break;
			}
			if (y ==-20000 && !type.equals("North")) {
				pass = false;
				break;
			}
			if (type.equals("South")) {
				y-=dist;
			}
			if (type.equals("North")) {
				y+=dist;
			}
			if (type.equals("East")) {
				x+=dist;
			}
			if (type.equals("West")) {
				x-=dist;
			}
		}
		if (y!=0) {
			pass = false;
		}
		if (pass) {
			System.out.println("YES");
		}
		else System.out.println("NO");

	}

}
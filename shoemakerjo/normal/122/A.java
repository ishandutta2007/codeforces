import java.util.Scanner;

public class LuckyDivision {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		boolean lucky = false;
		for (int i = 1; i <= n; i++) {
			String cur = Integer.toString(i);
			boolean okay = true;
			for (int j =  0; j <cur.length(); j++) {
				if (!(cur.charAt(j)=='4' || cur.charAt(j)=='7')) {
					okay = false;
					break;
				}
			}
			if (okay) {
				if (n%i==0) {
					lucky = true;
					break;
				}
			}
		}
		if (lucky) {
			System.out.println("YES");
		}
		else System.out.println("NO");

	}

}
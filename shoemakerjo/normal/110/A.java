import java.util.Scanner;

public class NearlyLuckyNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		long n = s.nextLong();
		String line = Long.toString(n);
		int ans = 0;
		for (int i = 0; i < line.length(); i++) {
			if (line.charAt(i)=='4'||line.charAt(i)=='7') ans++;
		}
		String cur = Integer.toString(ans);
		boolean lucky = true;
		for (int i = 0; i < cur.length(); i++) {
			if (!(cur.charAt(i)=='4'||cur.charAt(i)=='7')) {
				lucky = false;
				break;
			}
		}
		if (lucky) System.out.println("YES");
		else System.out.println("NO");

	}

}
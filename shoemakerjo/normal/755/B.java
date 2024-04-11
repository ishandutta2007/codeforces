import java.util.ArrayList;
import java.util.Scanner;

public class BallGame {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		s.nextLine();
		int com = 0;
		ArrayList<String> pw = new ArrayList<String>();
		for (int i = 0; i < n; i++) {
			pw.add(s.next());
		}
		for (int i = 0; i < m; i++) {
			String cur = s.next();
			if (pw.contains(cur)) com++;
		}
		n-=com;
		m-=com;
		if (n > m) System.out.println("YES");
		else if (m > n) System.out.println("NO");
		else {
			if (com%2==0) System.out.println("NO");
			else System.out.println("YES");
		}
	}

}
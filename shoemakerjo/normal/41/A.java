import java.util.Scanner;

public class Translation {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String line = s.next();
		String line2 = s.next();
		boolean e = true;
		if (line.length()!=line2.length()) {
			e = false;
		}
		else {
			for (int i = 0; i < line.length(); i++) {
				if (line.charAt(i)!=line2.charAt(line.length()-1-i)) {
					e = false;
					break;
				}
			}
		}
		
		if (e) System.out.println("YES");
		else System.out.println("NO");
		
	}

}
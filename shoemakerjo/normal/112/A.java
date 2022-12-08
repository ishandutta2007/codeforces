import java.util.Scanner;

public class PetyaandStrings {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String first = s.nextLine().toLowerCase();
		String second = s.nextLine().toLowerCase();
		if (first.equals(second))System.out.println(0);
		else {
			for (int i = 0; i < first.length(); i++) {
				if (first.charAt(i)>second.charAt(i)) {
					System.out.println(1);
					break;
				}
				if (first.charAt(i)<second.charAt(i)) {
					
					System.out.println(-1);
					break;
				}
			}
		}

	}

}
import java.util.Scanner;

public class HQ9plus {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		
		String line = s.nextLine();
		if (line.contains("H")||line.contains("Q")||line.contains("9")) {
			System.out.println("YES");
		}
		else System.out.println("NO");

	}

}
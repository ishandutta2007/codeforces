import java.util.Scanner;

public class Word {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String line = s.nextLine();
		int upper = 0;
		int lower = 0;
		for (int i = 0; i < line.length(); i++) {
			if (Character.isUpperCase(line.charAt(i))) {
				upper++;
			}
			else lower++;
		}
		if (upper <= lower) System.out.println(line.toLowerCase());
		else System.out.println(line.toUpperCase());

	}

}
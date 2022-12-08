import java.util.Scanner;

public class cAPSlOCK {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s =new Scanner(System.in);
		String line = s.nextLine();
		boolean swap = false;
		for (int i = 0; i < line.length(); i++) {
			String temp = line.substring(i,i+1);
			if (i==0) swap = true;
			else if (!temp.equals(temp.toUpperCase())) swap =false;
		}
		if (swap) {
			for (int i = 0; i < line.length();i++) {
				char c = line.charAt(i);
				if (Character.isUpperCase(c)) System.out.print(Character.toLowerCase(c));
				else System.out.print(Character.toUpperCase(c));
			}
		}
		else System.out.println(line);

	}

}
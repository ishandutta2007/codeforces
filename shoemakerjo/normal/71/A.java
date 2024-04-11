import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class WayTooLongWords {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		s.nextLine();
		for(int i = 0; i < n; i++) {
			String line = s.nextLine();
			int p = (line.length()-2);
			if(line.length()<=10) System.out.println(line);
			else System.out.println(line.charAt(0) +Integer.toString(p) +line.charAt(line.length()-1));
		}

	}

}
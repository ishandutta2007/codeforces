import java.util.Arrays;
import java.util.Scanner;

public class StringTask {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String line = s.nextLine().toLowerCase();
		
		for (int i = 0; i < line.length(); i++) {
			if(!(line.charAt(i)=='a'||line.charAt(i)=='e'||line.charAt(i)=='i'||line.charAt(i)=='o'||line.charAt(i)=='u'||line.charAt(i)=='y')) {
				System.out.print("." + line.charAt(i));
			}
		}
	}

}
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class night {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int moves = 0;
		String line = s.next();
		char c= 'a';
		String alph = "abcdefghijklmnopqrstuvwxyz";
		for (int i = 0; i < line.length(); i++) {
			int addon = Math.min(Math.abs(alph.indexOf(c)-alph.indexOf(line.charAt(i))), Math.abs(alph.indexOf(c)+26-alph.indexOf(line.charAt(i))));
			addon=Math.min(addon, Math.abs(alph.indexOf(line.charAt(i))+26-alph.indexOf(c)));
			moves+=addon;
			c = line.charAt(i);
			//System.out.println(moves);

		}
		System.out.println(moves);



	}

}
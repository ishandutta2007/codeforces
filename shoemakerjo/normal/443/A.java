import java.util.HashSet;
import java.util.Scanner;

public class AntonLetters {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String line = s.nextLine();
		HashSet<Character> ans = new HashSet<Character>();
		for (int i = 0; i < line.length(); i++) {
			char c = line.charAt(i);
			if (c!= '{' &&c!= '}'&&c!=' '&&c!=',') {
				ans.add(c);
			}
		}
		System.out.println(ans.size());

	}

}
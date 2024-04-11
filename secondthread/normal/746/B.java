import java.util.Scanner;

public class Decoding {
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		s.nextLine();
		String answer=s.nextLine();
		StringBuilder original=new StringBuilder("");
		for (int i=answer.length()-1; i>=0; i--) {
			original.insert(original.length()/2, answer.charAt(i));
		}
		System.out.println(original.toString());
	}
}
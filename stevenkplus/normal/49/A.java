import java.util.Scanner;


public class A049 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		char last = 'a';
		for(char c:in.nextLine().toLowerCase().toCharArray()) {
			if(Character.isLetter(c)) {
				last = c;
			}
		}
		System.out.println("aeiouy".contains(""+last)?"YES":"NO");
	}
}
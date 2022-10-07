import java.util.Scanner;


public class B043 {
	public static void main(String[ ] args) {
		System.out.println(b()?"YES":"NO");
	}
	static boolean b() {
		int[] count = new int[3444];
		Scanner in = new Scanner(System.in);
		String line1 = in.nextLine(),line2=in.nextLine();
		for(char c:line1.toCharArray()) {
			if(Character.isLetter(c))
				count[c]++;
		}
		for(char c:line2.toCharArray()) {
			if(Character.isLetter(c)) {
				count[c]--;
				if(count[c]<0) return false;
			}
		}
		return true;
	}
}
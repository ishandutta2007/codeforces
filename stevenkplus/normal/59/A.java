import java.util.Scanner;


public class A059 {
	public static void main(String[] args) throws Exception {
		String l = new Scanner(System.in).next();
		int k = 0;
		for(char c:l.toCharArray()) {
			if(Character.isLowerCase(c)) k++;
		}
		if(k*2>=l.length()) {
			System.out.println(l.toLowerCase());
		}
		else System.out.println(l.toUpperCase());
	}
}
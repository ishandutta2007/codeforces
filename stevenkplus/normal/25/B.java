import java.util.Scanner;

public class B025 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n= in.nextInt();
		String s =in.next();
		while(s.length()%3!=0&&s.length()>2) {
			System.out.print(s.substring(0,2)+"-");
			s = s.substring(2);
		}
		while(s.length()>3) {
			System.out.print(s.substring(0,3)+"-");
			s = s.substring(3);
		}
		System.out.println(s);
	}
}
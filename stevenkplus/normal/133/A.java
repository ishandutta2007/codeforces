import java.util.Scanner;


public class A133 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		String l = in.nextLine().replaceAll("[^HQ9]","");
		System.out.println(l.length()>0?"YES":"NO");
	}
}
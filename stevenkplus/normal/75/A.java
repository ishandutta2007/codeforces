import java.util.Scanner;


public class A075 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int c = a+b;
		int ap = c(a),bp=c(b),cp=c(c);
		System.out.println(ap+bp==cp?"YES":"NO");
	}
	static int c(int a) {
		return Integer.parseInt(Integer.toString(a).replaceAll("0", ""));
	}
}
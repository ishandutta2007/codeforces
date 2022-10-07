import java.util.Scanner;


public class A104 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt()-10;
		if(n>11||n<1) System.out.println("0");
		else if(n==11) System.out.println("4");
		else if (n==10) System.out.println("15");
		else System.out.println("4");
	}
}
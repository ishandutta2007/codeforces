import java.util.Scanner;


public class A041 {
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		String a = in.next(),b=in.next();
		StringBuffer c = new StringBuffer(b);
		c.reverse();
		System.out.println(a.equals(c.toString())?"YES":"NO");
	}
}
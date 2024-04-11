import java.util.Arrays;
import java.util.Scanner;

public class B012 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String a = in.next(), b = in.next();
		
		String c = ans(a);
		System.out.println(c.equals(b) ? "OK" : "WRONG_ANSWER");
	}

	static String ans(String a) {
		if(a.equals("0")) return "0";
		char[] b = a.toCharArray();
		Arrays.sort(b);
		int x = 0;
		while (b[x] == '0')
			x++;
		if(x>0&&x<b.length) {
			b[0] = b[x];
			b[x] = '0';
		}
		return new String(b);
	}
}
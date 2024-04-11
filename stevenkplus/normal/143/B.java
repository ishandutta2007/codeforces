import java.util.Scanner;

public class B143 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String line = in.next();
		System.out.println(conv(line));
	}

	static String conv(String a) {
		if (a.charAt(0) == '-') {
			return "(" + conv(a.substring(1)) + ")";
		}
		int d = a.indexOf(".");
		if (d >= 0) {
			a += "00";
			String dec = a.substring(d + 1);
			String part = a.substring(0, d);
			return "$" + convFirst(part) + "." + dec.substring(0, 2);
		} else {

			String dec = "00";
			String part = a;
			return "$" + convFirst(part) + "." + dec.substring(0, 2);
		}
	}

	static String convFirst(String a) {
		StringBuffer ret = new StringBuffer();
		for (int x = 0; x < a.length(); x++) {
			if (x > 0 && a.length() % 3 == x % 3)
				ret.append(",");
			ret.append(a.charAt(x));
		}
		return ret.toString();
	}
}
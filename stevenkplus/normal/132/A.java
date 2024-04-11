import java.util.Scanner;

public class A132 {
	static String zeros = "00000000";

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		String line = in.nextLine();
		String[] ar = new String[line.length()];
		for (int x = 0; x < line.length(); x++) {
			ar[x] = Integer.toBinaryString(line.charAt(x));
		}
		String[] res = new String[line.length()];
		for (int x = 0; x < line.length(); x++) {
			String k = rev(ar[x]);
			String prev = x > 0 ? rev(ar[x - 1]) : zeros;
			int r = (256 + Integer.parseInt(prev, 2) - Integer.parseInt(k, 2)) % 256;
			res[x] = Integer.toBinaryString(r);
			System.out.println(r);
		}
		
	}

	static String rev(String s) {
		s = zeros + s;
		return new StringBuffer(s.substring(s.length() - 8)).reverse()
				.toString();

	}
}
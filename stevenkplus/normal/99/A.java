import java.util.Scanner;

public class A099 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		String[] s = in.next().split("\\.");
		boolean b = s[1].charAt(0) < '5';
		if (s[0].charAt(s[0].length() - 1) == '9') {
			System.out.println("GOTO Vasilisa.");
		} else if (!b) {
			String st = s[0];
			System.out.println(st.substring(0, st.length() - 1)
					+ (char)((int)(st.charAt(st.length() - 1)) + 1));
		}
		else
			System.out.println(s[0]);
	}

}
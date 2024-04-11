import java.io.BufferedReader;
import java.io.InputStreamReader;

public class A131 {
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String line = in.readLine();
		if (up(line)) {
			StringBuffer b = new StringBuffer();
			for (char c : line.toCharArray()) {
				b.append(tog(c));
			}
			System.out.println(b.toString());
		}
		else
			System.out.println(line);
		
	}

	static char tog(char a) {
		if (Character.isUpperCase(a)) {
			return (char) (a + 'a' - 'A');
		} else
			return (char) (a + 'A' - 'a');
	}

	static boolean up(String l) {

		for (int x = 1; x < l.length(); x++) {
			if (!Character.isUpperCase(l.charAt(x)))
				return false;
		}
		return true;
	}
}
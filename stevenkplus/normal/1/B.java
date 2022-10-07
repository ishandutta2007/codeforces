import java.io.BufferedReader;
import java.io.InputStreamReader;

public class B001 {
	static String conv(String s) {
		if (s.matches("[A-Z]+\\d+")) {
			int row = 0, col = 0;
			for (int x = 0; x < s.length(); x++) {
				char c = s.charAt(x);
				if (Character.isDigit(c)) {
					row = Integer.parseInt(s.substring(x));
					break;
				}
				col *= 26;
				col += c - 'A' + 1;
			}
			return String.format("R%dC%d", row, col);
		} else {
			String[] ss = s.split("[RC]");
			int row = Integer.parseInt(ss[1]), col = Integer.parseInt(ss[2]);
			StringBuffer coll = new StringBuffer();
			while (col > 0) {
				coll.append((char)('A' + (col - 1 + 26) % 26));
				col--;
				col /= 26;
			}
			return String.format("%s%d", coll.reverse().toString(), row);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(r.readLine());
		for (int x = 0; x < n; x++) {
			System.out.println(conv(r.readLine()));
		}
	}
}
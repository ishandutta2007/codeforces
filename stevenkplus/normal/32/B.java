import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class B032 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		String line = r.readLine();
		StringBuffer ret = new StringBuffer();
		for (int x = 0; x < line.length(); x++) {
			if (line.charAt(x) == '.') {
				ret.append("0");
			} else {
				if (line.charAt(x + 1) == '.') {
					ret.append("1");
				} else
					ret.append("2");
				x++;
			}
		}
		System.out.println(ret.toString());
	}
}
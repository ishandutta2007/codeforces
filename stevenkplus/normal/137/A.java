import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class A098 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer token;
		ArrayList<Boolean> carry = new ArrayList<Boolean>();
		String line = in.nextLine();
		int count = 0;
		for (int x = 0; x < line.length(); x++) {
			boolean b = line.charAt(x) == 'C';
			boolean c = (carry.contains(!b));
			if (c || carry.size() >= 5) {
				carry.clear();
				count++;
			}
			carry.add(b);

		}
		System.out.println(count+1);
	}
}
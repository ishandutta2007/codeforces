import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class A {
	static BufferedReader r;
	static Scanner in;

	static void init() throws Exception {
		r = new BufferedReader(new InputStreamReader(System.in));
		in = new Scanner(System.in);
	}

	static StringTokenizer st;

	static void nextLine() throws Exception {
		st = new StringTokenizer(r.readLine());
	}

	static int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	static String next() throws Exception {
		if (st.hasMoreTokens()) {
			return st.nextToken();
		} else
			return r.readLine();

	}

	public static void main(String[] args) throws Exception {
		init();
		String a = r.readLine(), b = r.readLine();
		int i = 0;
		int count = 0;
		for (int x = 0; x < a.length(); x++) {
			if (a.charAt(x) == '4')
				count++;
			if (b.charAt(x) == '4')
				count--;
			if (a.charAt(x) != b.charAt(x)) {
				i++;
			}
		}
		int abs = count > 0 ? count : -count;
		int sum = abs;
		sum += (i - abs) / 2;
		System.out.println(sum);
	}

}
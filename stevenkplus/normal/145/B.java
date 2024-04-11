import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class B {
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
		nextLine();
		int a = nextInt(), b = nextInt(), c = nextInt(), d = nextInt();
		int aa = 0, bb = 0;
		StringBuffer sb = new StringBuffer();
		switch (c - d) {
		case -1:
			for (int x = 0; x < d; x++) {
				sb.append("74");
			}
			aa = d;
			bb = d;
			break;
		case 0:
			if (a >= c + 1) {
				sb.append("4");
				for (int x = 0; x < c; x++) {
					sb.append("74");
				}
				aa = c + 1;
				bb = c;
			} else {
				sb.append("7");
				for (int x = 0; x < c; x++) {
					sb.append("47");
				}
				aa = c;
				bb = c + 1;
			}
			break;
		case 1:
			for (int x = 0; x < c; x++) {
				sb.append("47");
			}
			aa = c;
			bb = c;
			break;
		default:
			System.out.println("-1");
			return;
		}
		aa = a - aa;
		bb = b - bb;
		if (aa < 0 || bb < 0) {
			System.out.println(-1);
			return;
		}
		int ins;
		for (ins = 0; sb.charAt(ins) != '4'; ins++)
			;
		StringBuffer insert = new StringBuffer();
		for (int x = 0; x < aa; x++) {
			insert.append("4");
		}
		sb.insert(ins, insert.toString());
		for (ins = sb.length() - 1; sb.charAt(ins) != '7'; ins--)
			;
		insert = new StringBuffer();
		for (int x = 0; x < bb; x++) {
			insert.append("7");
		}
		sb.insert(ins, insert.toString());
		System.out.println(sb.toString());
		// StringBuffer sb = new StringBuffer();
		// if (c == d - 1) {
		// int k = d;
		// if (a >= k && b >= k) {
		// sb.append("7");
		// sb.append("4");
		// for (int p = 0; p < a - k; p++) {
		// sb.append("4");
		// }
		// for (int p = 2; p < k; p++) {
		// sb.append("74");
		// }
		// sb.append("7");
		// for (int p = 0; p < b - k; p++) {
		// sb.append("7");
		// }
		// sb.append("4");
		// } else {
		// sb.append("-1");
		// }
		// } else if (c == d) {
		// int k = c;
		// if (a >= c + 1 && b >= c) {
		// sb.append("4");
		// for (int p = 0; p < a - 1 - k; p++) {
		// sb.append("4");
		// }
		// for (int p = 1; p < k; p++) {
		// sb.append("74");
		// }
		// sb.append("7");
		// for (int p = 0; p < b - k; p++) {
		// sb.append("7");
		// }
		// sb.append("4");
		// } else if (a >= c && b >= c + 1) {
		// sb.append("74");
		// for (int p = 0; p < a - k; p++) {
		// sb.append("4");
		// }
		// sb.append("7");
		// for (int p = 1; p < c; p++) {
		// sb.append("47");
		// }
		// for (int p = 0; p < b - c - 1; p++) {
		// sb.append("7");
		// }
		// } else {
		// sb.append("-1");
		// }
		// } else if (c == d + 1) {
		// int k = c;
		// if (a >= c && b >= c) {
		// sb.append("4");
		// for (int p = 0; p < a - k; p++) {
		// sb.append("4");
		// }
		// sb.append("7");
		// for (int p = 1; p < k; p++) {
		// sb.append("47");
		// }
		// for (int p = 0; p < b - k; p++) {
		// sb.append("7");
		// }
		// } else
		// sb.append("-1");
		// } else
		// sb.append("-1");
		// System.out.println(sb.toString());
	}
}
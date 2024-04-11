import java.util.Scanner;
import java.util.StringTokenizer;

public class D132 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String line = in.nextLine() + "001";
		int[] ar = new int[line.length()];
		boolean[] arr = new boolean[line.length()];
		int i = 0;
		// while (st.hasMoreTokens()) {
		// String next = st.nextToken();
		int state = 0;
		int start = 0;
		int prev = 0;
		for (int x = 0; x < line.length(); x++) {
			if (line.charAt(x) == '0') {
				if (state == 0)
					prev = x;
				state++;
			} else {
				if (state >= 2) {
					boolean fag = true;
					boolean f = true;
					for (int t = start; t < prev; t++) {
						if (f ^ line.charAt(t) == '1') {
							fag = false;
							break;
						}
						f=!f;
					}
					if (fag) {
						for (int t = start; t < prev; t++) {
							if (line.charAt(t) == '1') {
								ar[i] = t;
								arr[i] = true;
								i++;
							}
						}
					} else {
						ar[i] = start - 1;
						arr[i] = true;
						i++;
						for (int y = start; y < prev; y++) {
							if (line.charAt(y) == '0' ^ y == prev - 1) {
								ar[i] = y;
								arr[i] = false;
								i++;
							}
						}

					}

					start = x;
				}
				state = 0;
			}
		}
		System.out.println(i);
		for (int x = 0; x < i; x++) {
			System.out.println((arr[x] ? '+' : '-') + "2^"
					+ (line.length() - ar[x] - 4));
		}
	}
}
import java.io.*;
import java.util.*;

public class D159 {
	static String next() {
		if (st == null || !st.hasMoreTokens())
			nextLine();
		return st.nextToken();
	}

	static int nextInt() {
		return Integer.parseInt(next());
	}

	static void nextLine() {
		try {
			st = new StringTokenizer(f.readLine());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static StringTokenizer st;
	static PrintWriter out;
	static BufferedReader f;

	public static void main(String[] args) throws IOException {
		f = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		char[] s = next().toCharArray();
		int N = s.length;
		long[] start = new long[N], end = new long[N];
		for (int mid = 0; mid < N; mid++) {
			for (int off = 0; mid - off >= 0 && mid + off < N
					&& s[mid - off] == s[mid + off]; off++) {
				start[mid - off]++;
				end[mid + off]++;
			}
		}
		for (int mid = 0; mid + 1 < N; mid++) {
			int mid1 = mid + 1;
			for (int off = 0; mid - off >= 0 && mid1 + off < N
					&& s[mid - off] == s[mid1 + off]; off++) {
				start[mid - off]++;
				end[mid1 + off]++;
			}
		}

		long sum = 0;
		for (int x = 0; x < N; x++) {
			for (int y = x + 1; y < N; y++) {
				sum += end[x] * start[y];
			}
		}
		out.println(sum);
		out.close();
		// System.exit(0);
	}

}
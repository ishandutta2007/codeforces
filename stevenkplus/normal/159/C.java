import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class C159 {
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

	static class BIT {
		int[] vals;

		public BIT(int size) {
			vals = new int[size];
		}

		public void inc(int index) {
			while (index < vals.length) {
				vals[index]++;
				index += (index & -index);
			}
		}

		public int sum(int end) { // incl end
			int sum = 0;
			int index = end;
			while (index > 0) {
				sum += vals[index];
				index -= (index & -index);
			}
			return sum;
		}
	}

	public static void main(String[] args) throws IOException {
		f = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		int k = nextInt();
		char[] s = next().toCharArray();
		StringBuffer ret = new StringBuffer();
		HashSet<Integer>[] dels = new HashSet[26];
		for (int x = 0; x < 26; x++)
			dels[x] = new HashSet<Integer>();
		BIT[] bits = new BIT[26];
		int[] counts = new int[26];
		for (char c : s) {
			counts[c - 'a'] += k;
		}
		for (int x = 0; x < 26; x++) {
			bits[x] = new BIT(counts[x] + 1);
		}
		int M = nextInt();
		for (int x = 0; x < M; x++) {
			int a = nextInt(), b = next().charAt(0) - 'a';
			int low = a;
			int high = counts[b] + 1;
			while (low + 1 < high) {
				int mid = (low + high) / 2;
				int v = mid - bits[b].sum(mid);
				if (v == a) {
					if (dels[b].contains(mid))
						high = mid;
					else {
						low = mid;
						break;
					}
				} else if (v > a) {
					high = mid;
				} else {
					low = mid + 1;
				}
			}
			bits[b].inc(low);
			dels[b].add(low);
		}
		counts = new int[26];
		for (int x = 0; x < k; x++) {
			for (char c : s) {
				int cc = c - 'a';
				counts[cc]++;
				if (!dels[cc].contains(counts[cc])) {
					ret.append(c);
				}
			}
		}
		out.println(ret);
		out.close();
		// System.exit(0);
	}

}
import java.io.*;
import java.util.*;

public class B161 {
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

	static class item implements Comparable<item> {
		int id, val, t;

		public item(int a, int b, int c) {
			t = c;
			id = a + 1;
			val = b;
		}

		public int compareTo(item o) {
			if (t == 1 && o.t == 2)
				return -1;
			if (t == 2 && o.t == 1)
				return 1;
			return o.val - val;
		}
	}

	public static void main(String[] args) throws IOException {
		f = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		int N = nextInt(), K = nextInt();
		ArrayList<item> items = new ArrayList<item>();
		int min = Integer.MAX_VALUE;
		long sum = 0;

		for (int x = 0; x < N; x++) {
			int price = nextInt();
			items.add(new item(x, price, nextInt()));
			sum += price;
			if (price < min)
				min = price;
		}
		Collections.sort(items);
		long s = 0;
		for (int x = 0; x < K; x++) {
			if (items.get(x).t == 1) {
				if (x == K - 1) {
					s += min;
				} else
					s += items.get(x).val;
			}
		}
		out.printf("%.1f\n", sum - s / 2.);
		for (int x = 0; x < K - 1; x++) {
			out.printf("1 %d\n", items.get(x).id);
		}
		out.print(N - K + 1);
		for (int x = K - 1; x < N; x++) {
			out.print(" " + items.get(x).id);
		}
		out.println();
		// int s = 0;
		// for (int x = 0; x < stools.size(); x++) {
		// if (x == K) {
		// s += min;
		// break;
		// }
		// s += stools.get(x).val;
		// }
		// out.printf("%.1f\n", sum - s / 2.);
		// for (int x = 0; x < K; x++) {
		// if (x == K-1) {
		// int n = N - (K - 1);
		// StringBuffer sb = new StringBuffer();
		// sb.append(n);
		// for (int y = x; y < stools.size(); y++) {
		// sb.append(" " + stools.get(y).id);
		// }
		// for (item i : pencils)
		// sb.append(" " + i.id);
		// out.println(sb);
		// break;
		// }
		// if(x<stools.size())
		// out.printf("1 %d\n", stools.get(x).id);
		// // s+=stools.get(x).val;
		// }
		//
		out.close();
		// System.exit(0);
	}

}
import java.io.*;
import java.util.*;

public class E159 {
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

	static class color {
		long[] sums;
		ArrayList<cube> cubes;

		public color(int c) {
			cubes = new ArrayList<cube>();
		}

		public void calc() {
			Collections.sort(cubes);
			sums = new long[cubes.size() + 1];
			for (int x = 0; x < cubes.size(); x++) {
				sums[x + 1] = sums[x] + cubes.get(x).val;
				pq[x + 1].add(this);
			}
		}
	}

	static class cube implements Comparable<cube> {
		int val;
		int num;

		public cube(int v, int n) {
			val = v;
			num = n;
		}

		public int compareTo(cube o) {
			return o.val - val;
		}
	}

	static class colorcomp implements Comparator<color> {
		int h;

		public colorcomp(int height) {
			h = height;
		}

		public int compare(color a, color b) {
			return b.sums[h] - a.sums[h]>0?1:-1;
		}
	}

	static PriorityQueue<color>[] pq;
	static StringTokenizer st;
	static PrintWriter out;
	static BufferedReader f;

	public static void main(String[] args) throws IOException {
		f = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		Hashtable<Integer, color> ht = new Hashtable<Integer, color>();
		ArrayList<color> colors = new ArrayList<color>();
		int N = nextInt();
		for (int x = 0; x < N; x++) {
			int a = nextInt(), b = nextInt();
			if (ht.get(a) == null) {
				color c = new color(a);
				ht.put(a, c);
				colors.add(c);
			}
			color c = ht.get(a);
			c.cubes.add(new cube(b, x + 1));
		}
		pq = new PriorityQueue[N + 1];
		for (int x = 0; x < N + 1; x++) {
			pq[x] = new PriorityQueue<color>(10, new colorcomp(x));
		}
		for (color c : colors)
			c.calc();
		long maxh = -1, h1 = -1, h2 = -1;
		color col1 = null, col2 = null;
		for (int a = 1; a <= N; a++) {
			color ca = pq[a].peek();
			if (ca == null)
				break;
			for (int b = a - 1; b <= a + 1; b++) {
				if (b <= 0)
					continue;
				color cb = pq[b].peek();
				if (cb == ca) {
					pq[b].poll();
					color temp = pq[b].peek();
					pq[b].add(cb);
					cb = temp;
				}
				if (cb == null)
					continue;
				long sum = ca.sums[a] + cb.sums[b];
				if (sum > maxh) {
					maxh = sum;
					h1 = a > b ? a : b;
					h2 = a > b ? b : a;
					col1 = a > b ? ca : cb;
					col2 = a > b ? cb : ca;
				}
			}
		}
		out.println(maxh);
		out.println(h1 + h2);
		String sep = "";
		StringBuffer sb = new StringBuffer();
		for (int x = 0; x < h1; x++) {
			sb.append(sep);
			sep = " ";
			sb.append(col1.cubes.get(x).num);
			if (x < h2) {
				sb.append(sep);
				sep = " ";
				sb.append(col2.cubes.get(x).num);
			}
		}
		out.println(sb);
		out.close();
		// System.exit(0);
	}
}
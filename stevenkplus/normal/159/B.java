import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Hashtable;
import java.util.StringTokenizer;

public class B159 {
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
		int size = 1001;
		Hashtable<Point, Integer> ht = new Hashtable<Point, Integer>();
		int[] count = new int[size], count2 = new int[size];
		int beauty = 0;
		int N = nextInt(), M = nextInt();
		for (int x = 0; x < N; x++) {
			int a = nextInt(), b = nextInt();
			Point p = new Point(a, b);
			if (ht.get(p) == null)
				ht.put(p, 0);
			ht.put(p, ht.get(p) + 1);
			count[b]++;
		}
		for (int x = 0; x < M; x++) {
			int a = nextInt(), b = nextInt();
			Point p = new Point(a, b);
			if (ht.get(p) != null) {
				if (ht.get(p) > 1)
					ht.put(p, ht.get(p) - 1);
				else
					ht.remove(p);
				beauty++;
				count[b]--;
			} else {
				count2[b]++;
			}
		}
		int c = beauty;
		for (int x = 0; x < size; x++) {
			c += count[x] < count2[x] ? count[x] : count2[x];
		}
		out.printf("%d %d\n", c, beauty);
		out.close();
		// System.exit(0);
	}
}
import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class B181 {
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
		int n = nextInt();
		Point[] points = new Point[n];
		Set<Point> hs = new HashSet<Point>();
		for (int i = 0; i < n; i++) {
			hs.add(points[i] = new Point(nextInt(), nextInt()));
		}
		long trips = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				Point mdpt = mdpt(points[i], points[j]);
				if (mdpt != null && hs.contains(mdpt))
					trips++;
			}
		}
		out.println(trips);
		out.close();
		// System.exit(0);
	}

	static Point mdpt(Point a, Point b) {
		int xs = a.x + b.x, ys = a.y + b.y;
		if (xs % 2 == 0 && ys % 2 == 0)
			return new Point(xs / 2, ys / 2);
		else
			return null;
	}
}
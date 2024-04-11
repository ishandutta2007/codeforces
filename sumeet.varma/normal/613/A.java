import java.io.*;
import java.util.*;

public class R339qAWOW {

	public static void main(String args[]) throws Exception {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		Point P = new Point(in.nextInt(), in.nextInt());

		Point p[] = new Point[n];
		for (int i = 0; i < n; i++)
			p[i] = new Point(in.nextInt(), in.nextInt());
		
		double min = dist2(P, p[0]);
		double max = dist2(P, p[0]);

		for (int i = 1; i < p.length; i++) {
			double x = DistancePointSegment(p[i - 1], p[i], P);
			min = Math.min(min, x);
			max = Math.max(max, x);
			min = Math.min(min, dist2(P, p[i]));
			max = Math.max(max, dist2(P, p[i]));
		}
		
		min = Math.min(min , DistancePointSegment(p[n - 1], p[0], P));
		max = Math.max(max , DistancePointSegment(p[n - 1], p[0], P));
		
		w.println(Math.PI * (max - min));
		w.close();
	}

	// project point c onto line segment through a and b
	public static Point ProjectPointSegment(Point a, Point b, Point c) {
		double r = b.minus(a).dot(b.minus(a));
		r = c.minus(a).dot(b.minus(a)) / r;
		if (r < 0)
			return a;
		if (r > 1)
			return b;
		return a.plus(b.minus(a).mul(r));
	}

	// compute distance from c to segment between a and b
	public static double DistancePointSegment(Point a, Point b, Point c) {
		return dist2(c, ProjectPointSegment(a, b, c));
	}

	public static double dist2(Point a, Point b) { //square of distance
		return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	}

	public static class Point {
		public double x, y;

		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}

		public Point minus(Point b) {
			return new Point(x - b.x, y - b.y);
		}

		public Point plus(Point a) {
			return new Point(x + a.x, y + a.y);
		}

		public double cross(Point b) {
			return (double) x * b.y - (double) y * b.x;
		}

		public double dot(Point b) {
			return (double) x * b.x + (double) y * b.y;
		}

		public Point mul(double r) {
			return new Point(x * r, y * r);
		}
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar, snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}
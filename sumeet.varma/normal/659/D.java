import java.io.*;
import java.util.*;

public class R346qD {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		
		Point p[] = new Point[n];
		
		for(int i = 0; i < n; i++)
			p[i] = new Point(in.nextInt() , in.nextInt());
		
		
		Polygon P = new Polygon(n , p);
		int ans = 0;
		
		for(int i = 0; i < n; i++){
			int j = (i + 1) % n;
			Point q = new Point(p[j].x , p[j].y);
			if(p[i].x < p[j].x)
				q.x += 0.5;
			if(p[i].x > p[j].x)
				q.x -= 0.5;
			if(p[i].y < p[j].y)
				q.y += 0.5;
			if(p[i].y > p[j].y)
				q.y -= 0.5;
			if(P.PointInPolygon(q))
				ans++;
		}
		
		w.println(ans);
		w.close();
	}
	
	public static class Polygon {

		static final double EPS = 1e-15;
		public int n;
		public Point p[];

		Polygon(int n, Point x[]) {
			this.n = n;
			p = Arrays.copyOf(x, n);
		}

		long area(){ //returns 2 * area
			long ans = 0;
			for(int i = 1; i + 1 < n; i++)
				ans += p[i].minus(p[0]).cross(p[i + 1].minus(p[0]));
			return ans;
		}
		
		boolean PointInPolygon(Point q) {
			boolean c = false;
			for (int i = 0; i < n; i++){
			    int j = (i+1)%n;
			    if ((p[i].y <= q.y && q.y < p[j].y || 
			    		p[j].y <= q.y && q.y < p[i].y) &&
			    		q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
			    c = !c;
		     }
			return c;
	    }

			// determine if point is on the boundary of a polygon
		boolean PointOnPolygon(Point q) {
			 for (int i = 0; i < n; i++)
			 if (ProjectPointSegment(p[i], p[(i+1)%n], q).dist(q) < EPS)
			     return true;
		     return false;
		}
		
		// project point c onto line segment through a and b
		Point ProjectPointSegment(Point a, Point b, Point c) {
		  double r = b.minus(a).dot(b.minus(a));
		  if (Math.abs(r) < EPS) return a;
		  r = c.minus(a).dot(b.minus(a))/r;
		  if (r < 0) return a;
		  if (r > 1) return b;
		  return a.plus(b.minus(a).mul(r));
		}
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
		
		public Point plus(Point a){
			return new Point(x + a.x, y + a.y);
		}

		public double cross(Point b) {
			return (double)x * b.y - (double)y * b.x;
		}

		public double dot(Point b) {
			return (double)x * b.x + (double)y * b.y;
		}
		
		public Point mul(double r){
			return new Point(x * r, y * r);
		}
		
		public double dist(Point p){
			return Math.sqrt(fastHypt( x - p.x , y - p.y));
		}
		
		public double fastHypt(double x, double y){
			return x * x + y * y;
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
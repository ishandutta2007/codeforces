import java.awt.geom.Line2D;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class ConvexHullTest {

	public static class Point {
		public final int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	public static Point[] convexHull2(Point[] p) {
		int n = p.length;
		if (n <= 1)
			return p;
		Arrays.sort(p,new Comparator<Point>(){
			public int compare(Point a, Point b) {
				return (a.x!=b.x ? Integer.compare(a.x, b.x) : Integer.compare(a.y, b.y));
			}
		});
		Point[] h = new Point[n * 2];
		int cnt = 0;
		for (int i = 0; i < n; h[cnt++] = p[i++])
			while (cnt > 1 && cross(h[cnt - 2], h[cnt - 1], p[i]) >= 0)
				--cnt;
		for (int i = n - 2, t = cnt; i >= 0; h[cnt++] = p[i--])
			while (cnt > t && cross(h[cnt - 2], h[cnt - 1], p[i]) >= 0)
				--cnt;

		return Arrays.copyOf(h, cnt - 1 - (h[0].x == h[1].x && h[0].y == h[1].y ? 1 : 0));
	}

	static long cross(Point a, Point b, Point c) {
		return (long) (b.x - a.x) * (c.y - a.y) - (long) (b.y - a.y) * (c.x - a.x);
	}
	double eps=1e-8;
	static double intersection(Point p11, Point p12, Point p21 , Point p22){
		int x1=Math.min(p11.x,p12.x);
		int x2=Math.max(p11.x,p12.x);
		int y1=Math.min(p11.y,p12.y);
		int y2=Math.max(p11.y,p12.y);
		
		long a1=p12.y-p11.y,b1=p11.x-p12.x,c1=a1*p11.x+b1*p11.y;
		long a2=p22.y-p21.y,b2=p21.x-p22.x,c2=a2*p21.x+b2*p21.y;
		long det=a1*b2-a2*b1; 
		long x=(b2*c1-b1*c2);
		long y=-(a2*c1-a1*c2);
		if(x>=x1*det && x<=x2*det && y>=y1*det && y<=y2*det)
			return (double)x/det;
		else 
			return -1;
	}
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int finalX=in.nextInt();
		int finalY=in.nextInt();
		int a[] = new int[n];
		Point [] p = new Point[n+2]; 
		for (int i = 0; i < n; i++)
			p[i] = new Point(in.nextInt() , in.nextInt());
		int maxX=0;
		int maxY=0;
		for(int i=0;i<n;i++)
		{
			maxX = Math.max(p[i].x, maxX);
			maxY = Math.max(p[i].y, maxY);
		}
		p[n]=new Point(maxX, 0);
		p[n+1]=new Point(0, maxY);
		
		p = convexHull2(p);
		
		for(int i=0 ; i<p.length-1; i++){
			double ans=-1;
			if((ans=intersection(p[i], p[i+1], new Point(0,0), new Point(finalX,finalY)))!=-1){
				w.println(finalX/ans);
				break;
			}
		}
		w.close();
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
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

	static int pointInPolygon(int qx, int qy, Point[] points) {
		int n = points.length;
		int cnt = 0;
		for (int i = 0, j = n - 1; i < n; j = i++) {
			if (points[i].y == qy && (points[i].x == qx || points[j].y == qy && (points[i].x <= qx || points[j].x <= qx) && (points[i].x >= qx || points[j].x >= qx)))
				return 0; // boundary
			if ((points[i].y > qy) != (points[j].y > qy)) {
				long det = (long) (points[i].x - qx) * (points[j].y - qy) - (long) (points[j].x - qx) * (points[i].y - qy);
				if (det == 0)
					return 0; // boundary
				if ((det > 0) != (points[j].y - points[i].y > 0))
					++cnt;
			}
		}
		return cnt % 2 == 0 ? -1 /* exterior */ : 1 /* interior */;
	}
}
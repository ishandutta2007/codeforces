import java.io.*;
import java.util.*;

public class R245qDTrickyFunction {

	static int n;
	static Point p[];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		
		Point p[] = new Point[n];
		int tot = 0;
		for(int i=1;i<=n;i++){
			tot += in.nextInt();
			p[i-1] = new Point(i,tot);
		}

		w.println(ClosestPairOfPoints(p));
		w.close();
	}
	
	static long ClosestPairOfPoints(Point p[]){
		int n = p.length;
		
		if(n <= 1)
			return Long.MAX_VALUE;
		
		int mid = n >> 1;
		
		Point left[] = new Point[mid];
		for(int i=0;i<mid;i++)
			left[i] = p[i];
		
		Point right[] = new Point[n - mid];
		for(int i=0,j=mid;j<n;j++,i++)
			right[i] = p[j];
		
		long ans = Math.min(ClosestPairOfPoints(left),ClosestPairOfPoints(right));
		
		ArrayList<Point> strip = new ArrayList<Point>();
		
		for(int i=mid;i>=0;i--){
			if( (p[mid].x - p[i].x) * 1L * (p[mid].x - p[i].x) > ans)
				break;
			strip.add(p[i]);
		}
		
		for(int i=mid+1;i<n;i++){
			if( (p[mid].x - p[i].x) * 1L * (p[mid].x - p[i].x) > ans)
				break;
			strip.add(p[i]);
		}
		
		Collections.sort(strip,new PointCompY());
		int siz = strip.size();
		
		for(int i=0;i<siz;i++){
			for(int j=i+1;j<siz;j++){
				long a = strip.get(i).y;
				long b = strip.get(j).y;
				if( (a - b) * (a - b) > ans)
					break;
				ans = Math.min(ans, sqEuclid(strip.get(i),strip.get(j)));
			}
		}
		
		return ans;
	}
	
	static long sqEuclid(Point a,Point b){
		return (a.x - b.x) * 1L * (a.x - b.x) + (a.y - b.y) * 1L * (a.y - b.y);
	}
	
	static class Point{
		int x,y;
		Point(int x,int y){
			this.x = x;
			this.y = y;
		}
		public String toString(){
			return x + " " + y;
		}
	}
	
	static class PointCompY implements Comparator<Point>{
		public int compare(Point a,Point b){
			if(a.y != b.y)
				return Integer.compare(a.y, b.y);
			return Integer.compare(a.x,b.x);
		}
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
}
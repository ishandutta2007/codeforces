import java.io.*;
import java.util.*;
public class WunderFundqC {

	public static void main(String args[]) throws Exception {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		Pair p[] = new Pair[n];
		for(int i = 0; i < n; i++)
			p[i] = new Pair(i + 1, in.nextInt() , in.nextInt());
		
		Arrays.sort(p);
		int ans = -1;
		double minArea = Double.MAX_VALUE;
		double d = dis(p[0], p[1]);
		double eps = 1e-8;
		
		for(int i = 2; i < n; i++){
			double nowArea = area(p[0],p[1],p[i]);
			if(nowArea < eps)	continue;
			if(nowArea < minArea){
				minArea = nowArea;
				ans = i;
			}
		}
		
		if(ans == -1)	throw new RuntimeException();
		
		/*
		for(int i = 2; i < n; i++)
			if(p[i].idx != ans)
				System.out.println(inside(p[0],p[1],p[ans],p[i]) + " " + p[i].idx);
		*/
		
		w.println(p[0].idx + " " + p[1].idx + " " + p[ans].idx);
		w.close();
	}
	
	static double dis(Pair a, Pair b){
		double n = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
		return Math.sqrt(n);
	}
	
	static boolean inside(Pair a, Pair b, Pair c, Pair d){
		return area(a,b,c) == area(a,b,d) + area(a,c,d) + area(b,c,d);
	}
	
	static double area(Pair a, Pair b, Pair c){
		double n = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
		return Math.abs(n / 2);
	}
	
	static class Pair implements Comparable<Pair>{
		int idx;
		long x,y;
		Pair(int idx, int x,int y){	this.idx = idx; this.x = x; this.y = y; }
		public int compareTo(Pair o){
			if(x != o.x)
				return Long.compare(x, o.x);
			return Long.compare(y, o.y);
		}
		public String toString(){
			return idx + " " + x + " " + y;
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
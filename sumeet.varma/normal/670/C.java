import java.io.*;
import java.util.*;

public class R350qA {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int a[] = in.nextIntArray(n);
		
		TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
		for(int i = 0; i < a.length; i++){
			if(!map.containsKey(a[i]))
				map.put(a[i], 0);
			map.put(a[i], map.get(a[i]) + 1);
		}
		
		int ans = -1;
		int x = -1, y = -1;
		
		int m = in.nextInt();
		int b[] = in.nextIntArray(m);
		int c[] = in.nextIntArray(m);
		
		for(int i = 0;i < m; i++){
			//System.out.println(b[i] + " " + map.containsKey(b[i]) + " " + map.get(b[i]));
			int X = map.containsKey(b[i]) ? map.get(b[i]) : 0;
			int Y = map.containsKey(c[i]) ? map.get(c[i]) : 0;
			if(X > x || ( X == x && Y > y)){
				x = X;
				y = Y;
				ans = i + 1;
			}
		}
		
		w.println(ans);
		w.close();
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
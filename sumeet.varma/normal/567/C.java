import java.io.*;
import java.util.*;

public class GeometricProgression {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int k = in.nextInt();
		
		int a[] = new int[n];
		for(int i=0;i<n;i++)
			a[i] = in.nextInt();
		
		int p1[] = new int[n];
		HashMap<Integer,Integer> count = new HashMap<Integer,Integer>();
		
		for(int i=n-1;i>=0;i--){
			long next = a[i] * 1L *  k;
			if(next < Integer.MAX_VALUE && next > Integer.MIN_VALUE){
				int wow = (int)next;
				Integer cnt = count.get(wow);
				p1[i] = (cnt == null) ? 0 : cnt;
			}
			if(count.containsKey(a[i]))
				count.put(a[i], count.get(a[i]) + 1);
			else
				count.put(a[i], 1);
		}
		
		long ans = 0;
		HashMap<Integer,Long> ct2 = new HashMap<Integer,Long>();
		
		for(int i=n-1;i>=0;i--){
			long next = a[i] * 1L * k;
			if(next < Integer.MAX_VALUE && next > Integer.MIN_VALUE){
				int wow = (int)next;
				Long cnt = ct2.get(wow);
				ans += cnt == null ? 0 : cnt;
			}
			if(ct2.containsKey(a[i]))
				ct2.put(a[i], ct2.get(a[i]) + p1[i]);
			else
				ct2.put(a[i], (long)p1[i]);
		}
		
		w.println(ans);
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
}
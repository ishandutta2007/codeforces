import java.io.*;
import java.util.*;
import java.math.*;

public class R328qC {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter p = new PrintWriter(System.out);
		
		BigInteger t = new BigInteger(in.readString());
		BigInteger w = new BigInteger(in.readString());
		BigInteger b = new BigInteger(in.readString());
		
		BigInteger lcm = w.multiply(b).divide(w.gcd(b));
		BigInteger min = w.min(b);
		
		BigInteger cnt = t.divide(lcm);
		BigInteger ans = BigInteger.ZERO;
		
		ans = ans.add(cnt.multiply(min));
		
		BigInteger last = lcm.multiply(cnt);
		ans = ans.add(min.min(t.add(BigInteger.ONE).subtract(last)));
		ans = ans.subtract(BigInteger.ONE);
		
		BigInteger gcd = ans.gcd(t);
		ans = ans.divide(gcd);
		t = t.divide(gcd);
		
		p.println(ans.toString() + "/" + t.toString());
		p.close();
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
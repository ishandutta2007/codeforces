import java.io.*;
import java.util.*;

public class R332qA {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int p[][] = new int[3][3];
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				p[i][j] = Integer.MAX_VALUE / 3;
		
		int d1,d2,d3;
		
		d1 = p[0][1] = p[1][0] = in.nextInt();
		d2 = p[0][2] = p[2][0] = in.nextInt();
		d3 = p[1][2] = p[2][1] = in.nextInt();
		
		for(int k=0;k<3;k++)
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					p[i][j] = Math.min(p[i][j], p[i][k] + p[k][j]);
		
		int ans1 = p[0][1] + p[1][2] + p[2][0];
		int ans2 = p[0][2] + p[2][1] + p[1][0];
		
		int ans = Math.min(ans1, ans2);
		ans = Math.min(ans, d1 + d3 + d2);
		ans = Math.min(ans, d1 + d1 + d2 + d2);
		ans = Math.min(ans, d1 + d3 + d3 + d1);
		ans = Math.min(ans, d2 + d3 + d3 + d2);
		
		w.println(ans);
		
		w.close();
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
		
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
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

	}

}
import java.io.*;
import java.util.*;

public class R317qB {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int k = in.nextInt();
		
		int a[] = new int[n];
		for(int i = 0; i < n; i++)
			a[i] = in.nextInt();
		
		Arrays.sort(a);
		
		long p[] = new long[n];
		for(int i = 1; i < n; i++)
			p[i] = p[i - 1] + a[i] - a[i - 1];
		
		int f = n/k;
		int x = n % k; // x groups of (f + 1) size
		int y = k - x; // y groups of   (f)   size
		
		long dp[][] = new long[x + 1][y + 1];
		
		for(int i = x;i >= 0; i--){
			for(int j = y; j >= 0; j--){
				if(i < x || j < y)
					dp[i][j] = Long.MAX_VALUE; 
				if(i < x)
					dp[i][j] = Math.min(dp[i][j], dp[i + 1][j] + p[g(i+1,j,f) - 1] - p[g(i,j,f)]);
				if(j < y)
					dp[i][j] = Math.min(dp[i][j], dp[i][j + 1] + p[g(i,j+1,f) - 1] - p[g(i,j,f)]);
			}
		}
		
		w.println(dp[0][0]);
		w.close();
	}
	
	static int g(int i,int j,int f){
		return i * (f + 1) + j * f;
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
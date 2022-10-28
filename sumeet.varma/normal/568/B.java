import java.io.*;
import java.util.*;

public class R315qD {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int mod = (int)1e9 + 7;
		int c[][] = new int[4100][4100];
		
		c[0][0] = 1;
		for(int i=1;i<4100;i++){
			c[i][0] = c[i][i] = 1;
			for(int j=1;j<i;j++){
				c[i][j] = c[i-1][j] + c[i-1][j-1];
				if(c[i][j] >= mod)
					c[i][j] -= mod;
			}
		}
		
		long b[] = new long[4100];
		b[0] = 1;
		b[1] = 1;
		b[2] = 2;
		b[3] = 5;
		
		for(int i=3;i<=4051;i++)
			for(int j=0;j<=i;j++)
				b[i+1] = (b[i+1] + c[i][j] * b[j]) % mod;
		
		int n = in.nextInt();
		long ans = b[n+1] - b[n];
		ans %= mod;
		if(ans < 0)
			ans += mod;
		ans %= mod;
		if(ans < 0)
			ans += mod;

		w.println(ans);
		
		w.close();
	}
	
	

	private static boolean getRef3(boolean[][] state, int n) {
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
					if(state[i][j] && state[j][k] && !state[i][k])
						return false;
		return true;
	}


	private static boolean getRef2(boolean[][] state, int n) {
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(state[i][j] != state[j][i])
					return false;
		return true;
	}



	private static boolean getRef1(boolean[][] state,int n) {
		for(int i=0;i<n;i++)
			if(!state[i][i])
				return false;
		return true;
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
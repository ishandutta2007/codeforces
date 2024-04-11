import java.io.*;
import java.util.*;

public class _8VCFinalqB {

	static int N = 50;
	static long dp[][];
	static long x,s;
	
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		s = in.nextLong();
		x = in.nextLong();

		dp = new long[N + 1][2];
		dp[N][0] = 1;
		dp[N][1] = 0;
		
		for(int i = 0; i < N; i++)
			dp[i][0] = dp[i][1] = -1;
		
		long ans = DP(0 , 0);
		if(s == x)
			ans -= 2;
		w.println(ans);
		w.close();
	}
	
	static long DP(int i, int c){
		if(dp[i][c] == -1){
			long ans = 0;
			
			int d = (s & (1L << i)) != 0 ? 1 : 0;
			int e = (x & (1L << i)) != 0 ? 1 : 0;
			
			for(int a = 0; a < 2; a++){
				for(int b = 0; b < 2; b++){
					if((a ^ b) == e){
						int f = (a + b + c) % 2;
						int g = (a + b + c) / 2;
						if(f == d){
							ans += DP(i + 1 , g);
						}
					}
				}
			}
			
			dp[i][c] = ans;
		}
		//System.out.println(i + " " + c + " " + dp[i][c]);
		return dp[i][c];
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
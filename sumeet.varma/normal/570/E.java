import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;


public class R316qE {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		char s[][] = new char[n][m];
		for(int i=0;i<n;i++)
			s[i] = in.readString().toCharArray();
		
		int mod = (int)1e9 + 7;
		int dp[][][] = new int[n][n][2];
		
		for(int steps=(n+m-2)/2;steps>=0;steps--){
			for(int x=0;x<n;x++){
				for(int y=0;y<n;y++){
					int a = x;
					int b = steps - x;
					int c = n - 1 - y;
					int d = m - 1 - (steps - y);
					if(a < 0 || b < 0 || a >= n || b >= m)
						continue;
					if(c < 0 || d < 0 || c >= n || d >= m)
						continue;
					if(s[a][b] == s[c][d]){
						if(steps == (n + m - 2)/2){
							if(c >= a && d >= b && ((c - a) + (d - b)) <= 1)
								dp[x][y][0] = 1;
							else
								dp[x][y][0] = 0;
						}
						else{
							dp[x][y][0] = 0;
							if(b + 1 < m && d - 1 >= 0)dp[x][y][0] += dp[x][y][1];
							if(dp[x][y][0] >= mod)
								dp[x][y][0] -= mod;
							if(b + 1 < m && c - 1 >= 0)dp[x][y][0] += dp[x][y+1][1];
							if(dp[x][y][0] >= mod)
								dp[x][y][0] -= mod;
							if(a + 1 < n && d - 1 >= 0)dp[x][y][0] += dp[x+1][y][1];
							if(dp[x][y][0] >= mod)
								dp[x][y][0] -= mod;
							if(a + 1 < n && c - 1 >= 0)dp[x][y][0] += dp[x+1][y+1][1];
							if(dp[x][y][0] >= mod)
								dp[x][y][0] -= mod;
						}
					}
				}
			}
			for(int x=0;x<n;x++){
				for(int y=0;y<n;y++){
					dp[x][y][1] = dp[x][y][0];
					dp[x][y][0] = 0;
				}
			}
		}
		
		w.println(dp[0][0][1]);
		
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
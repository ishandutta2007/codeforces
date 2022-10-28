import java.io.*;
import java.util.*;

public class R327qDTopSecretTask {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		int k = in.nextInt();
		int s = in.nextInt();
		s = Math.min(s, n * (n + 1) / 2);
		
		int a[] = new int[n];
		for(int i=0;i<n;i++)
			a[i] = in.nextInt();
		
		int oo = (int)5e8;
		int dp[][][] = new int[2][k + 1][s + 1];
		for(int i=0;i<=k-1;i++)
			Arrays.fill(dp[1][i], oo);
		Arrays.fill(dp[1][k],0);
		
		for(int i=n-1;i>=0;i--){
			int t = Math.min(i,k);
			for(int j=0;j<=t;j++){
				for(int swap=0;swap<=s;swap++){
					dp[0][j][swap] = dp[1][j][swap];
					if(j < k && swap - (i - j) >= 0)
						dp[0][j][swap] = Math.min(dp[1][j+1][swap - (i - j)] + a[i], dp[0][j][swap]);
				}
			}
			for(int j=0;j<=t;j++)
				for(int swap=0;swap<=s;swap++)
					dp[1][j][swap] = dp[0][j][swap];
		}
		
		w.println(dp[1][0][s]);
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
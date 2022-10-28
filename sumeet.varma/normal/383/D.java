import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;

public class R225AntiMatter {

	static int MAXN = 1000;
	static int limit = 10000;
	static int mod = (int)1e9 + 7;
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		int a[] = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		
		long dp[][] = new long[2][2*limit + 2];
		long ans = 0;
		
		for(int i=0;i<n;i++){
			for(int j=-limit;j<=limit && i != 0;j++){
				if(j - a[i] + limit >= 0)
					dp[1][j + limit] = dp[0][j - a[i] + limit];
				if(j + a[i] + limit < 2*limit && j + a[i] + limit >= 0)
					dp[1][j + limit] += dp[0][j + a[i] + limit];
				if(dp[1][j + limit] >= mod)	dp[1][j + limit] -= mod;
			}
			dp[1][limit + a[i]]++;
			dp[1][limit - a[i]]++;
			ans += dp[1][limit];
			for(int j=-limit;j<=limit;j++)
				dp[0][limit+j] = dp[1][limit+j];
		}
		
		w.print(ans % mod);
		w.close();
	}

	public static int m(int x){
		return limit + x;
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[1024];
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
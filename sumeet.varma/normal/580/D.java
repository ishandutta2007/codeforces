import java.io.*;
import java.util.*;

public class R321qD {
	
	static int n,m,k;
	static long a[];
	static int c[][];
	static int cnt[];
	static long dp[][];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
		m = in.nextInt();
		k = in.nextInt();
		
		a = new long[n];
		for(int i=0;i<n;i++)
			a[i] = in.nextInt();
		
		c = new int[n + 1][n + 1];
		while(k-- > 0)
			c[in.nextInt() - 1][in.nextInt() - 1] = in.nextInt();
		
		cnt = new int[1<<n];
		for(int i=0;i<1<<n;i++)
			for(int j=0;j<n;j++)
				if(((1<<j) & i) != 0)
					cnt[i]++;
			
		dp = new long[n + 1][1<<n];
		for(int i=0;i<=n;i++)
			for(int j=0;j<(1<<n);j++)
				dp[i][j] = -1;
		
		w.println(DP(n,0));
		w.close();
	}

	public static long DP(int prev,int mask){
		if(dp[prev][mask] == -1){
			if(cnt[mask] == m)
				dp[prev][mask] = 0;
			else{
				long ans = 0;
				for(int i=0;i<n;++i)
					if( (mask & (1<<i)) == 0)
						ans = Math.max(ans, a[i] + c[prev][i] + DP(i,mask | (1<<i)));
				dp[prev][mask] = ans;
			}
		}
		return dp[prev][mask];
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
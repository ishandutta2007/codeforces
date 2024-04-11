import java.io.*;
import java.util.*;  

public class R309qA {

	static int c[][];
	static int n,k;
	static int a[],pre[];
	static int mod = (int)1e9 + 7;
	static long dp[][];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		c = new int[1001][1001];
		c[0][0] = 1;
		
		for(int i=1;i<=1000;i++){
			c[i][0] = c[i][i] = 1;
			for(int j=1;j<i;j++){
				c[i][j] = c[i-1][j] + c[i-1][j-1];
				if(c[i][j] >= mod)	c[i][j] %= mod;
			}
		}
		
		k = in.nextInt();

		a = new int[k];
		for (int i = 0; i < k; i++)
			a[i] = in.nextInt();
		
		pre = new int[k];
		pre[0] = a[0];
		for(int i = 1;i <k; i++)
			pre[i] = pre[i-1] + a[i];
		
		n = 0;
		for(int i=0;i<k;i++)
			n += a[i];
		
		dp = new long[n + 1][k + 1];
		for(int i=0;i<k;i++)
			dp[n][i] = 0;
		dp[n][k] = 1;
		
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<k;j++){
				if(i + 1 >= pre[j]){
					if(a[j] != 1)	dp[i][j] = j == 0 ? dp[i+1][j+1] * 1L * c[i][a[j]-1]: dp[i+1][j+1] * 1L * c[i - pre[j-1]][a[j]-1];
					else	dp[i][j] = dp[i+1][j+1];			
				}
				dp[i][j] += dp[i+1][j];
				if(dp[i][j] >= mod)	dp[i][j] %= mod;
			}
		}

		w.println(dp[0][0]);
		w.close();
	}
	
	/*
	static public long solve(int i,int j){
		if(dp[i][j] == -1){
			dp[i][j] = 0;
			if(i + 1 >= pre[j]){
				if(a[j] != 1)	dp[i][j] = j == 0 ? solve(i+1,j+1) * c[i][a[j]-1]: solve(i+1,j+1) * 1L * c[i - pre[j-1]][a[j]-1];
				else	dp[i][j] = solve(i+1,j+1);				
				if(i == 1 && j == 0)
					System.out.println(dp[i][j]);
			}
			if(i == 1 && j == 0)	System.out.println(solve(i+1,j));
			dp[i][j] += solve(i+1,j);
			dp[i][j] %= mod;
		}
		return dp[i][j];
	}*/

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
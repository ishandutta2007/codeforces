import java.io.*;
import java.util.*;

public class R190qECeilAndGondolas {

	static final int INF = (int)1e9;
	static int n,k;
	static int a[][],pre[][],cost[][];
	static int dp[][],best[][];
	
	public static void main(String args[]){
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
		k = in.nextInt();
		
		a = new int[n + 1][n + 1];
		pre = new int[n + 1][n + 1];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				a[i][j] = in.nextInt();
				pre[i][j] = pre[i][j-1] + a[i][j];
			}
		
		cost = new int[n + 2][n + 2];
		for(int i=n;i>=1;i--)
			for(int j=i;j<=n;j++)
				cost[i][j] = cost[i+1][j] + pre[i][j] - pre[i][i];
		
		dp = new int[n + 1][k + 1];
		best = new int[n + 1][k + 1];
		
		for(int i=1;i<=n;i++)
			dp[i][0] = INF;
		dp[0][0] = 0;
		
		for(int j=1;j<=k;j++)
			go(1,n,j,0,n);
		
		w.println(dp[n][k]);
		w.close();
	}
	
	//best[i][k] >= best[i-1][k]
	static public void go(int start,int end,int k,int lb,int rb){
		
		if(start > end)
			return;
		
		int mid = (start + end) >> 1;
		dp[mid][k] = INF;
		for(int i=lb;i<=Math.min(rb, mid-1);i++){
			if(dp[i][k-1] + cost[i+1][mid] < dp[mid][k]){
				dp[mid][k] = dp[i][k-1] + cost[i+1][mid];
				best[mid][k] = i;
			}
		}
		
		go(start,mid-1,k,lb,best[mid][k]);
		go(mid+1,end,k,best[mid][k],rb);
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
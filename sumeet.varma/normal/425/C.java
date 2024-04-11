import java.io.*;
import java.util.*;

public class R243qCSerejaAndTwoSequences {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		int m = in.nextInt();
		int s = in.nextInt();
		int e = in.nextInt();
		
		final int limit = 100010;
		final int max = s/e;
		
		int a[] = new int[n + 1];
		for(int i=1;i<=n;i++)
			a[i] = in.nextInt();
		
		int cnt[] = new int[limit];
		int ptr[] = new int[limit];
	
		int b[] = new int[m + 1];
		for(int i=1;i<=m;i++)
			cnt[b[i] = in.nextInt()]++;
		
		int pos[][] = new int[limit][];
		for(int i=1;i<limit;i++)
			pos[i] = new int[cnt[i] + 1];
		
		for(int i=1;i<=m;i++)
			pos[b[i]][ptr[b[i]]++] = i;
		
		int dp[][] = new int[max + 1][n + 1];
		int min[][] = new int[max + 1][n + 1];
		int ans = 0;
		
		for(int k=1;k<=max;k++){
			dp[k][0] = min[k][0] = m + 1;
			for(int i=1;i<=n;i++){
				if(min[k-1][i-1] >= m)
					dp[k][i] = m + 1;
				else{
					int start = 0,end = cnt[a[i]];
					dp[k][i] = m + 1;
					while(start < end){
						int mid = (start + end) >> 1;
						if(pos[a[i]][mid] > min[k-1][i-1]){
							end = mid;
							dp[k][i] = pos[a[i]][mid];
						}
						else
							start = mid + 1;
					}
					if(dp[k][i] <= m){
						if(i + dp[k][i] + k*e <= s)
							ans = Math.max(ans, k);
					}
							
				}
				min[k][i] = Math.min(min[k][i-1], dp[k][i]);
			}
		}
		
		w.println(ans);
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
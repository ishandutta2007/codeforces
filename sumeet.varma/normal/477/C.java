import java.io.*;
import java.util.*;

public class R272qcDreamoonAndStrings {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		char s[] = in.readString().toCharArray();
		char p[] = in.readString().toCharArray();
		
		int n = s.length;
		int m = p.length;
		
		int last[] = new int[n];
		Arrays.fill(last, -1);
		
		for(int i=0;i<n;i++){
			int curr = 0;
			for(int j=i;j<n;j++){
				if(s[j] == p[curr]){
					curr++;
					if(curr == m){
						last[i] = j;
						break;
					}
				}
			}
		}
		
		int dp[][] = new int[n + 1][n + 1];
		Arrays.fill(dp[n], -1000000);
		dp[n][0] = 0;
		
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<=n;j++){
				dp[i][j] = dp[i+1][j];
				if(j != 0)
					dp[i][j] = Math.max(dp[i + 1][j - 1], dp[i][j]);
				if(last[i] != -1){
					int length = last[i] - i + 1;
					int remove = length - m;
					if(remove <= j)
						dp[i][j] = Math.max(dp[i][j], 1 + dp[last[i] + 1][j - remove]);
				}
			}
		}
		
		for(int i=0;i<=n;i++)
			w.print(dp[0][i] + " ");
		w.println();
		
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
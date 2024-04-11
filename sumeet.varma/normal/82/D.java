import java.io.*;
import java.util.*;

public class Yandex2011QualificationqDTwoOutOfThree {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int a[] = in.nextIntArray(n);
		
		int dp[][] = new int[n + 2][n + 2];
		int best[][] = new int[n + 2][n + 2];
		
		for(int i = 0; i < n; i++){
			dp[i][n] = a[i];
			best[i][n] = -1;
		}
		dp[n][n] = 0;
		dp[n][n + 1] = 0;
		best[n][n + 1] = best[n][n] = -2;
		
		for(int i = n - 1; i >= 0; i--){
			for(int j = 0; j < i; j++){
				dp[j][i] = dp[i + 1][i + 2] + Math.max(a[j], a[i]);
				best[j][i] = 0;
				if(i + 1 < n){
					int now = dp[j][i + 2] + Math.max(a[i], a[i + 1]);
					if(now < dp[j][i]){
						dp[j][i] = now;
						best[j][i] = 1;
					}
					now =  Math.max(a[j], a[i + 1]) + dp[i][i + 2];
					if(now < dp[j][i]){
						dp[j][i] = now;
						best[j][i] = 2;
					}
				}
			}
		}

		w.println(dp[0][1]);
		
		int x = 0,y = 1;
		while(true){
			if(best[x][y] == 0){
				w.println((x+1) + " " + (y+1));
				x = y + 1;
				y = y + 2;
			}
			else if(best[x][y] == 1){
				w.println((y+1) + " " + (y+2));
				y = y + 2;
			}
			else if(best[x][y] == 2){
				w.println((x+1) + " " + (y+2));
				x = y;
				y = y + 2;
			}
			else if(best[x][y] == -1){
				w.println((x+1));
				break;
			}
			else
				break;
		}
		w.close();
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
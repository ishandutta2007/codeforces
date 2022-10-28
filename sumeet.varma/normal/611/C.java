import java.io.*;
import java.util.*;

public class GoodBye15qC {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		char s[][] = new char[n + 2][m + 2];
		for(int i = 1; i <= n; i++)
			s[i] = ("#" + in.readString() + "#").toCharArray();
		
		int r[][] = new int[n + 2][m + 2];
		int d[][] = new int[n + 2][m + 2];
		
		for(int i = 1;i <= n; i++){
			for(int j = 1;j <= m; j++){
				r[i][j] = r[i - 1][j] + r[i][j - 1] - r[i - 1][j - 1];
				d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
				if(s[i][j] == '.' && j + 1 <= m && s[i][j+1] == '.')
					r[i][j]++;
				if(s[i][j] == '.' && i + 1 <= n && s[i+1][j] == '.')
					d[i][j]++;
			}
		}
		
		int q = in.nextInt();
		
		while(q-- > 0){
			int r1 = in.nextInt();
			int c1 = in.nextInt();
			int r2 = in.nextInt();
			int c2 = in.nextInt();
			int ans = 0;
			if(c2 > c1){
				c2--;
				ans += r[r2][c2] - r[r2][c1-1] - r[r1-1][c2] + r[r1-1][c1-1];
				c2++;
			}
			if(r2 > r1){
				r2--;
				ans += d[r2][c2] - d[r2][c1-1] - d[r1-1][c2] + d[r1-1][c1-1];
				r2++;
			}
			w.println(ans);
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
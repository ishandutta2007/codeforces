import java.io.*;
import java.util.*;

public class _8VCVentureCupqB {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		
		char x[] = new char[]  { 'B' , 'G', 'R'};
		char s[] = in.readString().toCharArray();
		
		int cnt[] = new int[3];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 3; j++)
				if(s[i] == x[j])
					cnt[j]++;
		}
		
		boolean dp[][][] = new boolean[205][205][205];
		
		dp[cnt[0]][cnt[1]][cnt[2]] = true;
		
		for(int sum = n; sum >= 2; sum--){
			for(int a = 0;a <= sum; a++){
				for(int b = 0; a + b <= sum; b++){
					int c = sum - a - b;
					if(dp[a][b][c]){
						if(a >= 2)
							dp[a - 1][b][c] = true;
						if(b >= 2)
							dp[a][b - 1][c] = true;
						if(c >= 2)
							dp[a][b][c - 1] = true;
						if(a >= 1 && b >= 1)
							dp[a - 1][b - 1][c + 1] = true;
						if(b >= 1 && c >= 1)
							dp[a + 1][b - 1][c - 1] = true;
						if(a >= 1 && c >= 1)
							dp[a - 1][b + 1][c - 1] = true;
					}
				}
			}
		}
		
		if(dp[1][0][0])
			w.print('B');
		if(dp[0][1][0])
			w.print('G');
		if(dp[0][0][1])
			w.print('R');
		w.println();
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
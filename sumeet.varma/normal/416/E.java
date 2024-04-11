import java.io.*;
import java.util.*;

public class R241qEPresidentsPath {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		int m = in.nextInt();
		
		int d[][] = new int[n + 1][n + 1];
		int e[][] = new int[n + 1][n + 1];
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j] = (int)1e8;
		
		for(int i=1;i<=n;i++)
			d[i][i] = 0;
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				e[i][j] = (int)2e8;
		
		for(int i=1;i<=m;i++){
			int x = in.nextInt();
			int y = in.nextInt();
			int l = in.nextInt();
			d[x][y] = d[y][x] = l;
			e[x][y] = e[y][x] = l;
		}
		
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
		
		int ending[][] = new int[n + 1][n + 1];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					if(d[i][k] + e[k][j] == d[i][j])
						ending[i][j]++;
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int ans = 0;
				for(int k=1;k<=n;k++)
					if(d[i][k] + d[k][j] == d[i][j])
						ans += ending[i][k];
				w.print(ans + " ");
			}
		}
		
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
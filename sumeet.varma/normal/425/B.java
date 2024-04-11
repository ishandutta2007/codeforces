import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class R243qBSerejaAndTable {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		
		int a[][] = new int[n + 2][m + 2];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				a[i][j] = in.nextInt();
		
		int ans = Integer.MAX_VALUE;
		
		if(n > k){
			
			for(int i=0;i<n;i++){
				int nowAns = 0;
				for(int j=0;j<n;j++){
					int c1 = 0,c2 = 0;
					for(int x=0;x<m;x++)
						if(a[i][x] == a[j][x])
							c1++;
						else
							c2++;
					nowAns += Math.min(c1,c2);
				}
				ans = Math.min(ans, nowAns);
			}
			
		}
		
		else{
			for(int mask=0;mask<(1<<n);mask++){
				int nowAns = 0;
				
				int bit[] = new int[n];
				for(int j=0;j<n;j++)
					bit[j] = (mask & (1<<j)) != 0 ? 1 : 0;
				
				for(int j=0;j<m;j++){
					int c1 = 0,c2 = 0;
					for(int x=0;x<n;x++)
						if(a[x][j] == bit[x])
							c1++;
						else
							c2++;
					nowAns += Math.min(c1,c2);
				}
				
				ans = Math.min(ans, nowAns);
			}
		}
		
		w.println(ans > k ? -1 : ans);
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
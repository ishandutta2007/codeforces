import java.io.*;
import java.util.*;

public class R238qAUnusualProduct {

	public static void main(String args[]) throws Exception{
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		
		int a[][] = new int[n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j] = in.nextInt();
		
		int ans = 0;
		for(int i=0;i<n;i++)
			ans += a[i][i];
		ans %= 2;
		
		int Q = in.nextInt();
		for(int q=0;q<Q;q++){
			int type = in.nextInt();
			if(type == 1){
				int row = in.nextInt() - 1;
				if(a[row][row] == 1){
					a[row][row] = 0;
					ans -= 1;
				}
				else{
					a[row][row] = 1;
					ans += 1;
				}
				if(ans == -1)	ans = 1;
				if(ans == 2)	ans = 0;
			}
			else if(type == 2){
				int col = in.nextInt() - 1;
				if(a[col][col] == 1){
					a[col][col] = 0;
					ans -= 1;
				}
				else{
					a[col][col] = 1;
					ans += 1;
				}
				if(ans == -1)	ans = 1;
				if(ans == 2)	ans = 0;
			}
			else{
				w.print(ans);
			}
		}
		w.close();
	}
	
	
	static public class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[1024];
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
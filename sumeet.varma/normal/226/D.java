import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class R140qDTable {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();

		int a[][] = new int[n][m];
		int row[] = new int[n];
		int col[] = new int[m];
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++){
				a[i][j] = in.nextInt();
				row[i] += a[i][j];
				col[j] += a[i][j];
			}
		
		boolean found = true;
		int rx[] = new int[n];
		int cx[] = new int[m];
		while(found){
			
			found = false;
	
			for(int i=0;i<n;i++)
				if(row[i] < 0){
					found = true;
					row[i] *= -1;
					for(int j=0;j<m;j++)
						a[i][j] *= -1;
					for(int j=0;j<m;j++)
						col[j] += 2*a[i][j];
					rx[i]++;
					break;
				}
		
			if(found)
				continue;
			
			for(int i=0;i<m;i++)
				if(col[i] < 0){
					found = true;
					col[i] *= -1;
					for(int j=0;j<n;j++)
						a[j][i] *= -1;
					for(int j=0;j<n;j++)
						row[j] += 2*a[j][i];
					cx[i]++;
					break;
				}
			
		}
		
		for(int i=0;i<n;i++)
			rx[i] = rx[i] & 1;
		
		for(int j=0;j<m;j++)
			cx[j] = cx[j] & 1;
		
		int c = 0;
		for(int i=0;i<n;i++)
			c += rx[i];
		
		w.print(c +  " ");
		for(int i=0;i<n;i++)
			if(rx[i] == 1)
				w.print((i+1) + " ");
		w.println();
		
		c = 0;
		for(int i=0;i<m;i++)
			c += cx[i];
		
		w.print(c + " ");
		for(int i=0;i<m;i++)
			if(cx[i] == 1)
				w.print((i+1) + " ");
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
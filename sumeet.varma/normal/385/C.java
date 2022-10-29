import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;

public class R226qCBearAndPrimeNumbers {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int up = (int)1e7;
		
		int der[] = new int[up + 1];
		for(int i=0;i<n;i++)
			der[in.nextInt()]++;
		
		int ans[] = new int[up + 1];
		boolean common[] = new boolean[up + 1];
		for(int i=2;i<=up;i++)
			if(!common[i]){
				for(int j=i;j<=up;j+=i){
					ans[i] += der[j];
					common[j] = true;
				}
			}
	
		for(int i=2;i<=up;i++)
			ans[i] += ans[i-1];
		
		int m = in.nextInt();
		
		while(m-- > 0){
			int l = in.nextInt();
			int r = in.nextInt();
			r = Math.min(r, up);
			l = Math.min(l, up);
			w.println(ans[r] - ans[l-1]);
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
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;


public class Taxi {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		int count[] = new int[5];
		for (int i = 0; i < n; i++)
			count[in.nextInt()]++;

		int ans = 0;
		
		//2 2
		ans += count[2]/2;
		count[2] -= 2*(count[2]/2);
		
		//1 3
		int t = Math.min(count[1], count[3]);
		ans += t;
		count[1] -= t;
		count[3] -= t;
		
		//1 2 2
		t = Math.min(count[1]/2, count[2]);
		count[1] -= 2*t;
		count[2] -= t;
		ans += t;
		
		//1 2
		t = Math.min(count[1], count[2]);
		ans += t;
		count[1] -= t;
		count[2] -= t;
		
		//1 1 1 1
		ans += Math.ceil(count[1] * 1.0/4);
		count[1] -= count[1];
		
		//2 2
		ans += count[2];
		count[2] -= count[2];
		
		//3
		ans += count[3];
		count[3] -= count[3];
		
		//4
		ans += count[4];
		count[4] -= count[4];
		
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
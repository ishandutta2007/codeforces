import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;

public class R298qAExam {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		if(n == 1 || n == 2){
			System.out.println("1");
			System.out.println("1");
			return;
		}
		
		if(n == 3){
			System.out.println("2");
			System.out.println("1 3");
			return;
		}
		
		if(n == 4){
			System.out.println("4");
			System.out.println("3 1 4 2");
			return;
		}
		
		int a[] = new int[n];
		int j = 0;
		
		for(int i=1;i<=n;i+=2,j++)
			a[j] = i;
		
		for(int i=2;i<=n;i+=2,j++)
			a[j] = i;
		
		w.println(j);
		for(int i=0;i<j;i++)
			w.print(a[i] + " ");
		w.println();
	
		w.close();
	}

	static class InputReader {

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
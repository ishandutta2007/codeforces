import java.io.*;
import java.util.*;

public class R308qD {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		int x[] = new int[n];
		int y[] = new int[n];
		
		for(int i=0;i<n;i++){
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}
		
		long ans = ((long)n * (n-1) * (n-2));
		int k,c;
		
		double eps = 1e-15;
		long wow = 0;
		
		double slopes[] = new double[n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j == i)
					slopes[j] = -10000000;
				else
					slopes[j] = 1.0 * (y[j] - y[i]) * 1.0 / (x[j] - x[i]);
				if(Double.isInfinite(slopes[j]))
					slopes[j] = 100000000;
			}
			Arrays.sort(slopes);
			for(int j=1;j<n;){
				k = j;
				while(k < n && Math.abs(slopes[j] - slopes[k]) <= eps)
					k++;
				c = k - j;
				wow += Math.max(0,c*(c-1));
				j = k;
			}
		}
		
		w.println((ans - wow)/6);
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
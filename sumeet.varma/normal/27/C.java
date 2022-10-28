import java.io.*;
import java.util.*;

//java.is.awesome

public class R27qCUnorderedSubsequence {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int a[] = in.nextIntArray(n);
		
		int pM[] = new int[n];
		int pm[] = new int[n];
		
		int sM[] = new int[n];
		int sm[] = new int[n];
		
		pM[0] = pm[0] = 0;
		
		for(int i = 1; i < n; i++){
			pM[i] = a[i] > a[pM[i - 1]] ? i : pM[i - 1];
			pm[i] = a[i] < a[pm[i - 1]] ? i : pm[i - 1];
		}
		
		sM[n - 1] = sm[n - 1] = n - 1;
		
		for(int i = n - 2; i >= 0; i--){
			sM[i] = a[i] > a[sM[i + 1]] ? i : sM[i + 1];
			sm[i] = a[i] < a[sm[i + 1]] ? i : sm[i + 1];
		}
		
		for(int i = 1; i < n - 1; i++){
			if(a[pM[i - 1]] > a[i] && a[sM[i + 1]] > a[i]){
				w.println(3);
				w.println( (pM[i - 1] + 1) + " " + (i + 1) + " " + (sM[i + 1] + 1));
				w.close();
				return;
			}
			if(a[pm[i - 1]] < a[i] && a[sm[i + 1]] < a[i]){
				w.println(3);
				w.println( (pm[i - 1] + 1) + " " + (i + 1) + " " + (sm[i + 1] + 1));
				w.close();
				return;
			}
		}
		
		w.println(0);
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
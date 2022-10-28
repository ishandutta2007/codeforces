import java.io.*;
import java.util.*;

public class R107qAFreeze {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		long n = in.nextLong();
		
		long div1[] = new long[50001];
		long div2[] = new long[50001];
		int k1 = 0, k2 = 0;
		
		div2[k2++] = n;
		
		for(long i = 2; i * i <= n; i++){
			if( (n % i == 0) ){
				div1[k1++] = i;
				if(i * i != n)
					div2[k2++] = n / i;
			}
		}
		
		
		long div[] = new long[k1 + k2];
		int k = 0;
		for(int i = 0; i < k1; i++)
			div[k++] = div1[i];
		for(int i = k2 - 1; i >= 0; i--)
			div[k++] = div2[i];
		
		boolean win[] = new boolean[k];
		for(int i = 0; i < k; i++){
			boolean found = false;
			win[i] = false;
			for(int j = 0; j < i; j++){
				if(div[i] % div[j] == 0){
					win[i] |= !win[j];
					found = true;
				}
			}
			win[i] |= !found;
		}
		
		if(win[k - 1]){
			w.println("1");
			boolean f = false;
			for(int j = 0; j < k - 1; j++){
				if(n % div[j] == 0 && !win[j]){
					w.println(div[j]);
					f = true;
					break;
				}
			}
			if(!f)
				w.println(0);
		}
		else
			w.println("2");
		
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
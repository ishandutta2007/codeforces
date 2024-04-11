import java.io.*;
import java.util.*;

public class R338qD {

	public static void main(String args[]) throws Exception {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		final int mod = (int) 1e9 + 7;
		final int pmod = mod - 1;
		//final int max = 5;
		final int max = 2 * 100000 + 100;

		int m = in.nextInt();
		
		int a[] = new int[max];
		for (int i = 0; i < m; i++)
			a[in.nextInt()]++;

		long pre[] = new long[max];
		long suf[] = new long[max];

		//System.out.println(Arrays.toString(a));
		pre[0] = 1;
		for (int i = 1; i < max; i++)
			pre[i] = ((a[i] + 1) * pre[i - 1]) % pmod;

		//System.out.println(Arrays.toString(pre));
		suf[max - 1] = 1;
		for (int i = max - 2; i >= 0; i--)
			suf[i] = ((a[i] + 1) * suf[i + 1]) % pmod;

		//System.out.println(Arrays.toString(suf));
		long ans = 1;
		
		for(int i = 2; i + 1 < max; i++){
			long curr = i;
			long oth = (pre[i - 1] * suf[i + 1]) % pmod;
			for(int j = 1; j <= a[i]; j++){
				ans = (ans * pow(curr, oth, mod)) % mod;
				curr = (curr * i) % mod;
			}
		}
		
		w.println(ans);
		w.close();
	}
	
	static long pow(long a,long b,long mod){
		if(b == 0)
			return 1;
		long t = pow(a, b >> 1, mod);
		t = (t * t) % mod;
		if( (b & 1) != 0)
			t = (t * a) % mod;
		return t;
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
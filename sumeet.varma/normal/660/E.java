import java.io.*;
import java.util.*;

public class ER11qE {

	static final int mod = (int)1e9 + 7;
	
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		if(m == 1){
			w.println(n + 1);
			w.close();
			return;
		}
		
		long Mn = pow(m , n);
		
		long ans = Mn;
		
		long A = m;
		A *= inv(m - 1);
		A %= mod;
		
		long B = (1 + A) % mod;
		long t = A;
		
		long C = (m - 1);
		C *= inv(m);
		C %= mod;
		
		long D = C;
		
		for(int l = 1; l <= n; l++){
			
			long now = D;
			now *= Mn;
			now %= mod;
			now *= t;
			
			ans = (ans + now) % mod;
			
			t *= B;
			t %= mod;
			
			D *= C;
			D %= mod;
		}
		
		w.println(ans % mod);
		w.close();
	}
	
	static long inv(long a){
		return pow(a, mod - 2);
	}

	static long pow(long a,int b){
		if(b == 0)
			return 1;
		long t = pow(a, b >> 1);
		t = (t * t) % mod;
		if ( (b & 1) != 0)
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
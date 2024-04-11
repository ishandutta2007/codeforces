import java.io.*;
import java.util.*;

public class R265qCSubstitutesInANumber {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		final int mod = (int)1e9 + 7;
		char s[] = in.readString().toCharArray();
		
		long hash[] = new long[10];
		long pow10[] = new long[10];
		
		for(int i=0;i<=9;i++){
			hash[i] = i;
			pow10[i] = 10;
		}
		
		int n = in.nextInt();
		
		char q[][] = new char[n][];
		for(int i=0;i<n;i++)
			q[i] = in.readString().toCharArray();
		
		for(int i=n-1;i>=0;i--){
			int dig = q[i][0] - '0';
			long newHash = 0;
			long power10 = 1;
			for(int j=q[i].length-1;j>=3;j--){
				newHash = (newHash + hash[q[i][j] - '0'] * power10) % mod;
				power10 = (power10 * pow10[q[i][j] - '0']) % mod;
			}
			hash[dig] = newHash;
			pow10[dig] = power10;
		}
		
		long ans = 0;
		long power10 = 1;
		for(int i=s.length-1;i>=0;i--){
			ans = (ans + hash[s[i] - '0'] * power10) % mod;
			power10 = (power10 * pow10[s[i] - '0']) % mod;
		}
		
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
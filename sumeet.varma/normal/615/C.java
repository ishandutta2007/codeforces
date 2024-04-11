import java.io.*;
import java.util.*;

public class R338qC {

	public static void main(String args[]) throws Exception {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		String s = in.readString();
		String r = new StringBuilder(s).reverse().toString();
		
		String t = in.readString();
		int n = t.length();
		
		int dp[] = new int[n + 1];
		int x[] = new int[n + 1];
		int y[] = new int[n + 1];
		
		dp[n] = 0;
		x[n] = y[n] = -1;
		final int inf = (int)1e8;
		
		for(int i = n - 1; i >= 0; i--){
			String der = t.substring(i, n) + "$" + s;
			int z[] = zFunction(der.toCharArray());
			dp[i] = inf;
			int len = n - i;
			
			for(int j = len + 1,k = 0; j < z.length; j++,k++){
				if(z[j] > 0 && 1 + dp[i + z[j]] < dp[i]){
					dp[i] = 1 + dp[i + z[j]];
					x[i] = k;
					y[i] = k + z[j] - 1;
				}
			}
			
			der = t.substring(i, n) + "$" + r;
			z = zFunction(der.toCharArray());
			len = n - i;
			
			for(int j = len + 1,k = 0; j < z.length; j++,k++){
				if(z[j] > 0 && 1 + dp[i + z[j]] < dp[i]){
					dp[i] = 1 + dp[i + z[j]];
					x[i] = k;
					y[i] = k + z[j] - 1;
					x[i] = s.length() - 1 - x[i];
					y[i] = s.length() - 1 - y[i];
				}
			}
			
			x[i]++;
			y[i]++;
			//System.out.println(dp[i] + " " + x[i] + " " + y[i]);
		}
		
		if(dp[0] >= inf)
			w.println(-1);
		else{
			w.println(dp[0]);
			int curr = 0;
			while(curr < n){
				w.println(x[curr] + " " + y[curr]);
				curr += Math.abs(x[curr] - y[curr]) + 1;
			}
		}

		w.close();
	}
	
	public static int[] zFunction(char pat[]) {
		int n = pat.length;
		int z[] = new int[n];

		int l = 0, r = 0;
		for (int i = 1; i < n; i++) {
			if (i > r) {
				l = r = i;
				while (r < n && pat[r - l] == pat[r])
					r++;
				z[i] = r - l;
				r--;
			} else {
				int k = i - l;
				if (z[k] < r - i + 1)
					z[i] = z[k];
				else {
					l = i;
					while (r < n && pat[r - l] == pat[r])
						r++;
					z[i] = r - l;
					r--;
				}
			}
		}

		// z[0] = 0 , n;
		return z;
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
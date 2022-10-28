import java.io.*;
import java.util.*;

public class R349qC {
	
	static final int mod = (int)1e9 + 7;
	static long fact[];
	static long inv[];
	static long _25[], _26[];
	
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		final int c = (int)1e5 + 10;
		
		fact = new long[c];
		fact[0] = 1;
		for(int i = 1; i < c; i++)
			fact[i] = (i * fact[i - 1]) % mod;
		
		inv = new long[c];
		for(int i = 0; i < c; i++)
			inv[i] = pow(fact[i], mod - 2);
		
		_25 = new long[c];
		_25[0] = 1;
		for(int i = 1; i < c; i++)
			_25[i] = (25 * _25[i - 1]) % mod;
		
		_26 = new long[c];
		_26[0] = 1;
		for(int i = 1; i < c; i++)
			_26[i] = (26 * _26[i - 1]) % mod;
		
		int m = in.nextInt();
		
		TreeSet<Integer> set = new TreeSet<Integer>();
		
		int first = in.readString().length();
		set.add(first);
		
		int a[] = new int[m];
		int b[] = new int[m];
		
		for(int i = 0; i < m; i++){
			a[i] = in.nextInt();
			if(a[i] == 2)
				b[i] = in.nextInt();
			else{
				b[i] = in.readString().length();
				set.add(b[i]);
			}
		}
		
		int map[] = new int[c];
		int val[] = new int[set.size()];
		int ptr = 0;
		for(int x : set){
			map[x] = ptr;
			val[ptr++] = x;
		}
		
		int dp[][] = new int[val.length][c];
			
		for(int i = 0; i < val.length; i++){
			int x = val[i];
			for(int j = x; j < c; j++){
				dp[i][j] = (int)((26L * dp[i][j - 1]) % mod);
				long now = C(j - 1, x - 1);
				now *= _25[j - x];
				now %= mod;
				dp[i][j] += now;
				if(dp[i][j] >= mod)
					dp[i][j] -= mod;
			}
		}
		
		int curr = first;
		
		for(int i = 0; i < m; i++){
			if(a[i] == 2){
				w.println(dp[map[curr]][b[i]]);
			}
			else{
				curr = b[i];
			}
		}
		
		w.close();
	}
	
	static long pow(long a, int b){
		if(b == 0)
			return 1;
		long t = pow(a,b >> 1);
		t = (t * t) % mod;
		if( (b & 1) != 0 )
			t = (t * a) % mod;
		return t;
	}
	
	static long C(int n, int r){
		if(r > n || r < 0)
			return 0;
		return (((fact[n] * inv[r]) % mod) * inv[n - r]) % mod;
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
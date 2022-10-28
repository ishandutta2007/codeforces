import java.io.*;
import java.util.*;

public class R349qA {
	
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		char s[] = in.readString().toCharArray();
		TreeSet<String> ans = new TreeSet<String>();
		
		int n = s.length;
		
		boolean dp2[] = new boolean[n + 1];
		dp2[n] = true;
		
		boolean dp3[] = new boolean[n + 1];
		dp3[n] = true;
		
		for(int i = s.length - 1; i >= 5; i--){
			
			if(i + 1 < s.length){
				boolean c = dp3[i + 2];
				if(dp2[i + 2]){
					if(i + 2 == n)
						c |= true;
					else{
						if(s[i + 2] != s[i] || s[i + 3] != s[i + 1])
							c |= true;
					}
				}
				dp2[i] = c;
				if(dp2[i]){
					String x = new String();
					x = x + s[i];
					x = x + s[i + 1];
					ans.add(x);
				}
			}
			
			if(i + 2 < s.length){
				boolean c = dp2[i + 3];
				if(dp3[i + 3]){
					if(i + 3 == n)
						c |= true;
					else{
						if(s[i + 3] != s[i] || s[i + 4] != s[i + 1] || s[i + 5] != s[i + 2])
							c |= true;
					}
				}
				dp3[i] = c;
				if(dp3[i]){
					String x = new String();
					x = x + s[i];
					x = x + s[i + 1];
					x = x + s[i + 2];
					ans.add(x);
				}
			}
			
		}
		
		w.println(ans.size());
		for(String x : ans)
			w.println(x);
	
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
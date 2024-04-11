import java.io.*;
import java.util.*;

public class ER11qC {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int a[] = in.nextIntArray(n);
		
		ArrayList<Integer> ans = new ArrayList<Integer>();
		ans.add(a[0]);
		
		for(int i = 1; i < n; i++){
			if(gcd(a[i] , a[i - 1]) != 1){
				for(int j = 1; ;j++){
					if(a[i] + j <= (int)1e9){
						if(gcd(a[i] , a[i] + j) == 1 && gcd(a[i] + j, a[i - 1]) == 1){
							ans.add(a[i] + j);
							break;
						}
					}
					if(a[i] - j >= 1){
						if(gcd(a[i] , a[i] - j) == 1 && gcd(a[i] - j, a[i - 1]) == 1){
							ans.add(a[i] - j);
							break;
						}
					}
				}
			}
			ans.add(a[i]);
		}
		
		w.println(ans.size() - n);
		for(int x : ans)
			w.print(x + " ");
		
		w.close();
	}
	
	public static int gcd(int a,int b){
		while(b != 0){ int t = b; b = a%b; a = t;} return a;}

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
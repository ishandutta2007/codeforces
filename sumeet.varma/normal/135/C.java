import java.io.*;
import java.util.*;

public class R97qCZeroOne {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		char s[] = in.readString().toCharArray();
		int cnt[] = new int[3];
		for(char x : s){
			if(x == '?')
				cnt[2]++;
			else
				cnt[x - '0']++;
		}
		
		boolean ans[][] = new boolean[2][2];
		int n = s.length;
		
		int ones = cnt[1] + cnt[2];
		if(ones - (n - 2 + 1) / 2 >= 2)
			ans[1][1] = true;
		
		int zeroes = cnt[0] + cnt[2];
		if(zeroes - (n - 2) / 2 >= 2)
			ans[0][0] = true;
		
		int a = (n - 2 + 1) / 2;
		int b = (n - 2) / 2;
		int c[] = new int[2];
		c[0] = b + 1;
		c[1] = a + 1;
		
		if(cnt[0] <= c[0] && cnt[1] <= c[1]){
			
			{
				char t[] = Arrays.copyOf(s, n);
				int k = 0;
				for(int i = 0; i < n; i++){
					if(t[i] == '?'){
						if(k < c[0] - cnt[0]){
							k++;
							t[i] = '0';
						}
						else
							t[i] = '1';
					}
				}
				if(t[n - 1] == '1')
					ans[0][1] = true;
			}
			
			{
				char t[] = Arrays.copyOf(s, n);
				int k = 0;
				for(int i = 0; i < n; i++){
					if(t[i] == '?'){
						if(k < c[1] - cnt[1]){
							k++;
							t[i] = '1';
						}
						else
							t[i] = '0';
					}
				}
				if(t[n - 1] == '0')
					ans[1][0] = true;
			}
			
		}
		
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				if(ans[i][j])
					w.println(i + "" + j);
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
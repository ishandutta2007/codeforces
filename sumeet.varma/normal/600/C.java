import java.io.*;
import java.util.*;

public class Ed2qA {


	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		char s[] = in.readString().toCharArray();
		
		int cnt[] = new int[26];
		for(char x : s)
			cnt[x - 'a']++;
		
		int ans[] = new int[26];
		int single = -1;
		
		ArrayList<Integer> list = new ArrayList<Integer>();
		
		for(int i=0;i<26;i++){
			ans[i] = cnt[i] / 2;
			cnt[i] %= 2;
			if(cnt[i] == 1)
				list.add(i);
		}
		
		int size = list.size();
		
		for(int i=0;i<size/2;i++)
			ans[list.get(i)]++;
		
		if(size % 2 == 1)
			single = list.get(size/2);
		
		for(int i=0;i<26;i++)
			for(int j=0;j<ans[i];j++)
				w.print((char)(i + 'a'));
		
		if(single != -1)
			w.print((char)('a' + single));
		
		for(int i=25;i>=0;i--)
			for(int j=0;j<ans[i];j++)
				w.print((char)(i + 'a'));
		
		w.println();
		w.close();
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
		
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
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

	}
}
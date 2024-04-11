import java.io.*;
import java.util.*;

//java.is.awesome

public class R324qEAntonAndIra {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int p[] = in.nextIntArray(n);
		int q[] = in.nextIntArray(n);
		int map[] = new int[n + 1];
		for(int i = 0; i < n; i++)
			map[q[i]] = i;
		for(int i = 0; i < n; i++)
			p[i] = map[p[i]];
		
		int pos[] = new int[n];
		for(int i = 0; i < n; i++)
			pos[p[i]] = i;
			
		ArrayList<Integer> ans = new ArrayList<Integer>();
		int sum = 0;
		
		for(int i = 0; i < n; i++){
			int curr = pos[i];
			for(int j = pos[i] - 1; j >= i; j--){
				if(p[j] >= curr){
					{
						ans.add(j + 1);
						ans.add(curr + 1);
						sum += curr - j;
					}
					{
						int t = p[curr];
						p[curr] = p[j];
						p[j] = t;
					}{
						pos[i] = j;
						pos[p[j]] = curr;
						curr = j;
					}
					
				}
			}	
		}
		
		w.println(sum);
		w.println(ans.size() / 2);
		for(int i = 0; i < ans.size();)
			w.println(ans.get(i++) + " " + ans.get(i++));
		
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
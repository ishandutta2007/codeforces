import java.io.*;
import java.util.*;

public class R327qA {

	static int n;
	static int a[];
	static int ans = 0;
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
		
		a = new int[n];
		for(int i=0;i<n;i++)
			a[i] = in.nextInt();
		
		boolean inGroup[] = new boolean[n];
		inGroup[0] = inGroup[n-1] = true;
		
		for(int i=1;i<n;i++)
			if(a[i] == a[i-1])
				inGroup[i] = inGroup[i-1] = true;
		
		for(int i=0;i<n;){
			int j = i + 1;
			while(j < n && !inGroup[j])
				j++;
			ans = Math.max(ans, (j - i)/2);
			int mid = i + (j - i)/2;
			for(int k=i;k<=mid;k++)
				a[k] = a[i];
			for(int k=mid+1;k<j;k++)
				a[k] = a[j];
			i = j;
		}
		
		w.println(ans);
		for(int i=0;i<n;i++)
			w.print(a[i] + " ");
		w.println();
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
import java.io.*;
import java.util.*;

public class R312qB {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		int a[] = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		
		int m = 1000001;
		int min[] = new int[m];
		Arrays.fill(min, (int)1e7);
		int max[] = new int[m];
		Arrays.fill(max, -(int)1e7);
		int cnt[] = new int[m];
		
		for(int i=0;i<n;i++){
			cnt[a[i]]++;
			max[a[i]] = Math.max(max[a[i]],i);
			min[a[i]] = Math.min(min[a[i]],i);
		}
		
		int mc = 0;
		for(int i=0;i<m;i++)
			mc = Math.max(mc, cnt[i]);
		
		int ans = n;
		int l = 1,r = n;
		for(int i=0;i<m;i++)
			if(cnt[i] == mc){
				if(max[i] - min[i] + 1 < ans){
					ans = max[i] - min[i] + 1;
					l = min[i] + 1;
					r = max[i] + 1;
				}
			}
		
		w.println(l + " " + r);
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
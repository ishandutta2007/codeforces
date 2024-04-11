import java.io.*;
import java.util.*;

public class R345qB {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int a = in.nextInt();
		int b = in.nextInt();
		int t = in.nextInt();
		
		char s[] = ("$" + in.readString()).toCharArray();
		
		long pre[] = new long[n + 2];
		
		for(int i = 1; i <= n; i++){
			long now = 0;
			if(s[i] == 'w')
				now += b;
			now++;
			if(i > 1)
				now += a;
			pre[i] = pre[i - 1] + now;
		}
		
		long post[] = new long[n + 2];
		
		for(int i = n; i >= 1; i--){
			long now = 0;
			if(s[i] == 'w')
				now += b;
			now++;
			now += a;
			post[i] = post[i + 1] + now;
		}
		
		int ans = 0;
		
		for(int i = 1; i <= n; i++){
			if(pre[i] <= t){
				long time = pre[i] + (i - 1) * 1L * a;
				int start = i + 1, end = n + 1;
				int max = i;
				while(start < end){
					int mid = (start + end) >> 1;
					if(post[mid] + time <= t){
						max = i + n - mid + 1;
						end = mid;
					}
					else
						start = mid + 1;
				}
				ans = Math.max(ans, max);
			}
			else
				break;	
		}
		
		for(int i = n; i >= 2; i--){
			if(post[i] <= t){
				long time = post[i] + (n - i + 1) * 1L * a;
				int start = 1, end = i;
				int max = -1;
				while(start < end){
					int mid = (start + end) >> 1;
					if(pre[mid] + time <= t){
						max = mid + n - i + 1;
						start = mid + 1;
					}
					else
						end = mid;
				}
				ans = Math.max(ans, max);
			}
		}
		
		w.println(ans);
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
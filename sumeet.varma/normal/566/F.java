import java.io.*;
import java.util.*;

public class VKCupqA {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		int a[] = new int[n];
		for(int i=0;i<n;i++)
			a[i] = in.nextInt();
		
		int m = 1000000;
		
		int cnt[] = new int[m + 1];
		for(int i=0;i<n;i++)
			cnt[a[i]]++;
		
		int max[] = new int[m + 1];
		int ans = 0;
		
		for(int i=1;i<=m;i++){
			max[i] += cnt[i];
			for(int j=2*i;j<=m;j+=i)
				if(max[j] < max[i])
					max[j] = max[i];
			ans = Math.max(ans, max[i]);
		}
		
		/*
		int ans2 = 0;
		
		for(int i=0;i<(1<<n);i++){
			int state[] = new int[n];
			int count = 0;
			for(int j=0;j<n;j++){
				if(((1<<j) & i) != 0){
					state[j] = 1;
					count++;
				}
			}
			boolean yes = true;
			for(int j=0;j<n;j++)
				for(int k=j;k<n;k++)
					if(state[j] == 1 && state[k] == 1)
						yes &= a[k] % a[j] == 0 || a[j] % a[k] == 0;
			if(yes)
				ans2 = Math.max(ans2, count);
		}
		
		w.println(ans + " " + ans2);
		*/
		
		w.println(ans);
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
import java.io.*;
import java.util.*;

public class R276qDKindergarten {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		final int INC = 1,DEC = -1;
		int n = in.nextInt();
		
		if(n == 1){
			System.out.println(0);
			return;
		}
		
		int a[] = new int[n + 5];
		for(int i=1;i<=n;i++)
			a[i] = in.nextInt();
		
		long dp[] = new long[n + 5];
		int len[] = new int[n + 5];
		int state[] = new int[n + 5];
		
		dp[1] = 0;
		dp[2] = Math.abs(a[1] - a[2]);
		
		if(a[2] > a[1]){
			len[2] = 2;
			state[2] = INC;
		}
		else if(a[2] < a[1]){
			len[2] = 2;
			state[2] = DEC;
		}
		else
			len[2] = 1;
		
		for(int i=3;i<=n;i++){
			if(a[i] == a[i-1]){
				dp[i] = dp[i-1];
				len[i] = 1;
			}
			else if(a[i] > a[i-1]){
				if(len[i-1] == 1){
					dp[i] = dp[i-2] + a[i] - a[i-1];
					len[i] = 2;
					state[i] = INC;
				}
				else if(state[i-1] == INC){
					dp[i] = dp[i-1] + a[i] - a[i-1];
					len[i] = len[i-1] + 1;
					state[i] = INC;
				}
				else{
					dp[i] = Math.max(dp[i-1],dp[i-2] + a[i] - a[i-1]);
					len[i] = 2;
					state[i] = INC;
				}
			}
			else{
				if(len[i-1] == 1){
					dp[i] = dp[i-2] + a[i - 1] - a[i];
					len[i] = 2;
					state[i] = DEC;
				}
				else if(state[i-1] == DEC){
					dp[i] = dp[i-1] + a[i-1] - a[i];
					len[i] = len[i-1] + 1;
					state[i] = DEC;
				}
				else{
					dp[i] = Math.max(dp[i-1],dp[i-2] + a[i-1] - a[i]);
					len[i] = 2;
					state[i] = DEC;
				}
			}
		}
		
		//System.out.println(Arrays.toString(dp));
		//System.out.println(Arrays.toString(len));
		//System.out.println(Arrays.toString(state));
		w.println(dp[n]);
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
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
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
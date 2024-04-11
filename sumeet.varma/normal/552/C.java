import java.io.*;
import java.util.*;

public class R308qC {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter p = new PrintWriter(System.out);

		int w = in.nextInt();
		int m = in.nextInt();
		
		if(w == 2){
			System.out.println("YES");
			return;
		}
		
		long up = (long)1e11;
		
		long pow[] = new long[21];
		pow[0] = 1;
		int n = 21;
		
		for(int i=1;i<21;i++){
			pow[i] = w * pow[i-1];
			if(pow[i] >= up){
				n = i + 1;
				break;
			}
		}
		
		int state[] = new int[n];
		
		for(int i=0;i<(1<<n);i++){
			long left = m,right = 0;
			for(int j=0;j<n;j++)
				if(((1<<j) & i) != 0){
					state[j] = 1;
					left += pow[j];
				}
				else{
					state[j] = 0;
					right += pow[j];
				}
			long left2 = left,right2 = right;
			if(left > right){
				long diff = left - right;
				for(int j=n-1;j>=0;j--){
					if(state[j] == 1 && pow[j] <= diff){
						diff -= pow[j];
						left -= pow[j];
					}
				}
			}
			if(right > left){
				long diff = right - left;
				for(int j=n-1;j>=0;j--){
					if(state[j] == 0 && pow[j] <= diff){
						diff -= pow[j];
						right -= pow[j];
					}
				}
			}
			if(left == right){
				System.out.println("YES");
				return;
			}
			if(right2 > left2){
				long diff = right2 - left2;
				for(int j=n-1;j>=0;j--){
					if(state[j] == 0 && pow[j] <= diff){
						diff -= pow[j];
						right2 -= pow[j];
					}
				}
			}
			if(left2 > right2){
				long diff = left2 - right2;
				for(int j=n-1;j>=0;j--){
					if(state[j] == 1 && pow[j] <= diff){
						diff -= pow[j];
						left2 -= pow[j];
					}
				}
			}
			if(left2 == right2){
				System.out.println("YES");
				return;
			}
		}
		
		p.println("NO");
		p.close();
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
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class R243qESerejaAndSets {
	
	static final int mod = (int)1e9 + 7;
	static long pow2[];
	static int N,K;
	static int dp[][][];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		pow2 = new long[551];
		pow2[0] = 1;
		for(int i=1;i<=550;i++)
			pow2[i] = (pow2[i-1] * 2) % mod;
		
		N = in.nextInt();
		K = in.nextInt();
		
		dp = new int[2][K + 1][N + 1];
		for(int i=0;i<=N;i++)
			dp[1][K][i] = 1;
		
		for(int curr=N;curr>=1;curr--){
			int t = Math.min(K, curr-1);
			for(int count=0;count<=t;count++){
				for(int last=0;last<=curr;last++){
					long ans = 0;
					if(count != K)
						ans = (dp[1][count+1][curr] * (pow2[curr] - pow2[last] + mod));
					ans = (ans + dp[1][count][last] * pow2[last]) % mod;
					dp[0][count][last] = (int)ans;
				}
			}
			for(int count=0;count<=t;count++)
				for(int last=0;last<=curr;last++)
					dp[1][count][last] = dp[0][count][last];
		}
		
		w.println(dp[1][0][0]);
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
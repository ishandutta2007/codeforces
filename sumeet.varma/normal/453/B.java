import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class R259qBLittleHarmonyAndChest {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		long start = System.currentTimeMillis();
		int primeSet[] = new int[61];
		int primeCount = 0;
		
		for(int i=2;i<=58;i++){
			if(primeSet[i] == 0){
				for(int j=i;j<=58;j+=i)
					primeSet[j] = set(primeCount,primeSet[j]);
				primeCount++;
			}
		}
		
		int n = in.nextInt();
		
		int a[] = new int[n];
		for(int i=0;i<n;i++)
			a[i] = in.nextInt();
		
		int dp[][] = new int[n + 1][1<<primeCount];
		int val[][] = new int[n + 1][1<<primeCount];
		
		final int oo = Integer.MAX_VALUE >> 1;
		
		for(int i=n-1;i>=0;i--){
			for(int mask=0;mask<(1<<primeCount);mask++){
				dp[i][mask] = oo;
				for(int j=1;j<=58;j++){
					if((mask & primeSet[j]) == 0){
						int wow = Math.abs(a[i] - j) + dp[i+1][mask|primeSet[j]];
						if(wow < dp[i][mask]){
							dp[i][mask] = wow;
							val[i][mask] = j;
						}
					}
				}
			}
		}
		
		int mask = 0;
		for(int i=0;i<n;i++){
			w.print(val[i][mask] + " ");
			mask = mask | primeSet[val[i][mask]];
		}
		
		w.println();
		w.close();
		
		System.out.println(System.currentTimeMillis() - start);
	}
	
	static boolean get(int bit,int mask){
		return (mask & (1<<bit)) != 0;
	}
	
	static int set(int bit,int mask){
		return mask | (1 << bit);
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
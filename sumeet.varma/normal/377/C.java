import java.io.*;
import java.util.*;

public class R222qCCaptainsMode {

	static int n,m;
	static int a[];
	static int dp[];
	static char action[];
	static int person[];
	static int inf = Integer.MAX_VALUE >> 1;
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
		
		a = new int[n];
		for(int i=0;i<n;i++)
			a[i] = -1 * in.nextInt();
		Arrays.sort(a);
		for(int i=0;i<n;i++)
			a[i] *= -1;
		
		m = in.nextInt();
		
		action = new char[m];
		person = new int[m];
		
		for(int i=0;i<m;i++){
			action[i] = in.readString().charAt(0);
			person[i] = in.nextInt();
		}
		
		dp = new int[1<<m];
		
		for(int mask=(1<<m)-1;mask>=0;mask--){
			
			int idx = setBits(mask);
			if(idx == m){
				dp[mask] = 0;
				continue;
			}
			
			int first = -1;
			for(int j=0;j<m;j++){
				if((mask & (1<<j)) == 0){
					first = j;
					break;
				}
			}
			
			if(person[idx] == 1){
				if(action[idx] == 'p')
					dp[mask] = a[first] + dp[mask|(1<<first)];
				else{
					dp[mask] = -inf;
					for(int j=0;j<m;j++)
						dp[mask] = Math.max(dp[mask], dp[mask|(1<<j)]);
				}
			}
			else{
				if(action[idx] == 'p')
					dp[mask] = -a[first] + dp[mask|(1<<first)];
				else{
					dp[mask] = inf;
					for(int j=0;j<m;j++)
						dp[mask] = Math.min(dp[mask], dp[mask|(1<<j)]);
				}
			}
			
		}
		
		w.println(dp[0]);
		w.close();
	}
	
	static int setBits(int mask){
		int ans = 0;
		for(int i=0;i<m;i++)
			if((mask & (1<<i)) != 0)
				ans++;
		return ans;
	}
	
	static boolean get(int bit,int mask){
		return (mask & (1 << bit)) != 0;
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
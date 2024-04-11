import java.io.*;
import java.util.*;

public class R288qEArthurAndBrackets {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		
		int l[] = new int[n];
		int r[] = new int[n];
		
		for(int i = 0; i < n; i++){
			l[i] = in.nextInt();
			r[i] = in.nextInt();
			if(l[i] % 2 == 0)
				l[i]++;
			if(r[i] % 2 == 0)
				r[i]--;
		}
		
		boolean dp[][] = new boolean[n][n];
		int first[][] = new int[n][n];
		
		for(int i = 0; i < n; i++){
			dp[i][i] = l[i] <= 1 && 1 <= r[i];
			first[i][i] = dp[i][i] ? 1 : -1;
		}
		
		
		for(int x = 1; x < n; x++){
			for(int i = 0, j = i + x; j < n; i++,j++){
				dp[i][j] = false;
				for(int k = l[i]; k <= r[i] && k <= 2*x + 1; k += 2){
					boolean now = true;
					if(k != 1)
						now &= dp[i + 1][i + k/2];
					if(i + k/2 + 1 <= j)
						now &= dp[i + k/2 + 1][j];
					if(now){
						dp[i][j] = true;
						first[i][j] = k;
						break;
					}
				}
			}
		}
		
		if(!dp[0][n-1])
			w.println("IMPOSSIBLE");
		else{
			char ans[] = new char[2*n];
			dfs(0 , n - 1 , first , ans , 0);
			w.println(new String(ans));
		}
		
		w.close();
	}
	
	public static void dfs(int l, int r, int first[][], char ans[] , int off){
		if(l > r)
			return;
		//System.out.println(l + );
		ans[off] = '(';
		ans[off + first[l][r]] = ')';
		int k = first[l][r];
		if(k != 1)
			dfs(l + 1 ,l + k/2 , first , ans , off + 1);
		if(l + k/2 + 1 <= r)
			dfs(l + k/2 + 1 , r , first, ans , off + 1 + k);
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
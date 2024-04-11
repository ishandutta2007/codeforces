import java.io.*;
import java.util.*;


public class CrocChamp12qDTshirts {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		int a[][] = new int[n + 1][];
		for(int i = 1; i <= n; i++)	a[i] = in.nextIntArray(m);

		double dp[][] = new double[m][n + 1];
		TreeSet<Pair> set = new TreeSet<Pair>();
		
		for(int i = 0; i < m; i++){
			dp[i][0] = 1;
			for(int j = 1; j <= n; j++)
				dp[i][j] = dp[i][j - 1] * (1000 - a[j][i]) / 1000.0;
			set.add(new Pair(i , 1 - dp[i][n]));
		}
		
		//System.out.println(set);
		double ans = 0;
		
		for(int k = 0; k < n; k++){
			Pair first = set.last();
			set.remove(first);
			//System.out.println(first);
			ans += first.y;			
			int i = first.x;

			double dp2[] = new double[n + 1];
			for(int j = 1; j <= n; j++)
				dp2[j] = dp2[j - 1] * (1000 - a[j][i]) / 1000.0 + dp[i][j - 1] * a[j][i] / 1000.0;
			for(int j = 0; j <= n; j++)
				dp[i][j] = dp2[j];
			//System.out.println(Arrays.toString(dp2));
			
			set.add(new Pair(i , 1 - (1 - first.y) - dp2[n]));
		}
		
		w.println(ans);
		w.close();
	}
	
	static class Pair implements Comparable<Pair>{
		int x;
		double y;
		Pair(int x, double y){
			this.x = x;
			this.y = y;
		}
		public int compareTo(Pair o){
			if(o.y != y)
				return Double.compare(y, o.y);
			return Integer.compare(x, o.x);
		}
		public String toString(){
			return x + " " + y;
		}
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
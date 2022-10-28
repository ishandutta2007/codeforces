import java.io.*;
import java.util.*;

public class R341qC {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int p = in.nextInt();
		
		int l[] = new int[n];
		int r[] = new int[n];
		
		for (int i = 0; i < n; i++){
			l[i] = in.nextInt();
			r[i] = in.nextInt();
		}
		
		double ans = 0;
		
		for(int i = 1; i < n; i++){
			double p1 = count(l[i - 1], r[i - 1], p);
			double p2 = count(l[i], r[i], p);
			ans += 1000 - (1000 - p1) * (1000 - p2) / 1000;
		}
		
		double last = count(l[n - 1], r[n - 1], p);
		double first = count(l[0], r[0], p);
		ans += 1000 - (1000 - first) * (1000 - last) / 1000;
		
		ans *= 2;
		
		w.println(ans);
		
		/*
		double dp[][] = new double[n][2];
		double pr[][] = new double[n][2];
		
		
		
		dp[n - 1][1] = 0;	dp[n - 1][0] = 0;
		pr[n - 1][1] = 1;	pr[n - 1][0] = 0;
		
		for(int i = n - 2; i >= 1; i--){
			double pro = count(l[i], r[i], p);
			dp[i][1] = 1000 + (pr[i + 1][1] * dp[i + 1][1] + pr[i + 1][0] * dp[i + 1][0]);
			pr[i][1] = pro;
			dp[i][0] = (1000 + dp[i + 1][1]) * pr[i + 1][1] + dp[i + 1][0] * pr[i + 1][0];
		}
		
		double ans1 = first * ( (1000 + dp[1][0]) * pr[1][0] + (1000 + dp[1][1]) * pr[1][1] + 1000) 
				+ (1 - first) * ( 1000 + (1000 + dp[1][1]) * pr[1][1] + dp[1][0] * pr[1][0]);

		dp[n - 1][1] = 0;	dp[n - 1][0] = 0;
		pr[n - 1][1] = 0;	pr[n - 1][0] = 1;
		
		for(int i = n - 2; i >= 1; i--){
			double pro = count(l[i], r[i], p);
			dp[i][1] = 1000 + (pr[i + 1][1] * dp[i + 1][1] + pr[i + 1][0] * dp[i + 1][0]);
			pr[i][1] = pro;
			dp[i][0] = (1000 + dp[i + 1][1]) * pr[i + 1][1] + dp[i + 1][0] * pr[i + 1][0];
		}
		
		double ans2 = first * ( (1000 + dp[1][0]) * pr[1][0] + (1000 + dp[1][1]) * pr[1][1] + 1000) 
				+ (1 - first) * ((1000 + dp[1][1]) * pr[1][1] + dp[1][0] * pr[1][0]);
		
		double ans = last * ans1 + (1 - last) * ans2;
		w.println(ans);*/
		w.close();
	}
	
	static double count(int l, int r,int p){
		int first = l % p == 0 ? (l / p) : (l / p + 1); 
		int last = r / p;
		if(first <= last)
			return 1000 * (last - first + 1.0) / (r - l + 1);
		return 0;
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
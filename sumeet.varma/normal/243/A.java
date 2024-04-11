import java.io.*;
import java.util.*;

public class R150qA {
	
	static int a[],logs[];
	static int z[][];
	static int n;
	static boolean hash[];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();

		a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();

		
		buildLogs();
		buildSparseTableOr();
		
		hash = new boolean[1<<22];
		
		for(int i=0;i<n;++i){
			int or = -1,curr = i;
			while(true){
				int ret = -1;
				int start = curr,end = n,mid;
				while(start < end){
					mid = (start + end) >> 1;
					if(queryOr(i,mid) > or)
						ret = end = mid;
					else
						start = mid + 1;
				}
				if(ret != -1){
					or = queryOr(i,ret);
					hash[or] = true;
					curr = ret + 1;
				}
				else
					break;
			}
			//System.out.println(i + " " + count);
		}
		
		int ans = 0;
		for(int i=0;i<hash.length;i++)
			if(hash[i])
				ans++;
		
		w.println(ans);
		w.close();
	}
	
	public static void buildLogs() {
		logs = new int[n + 1];
		int g = 2;
		while (g <= n) {
			logs[g] = 1;
			g = (g << 1);
		}
		for (int i = 1; i <= n; i++)
			logs[i] += logs[i - 1];
	}

	public static void buildSparseTableOr() {
		int p, g;
		z = new int[21][n];
		for (int i = 0; i < n; i++)
			z[0][i] = a[i];
		for (int j = 1; (1 << j) < n; j++)
			for (int i = 0; i + (1 << j) <= n; i++) {
				g = z[j - 1][i];
				p = z[j - 1][i + (1 << (j - 1))];
				z[j][i] = g | p;
			}
	}

	public static int queryOr(int l, int r) {
		int k = logs[r - l + 1];
		return z[k][l] | z[k][r - (1 << k) + 1] ;
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
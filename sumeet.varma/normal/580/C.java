import java.io.*;
import java.util.*;

public class R321qC {

	static int n,m;
	static int cat[];
	static ArrayList<Integer> g[];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
		m = in.nextInt();
		
		cat = new int[n];
		for(int i=0;i<n;i++)
			cat[i] = in.nextInt();
		
		g = new ArrayList[n];
		for(int i=0;i<n;i++)
			g[i] = new ArrayList<Integer>();
		
		for(int i=1;i<n;i++){
			int u = in.nextInt() - 1;
			int v = in.nextInt() - 1;
			g[u].add(v);
			g[v].add(u);
		}
		
		w.println(dfs(0,0,0,-1));
		
		w.close();
	}
	
	static public int dfs(int curr,int currCount,int maxCount,int prev){
		int ans = 0;
		if(cat[curr] == 1)
			currCount++;
		else
			currCount = 0;
		maxCount = Math.max(maxCount, currCount);
		int trees = 0;
		for(int x : g[curr]){
			if(x != prev){
				trees++;
				ans += dfs(x,currCount,maxCount,curr);
			}
		}
		if(trees == 0 && maxCount <= m)
			ans++;
		return ans;
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
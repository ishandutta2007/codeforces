import java.io.*;
import java.util.*;

public class R177qDPoloAndTrees {

	static int n;
	static ArrayList<Integer> g[];
	static long ans;
	static long subtree[];
	
	@SuppressWarnings("unchecked")
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
	
		g = new ArrayList[n + 1];
		for(int i=1;i<=n;i++)
			g[i] = new ArrayList<Integer>();
		
		for(int i=1;i<n;i++){
			int u = in.nextInt();
			int v = in.nextInt();
			g[u].add(v);
			g[v].add(u);
		}
		
		subtree = new long[n + 1];
		ans = 0;
		
		dfs(1,0);
		w.println(ans);
		
		w.close();
	}
	
	public static void dfs(int curr,int prev){
		subtree[curr] = 1;
		long paths = 0;
		for(int x : g[curr]){
			if(x != prev){
				dfs(x,curr);
				paths += subtree[curr] * subtree[x];
				subtree[curr] += subtree[x];
			}
		}
		paths += (n - subtree[curr]) * subtree[curr];
		for(int x : g[curr]){
			if(x != prev){
				long nowPaths = paths;
				nowPaths -= subtree[x] * (n - subtree[x]);
				ans += nowPaths * subtree[x] * (subtree[x] - 1) / 2;
			}
		}
		paths -= (n - subtree[curr]) * subtree[curr];
		ans += paths * (n - subtree[curr]) * (n - subtree[curr] - 1) / 2;
		//System.out.println(curr + " " + ans);
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
			
			int res = 0;

			do {
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res;
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
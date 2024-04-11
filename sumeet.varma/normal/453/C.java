import java.io.*;
import java.util.*;

public class R259qCLittlePonyAndSunCelebration {

	static int n,m;
	static ArrayList<Integer> g[];
	static boolean vis[];
	static int cnt[],target[];
	static ArrayList<Integer> path;
	
	@SuppressWarnings("unchecked")
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
		m = in.nextInt();
		
		g = new ArrayList[n + 1];
		for(int i=1;i<=n;i++)
			g[i] = new ArrayList<Integer>();
		
		while(m-- > 0){
			int u = in.nextInt();
			int v = in.nextInt();
			g[u].add(v);
			g[v].add(u);
		}
		
		int root = 1;
		
		target = new int[n + 1];
		cnt = new int[n + 1];
		
		for(int i=1;i<=n;i++){
			target[i] = in.nextInt();
			if(target[i] == 1 && target[root] == 0)
				root = i;
		}
		
		vis = new boolean[n + 1];
		path = new ArrayList<Integer>();
		dfs(root,-1);
		
		if(cnt[root] != target[root]){
			cnt[root] = 1 - cnt[root];
			path.remove(path.size() - 1);
		}
		
		boolean yes = true;
		for(int i=1;i<=n;i++)
			yes &= cnt[i] == target[i];
		
		if(yes){
			w.println(path.size());
			for(int x : path)
				w.print(x + " ");
			w.println();
		}
		else
			w.println(-1);
			
		w.close();
	}
	
	static void dfs(int curr,int parent){
		vis[curr] = true;
		path.add(curr);
		cnt[curr] = 1 - cnt[curr];
		
		for(int next : g[curr]){
			if(vis[next])	continue;
			dfs(next,curr);
			path.add(curr);
			cnt[curr] = 1 - cnt[curr];
		}
		
		if(parent != -1 && cnt[curr] != target[curr]){
			path.add(parent);
			path.add(curr);
			cnt[parent] = 1 - cnt[parent];
			cnt[curr] = 1 - cnt[curr];
		}
		
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
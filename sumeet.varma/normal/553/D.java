import java.io.*;
import java.util.*;

//java.is.awesome

public class R309qDNudistBeach {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		
		int L[] = new int[k];
		for(int i = 0; i < k; i++)
			L[i] = in.nextInt() - 1;
		
		@SuppressWarnings("unchecked")
		ArrayList<Integer> g[] = new ArrayList[n];
		for(int i = 0; i < n; i++)
			g[i] = new ArrayList<Integer>();
		
		while(m-- > 0){
			int u = in.nextInt() - 1;
			int v = in.nextInt() - 1;
			g[u].add(v);
			g[v].add(u);
		}
		
		int f[] = new int[n];
		for(int i = 0; i < k; i++)
			f[L[i]] = 1;
		
		TreeSet<Pair> set = new TreeSet<Pair>();
		int curr[] = new int[n];
		
		for(int i = 0;i < n; i++){
			if(f[i] == 0){
				int c = 0;
				for(int x : g[i])
					if(f[x] == 0)
						c++;
				curr[i] = c;
				set.add(new Pair(i , c , g[i].size()));
			}
		}
		
		double ans = 0;
		int time = 1;
		int bestTime = 0;
		int bestAns = 0;
		
		while(set.size() > 0){
			Pair F = set.first();
			double now = F.x * 1.0 / F.y;
			f[F.idx] = ++time;
			if(now >= ans){
				ans = now;
				bestTime = time;
				bestAns = set.size();
			}
			set.remove(F);
			for(int v : g[F.idx]){
				if(f[v] == 0){
					set.remove(new Pair(v , curr[v] , g[v].size()));
					curr[v]--;
					set.add(new Pair(v , curr[v] , g[v].size()));
				}
			}
		}
		
		
		w.println(bestAns);
		for(int i = 0 ;i < n; i++)
			if(f[i] >= bestTime)
				w.print((i+1) + " ");
		
		w.println();
		w.close();
	}
	
	static class Pair implements Comparable<Pair>{
		int idx,x,y;
		Pair(int idx, int x, int y){
			this.idx = idx;
			this.x = x;
			this.y = y;
		}
		public int compareTo(Pair o){
			int z = Long.compare(x * 1L * o.y, o.x * 1L * y);
			return z == 0 ? Integer.compare(idx, o.idx) : z;
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
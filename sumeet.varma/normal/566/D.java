import java.io.*;
import java.util.*;

public class VKCupqD {

	static int nxt[];
	static DisjointSet ds;
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int q = in.nextInt();
		
		ds = new DisjointSet(n);
		
		nxt = new int[n];
		for(int i=0;i<n;i++)
			nxt[i] = i + 1;
		
		while(q-- > 0){
			int type = in.nextInt();
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
		
			if(type == 3)
				w.println(ds.find(x) == ds.find(y) ? "YES" : "NO");
			else if(type == 2)
				go(x,y);
			else
				ds.merge(x, y);
		}

		w.close();
	}
	
	static public int go(int x,int y){
		if(nxt[x] <= y){
			ds.merge(x,nxt[x]);
			nxt[x] = go(nxt[x],y);
			return nxt[x];
		}
		else
			return x;
	}
	
	static class DisjointSet {

			public int rank[],parent[];
			public int n;
			
			public DisjointSet(int n){
			    this.n = n;
				makeSet();
			}
			
			public void makeSet(){
				rank = new int[n];
				parent = new int[n];
				for(int i=0;i<n;i++)
					parent[i] = i;
			}
			
			public int find(int x){
				if(parent[x] != x)
					parent[x] = find(parent[x]);
				return parent[x];
			}
			
			public void merge(int x,int y){
				int xRoot = find(x);
				int yRoot = find(y);
				
				if(xRoot == yRoot)
					return;
				
				if(rank[xRoot] < rank[yRoot])
					parent[xRoot] = yRoot;
				else{
					parent[yRoot] = xRoot;
					if(rank[xRoot] == rank[yRoot]){
						parent[yRoot] = xRoot;
						rank[xRoot]++;
					}
				}
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
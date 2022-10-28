import java.io.*;
import java.util.*;

public class R309qC {

	static int color[];
	static ArrayList<Integer> g[];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		int a[] = new int[m];
		int b[] = new int[m];
		int c[] = new int[m];
		
		DisjointSet ds1 = new DisjointSet(n);
		DisjointSet ds2 = new DisjointSet(n);
		
		for(int i=0;i<m;i++){
			a[i] = in.nextInt() - 1;
			b[i] = in.nextInt() - 1;
			c[i] = in.nextInt();
			ds2.merge(a[i], b[i]);
			if(c[i] == 1)
				ds1.merge(a[i], b[i]);
		}
		
		g = new ArrayList[n];
		for(int i=0;i<n;i++)
			g[i] = new ArrayList<Integer>();
		
		for(int i=0;i<m;i++)
			if(c[i] == 0){
				g[ds1.find(a[i])].add(ds1.find(b[i]));
				g[ds1.find(b[i])].add(ds1.find(a[i]));
			}
				
		color = new int[n];
	
		for(int i=0;i<n;i++)
			if(color[i] == 0 && ds1.find(i) == i){
				color[i] = 1;
				if(!dfs(i)){
					System.out.println(0);
					return;
				}
			}
		
		w.println(pow(2,ds2.comp - 1,(int)1e9 + 7));
		w.close();
	}
	
	static public boolean dfs(int curr){
		for(int x : g[curr]){
			if(color[x] == 0){
				color[x] = -1 * color[curr];
				if(!dfs(x))
					return false;
			}
			if(color[x] == color[curr])
				return false;
		}
		return true;
	}
	
	static long pow(int a,int b,int mod){
		if(b == 0)
			return 1;
		long t = pow(a, b/2, mod);
		t = (t * t) % mod;
		if( b % 2 == 1)
			t = (t * a) % mod;
		return t;
	}
	
	static public class DisjointSet {

		public int rank[],parent[],size[];
		public int n,comp;
		
		public DisjointSet(int n){
		    this.n = n;
			makeSet();
		}
		
		public void makeSet(){
			rank = new int[n];
			parent = new int[n];
			for(int i=0;i<n;i++)
				parent[i] = i;
			size = new int[n];
			Arrays.fill(size, 1);
			comp = n;
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
			
			size[xRoot] = size[yRoot] = size[xRoot] + size[yRoot];
			
			if(rank[xRoot] < rank[yRoot])
				parent[xRoot] = yRoot;
			else{
				parent[yRoot] = xRoot;
				if(rank[xRoot] == rank[yRoot]){
					parent[yRoot] = xRoot;
					rank[xRoot]++;
				}
			}
			comp--;
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
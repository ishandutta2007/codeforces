import java.io.*;
import java.util.*;

public class R331qC {

	static Pair p[];
	static ArrayList<Pair> list[];
	static ArrayList<Integer> der[];
	static int assigned[];
	static Pair rev[];
	static int segtree[];
	
	@SuppressWarnings("unchecked")
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		list = new ArrayList[2 * 100001];
		for(int i=0;i<=200000;i++)
			list[i] = new ArrayList<Pair>();
		
		int n = in.nextInt();
		
		p = new Pair[n];
		
		for(int i=0;i<n;i++){
			p[i] = new Pair(i,in.nextInt(),in.nextInt());
			list[p[i].y - p[i].x + 100000].add(new Pair(i,p[i].x,p[i].y));
		}
		
		Arrays.sort(p);
		
		der = new ArrayList[2 * 100001];
		for(int i=0;i<=200000;i++)
			der[i] = new ArrayList<Integer>();
		
		for(int i=1;i<=n;i++)
			der[in.nextInt() + 100000].add(i);
		
		assigned = new int[n];
		rev = new Pair[n + 1];
		
		for(int i=0;i<=200000;i++){
			
			if(list[i].size() != der[i].size()){
				System.out.println("NO");
				return;
			}
			
			if(list[i].isEmpty())
				continue;
			
			Collections.sort(list[i]);
			
			int s = list[i].size();
			for(int j=0;j<s;j++){
				assigned[list[i].get(j).idx] = der[i].get(j);
				rev[der[i].get(j)] = new Pair(list[i].get(j).idx,list[i].get(j).x,list[i].get(j).y);
			}
		}
		
		segtree = new int[4 * (100010)];
		Arrays.fill(segtree, (int)1e8);
		
		for(int i=n-1;i>=0;i--){
			update(0,100000,0,p[i].y,assigned[p[i].idx]);
			int min = find(0,100000,0,p[i].y,100000);
			if(min < assigned[p[i].idx]){
				System.out.println("NO");
				return;
			}
		}
		
		w.println("YES");
		for(int i=1;i<=n;i++)
			w.println(rev[i].x + " " + rev[i].y);
		
		w.close();
	}
	
	public static void update(int s,int e,int c,int x,int v){
		if(s == e)	{
			segtree[c] = Math.min(segtree[c],v);
			return;
		}
		int m = (s + e) >> 1;
		if(x <= m)  update(s,m,2*c+1,x,v);
		else		update(m+1,e,2*c+2,x,v);
		segtree[c] = merge(segtree[2*c+1],segtree[2*c+2]);
	}
	
	public static int find(int s,int e,int c,int l,int r){
		if(s == l && e == r) return segtree[c];
		int m = (s + e) >> 1;
		if(l <= m && r <= m) return find(s,m,2*c+1,l,r);
		if(l >  m && r  > m) return find(m+1,e,2*c+2,l,r);
		return merge(find(s,m,2*c+1,l,m) , find(m+1,e,2*c+2,m+1,r));
	}
	
	static int merge(int a,int b){
		return Math.min(a, b);
	}
	
	static class Pair implements Comparable<Pair>{
		int idx,x,y;
		Pair(int idx,int x,int y){
			this.x = x;
			this.y = y;
			this.idx = idx;
		}
		public int compareTo(Pair o){
			if(x != o.x)
				return Integer.compare(x, o.x);
			return Integer.compare(y, o.y);
		}
		public String toString(){
			return idx + " " + x + " " + y;
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
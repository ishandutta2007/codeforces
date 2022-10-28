import java.io.*;
import java.util.*;

public class ER10qD {
	
	static int n;
	static Pair p[];
	static int st[][];

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		
		p = new Pair[n];
		for(int i = 0; i < n; i++)
			p[i] = new Pair(i, in.nextInt() , in.nextInt());
		
		
		/*TreeSet<Integer> set = new TreeSet<Integer>();
		for(Pair x : p){
			set.add(x.x);
			set.add(x.y);
		}
		
		TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
		int cnt = 0;
		for(int x : set)
			map.put(x, cnt++);
		
		for(int i = 0; i < n; i++){
			p[i].x = map.get(p[i].x);
			p[i].y = map.get(p[i].y);
		}*/
		
		Arrays.sort(p);
		st = new int[4*n][];
		
		build(0 ,n - 1 , 0);
		int ans[] = new int[n];
		
		for(int i = 0; i < n; i++){
			int start = i + 1 , end = n;
			int as = i;
			while(start < end){
				int mid = (start + end) >> 1;
				if(p[mid].x < p[i].y){
					as = mid;
					start = mid + 1;
				}
				else
					end = mid;
			}
			if(as != i)
				ans[p[i].idx] = find( 0 , n - 1 , 0 , i + 1 , as , p[i].y);
		}
		
		for(int x : ans)
			w.println(x);
		
		w.close();
	}
	
	static void build(int s, int e, int c){
		st[c] = new int[e - s + 1];
		for(int i = s; i <= e; i++)
			st[c][i - s] = p[i].y;
		Arrays.sort(st[c]);
		if(s != e){
			int m = (s + e) >> 1;
			build(s , m , 2*c + 1);
			build(m + 1 , e , 2*c + 2);
		}
	}
	
	static int find(int s, int e, int c, int l, int r, int k){
		if(s == l && e == r){
			int start = 0, end = st[c].length;
			int ans = 0;
			while(start < end){
				int mid = (start + end) >> 1;
				if(st[c][mid] <= k){
					ans = mid + 1;
					start = mid + 1;
				}
				else
					end = mid;
			}
			return ans;
		}
		else{
			int m = (s + e) >> 1;
			if(r <= m)
				return find(s , m , 2*c + 1 , l , r , k);
			if(l > m)
				return find(m + 1 , e , 2*c + 2 , l ,r , k);
			return find(s , m , 2*c + 1 , l , m , k) + find(m + 1 , e , 2*c+  2 , m + 1 ,r ,  k);
		}
	}
	
	static class Pair implements Comparable<Pair>{
		int idx,x,y;
		Pair(int idx, int x,int y){	this.idx = idx; this.x = x; this.y = y; }
		public int compareTo(Pair o){
			if(x != o.x)
				return Integer.compare(x, o.x);
			return Integer.compare(y, o.y);
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
import java.io.*;
import java.util.*;

public class R343qD {
	
	static long segtree[];

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		Pair p[] = new Pair[n];
		for(int i = 0; i < n; i++){
			int r = in.nextInt();
			int h = in.nextInt();
			p[i] = new Pair(i , r * 1L * r * 1L * h);
		}

		Arrays.sort(p);
		
		long dp[] = new long[n];
		segtree = new long[4*n];
		long ans = 0;
		
		for(int i = 0; i < n; i++){
			dp[p[i].idx] = p[i].val;
			dp[p[i].idx] += find(0, n - 1 , 0 , 0 , p[i].idx);
			update(0,  n - 1, 0 , p[i].idx , dp[p[i].idx]);
			ans = Math.max(ans, dp[p[i].idx]);
		}
		
		w.println(Math.PI * ans);
		w.close();
	}
	
	public static void update(int s,int e,int c,int x,long v){
		if(s == e)	{
			segtree[c] = v;
			return;
		}
		int m = (s + e) >> 1;
		if(x <= m)  update(s,m,2*c+1,x,v);
		else		update(m+1,e,2*c+2,x,v);
		segtree[c] = merge(segtree[2*c+1],segtree[2*c+2]);
	}
	
	public static long find(int s,int e,int c,int l,int r){
		if(s == l && e == r) return segtree[c];
		int m = (s + e) >> 1;
		if(l <= m && r <= m) return find(s,m,2*c+1,l,r);
		if(l >  m && r  > m) return find(m+1,e,2*c+2,l,r);
		return merge(find(s,m,2*c+1,l,m) , find(m+1,e,2*c+2,m+1,r));
	}
	
	public static long merge(long a,long b){
		return Math.max(a, b);
	}
	
	static class Pair implements Comparable<Pair>{
		int idx;
		long val;
		Pair(int i,long v){
			idx = i;
			val = v;
		}
		public int compareTo(Pair o){
			if(val != o.val)
				return Long.compare(val, o.val);
			return Integer.compare(o.idx, idx);
		}
		public String toString(){
			return idx + " " + val;
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
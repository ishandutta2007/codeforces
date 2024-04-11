import java.io.*;
import java.util.*;

public class R107qCSmartCheater{
	
	static int n,m,c;
	static int x[];
	static long p[];
	static SegNode segtree[];
	
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		m = in.nextInt();
		c = in.nextInt();
		
		x = new int[n];
		for(int i = 0; i < n; i++)
			x[i] = in.nextInt();
		
		p = new long[n];
		for(int i = 1; i < n; i++)
			p[i] = in.nextInt();

		for(int i = 1; i < n; i++)
			p[i] = 50L*(x[i] - x[i - 1])  - p[i] * 1L * c;
		
		segtree = new SegNode[4*n];
		build(1 , n - 1 , 0);
		
		double ans = 0;
		
		while(m-- > 0){
			int l = in.nextInt();
			int r = in.nextInt();
			r--;
			ans += find(1 , n - 1 , 0 , l , r).ans;
		}
		
		w.println(ans / 100.0);
		w.close();
	}
	
	public static void build(int s,int e,int c){
		if(s == e){
			segtree[c] = new SegNode(p[s]);
			return;
		}
		int m = (s + e) >> 1;
		build(s,m,2*c+1);
		build(m+1,e,2*c+2);
		segtree[c] = merge(segtree[2*c+1],segtree[2*c+2]);
	}
	
	public static SegNode find(int s,int e,int c,int l,int r){
		if(s == l && e == r) return segtree[c];
		int m = (s + e) >> 1;
		if(r <= m) return find(s,m,2*c+1,l,r);
		if(l >  m) return find(m+1,e,2*c+2,l,r);
		return merge(find(s,m,2*c+1,l,m) , find(m+1,e,2*c+2,m+1,r));
	}
	
	static SegNode merge(SegNode a, SegNode b){
		SegNode ans = new SegNode(0);
		ans.tot = a.tot + b.tot;
		ans.maxStart = Math.max(a.maxStart, a.tot + b.maxStart);
		ans.maxEnd = Math.max(b.maxEnd, b.tot + a.maxEnd);
		ans.ans = Math.max(a.ans, b.ans);
		ans.ans = Math.max(ans.ans, a.maxEnd + b.maxStart);
		return ans;
	}
	
	static class SegNode{
		long tot;
		long maxStart, maxEnd;
		long ans;
		SegNode(long x){
			tot = x;
			maxStart = maxEnd = ans = Math.max(x, 0);
		}
		public String toString(){
			return tot +  " "  + maxStart + " " + maxEnd + " " + ans;
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
import java.io.*;
import java.util.*;

public class _8VCFinalsqC {
	
	static int n,k,a,b,q;
	static long segtree1[], segtree2[];

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		k = in.nextInt();
		a = in.nextInt();
		b = in.nextInt();
		q = in.nextInt();
		
		segtree1 = new long[4*n];
		segtree2 = new long[4*n];
		
		for(int i = 0; i < q; i++){
			int t = in.nextInt();
			if(t == 1){
				int d = in.nextInt() - 1;
				int a = in.nextInt();
				update1(0 , n - 1 , 0 , d , a);
				update2(0 , n - 1 , 0 , d , a);
			}
			else{
				int p = in.nextInt() - 1;
				int ans = 0;
				if(p != 0)
					ans += find2(0 , n - 1 , 0 , 0 , p - 1);
				p += k;
				if(p < n)
					ans += find1(0 , n - 1,  0 , p, n - 1);
				w.println(ans);
			}
		}

		w.close();
	}
	
	public static void update1(int s,int e,int c,int x,int v){
		if(s == e)	{
			segtree1[c] += v;
			segtree1[c] = Math.min(segtree1[c], a);
			return;
		}
		int m = (s + e) >> 1;
		if(x <= m)  update1(s,m,2*c+1,x,v);
		else		update1(m+1,e,2*c+2,x,v);
		segtree1[c] = merge(segtree1[2*c+1],segtree1[2*c+2]);
	}
	
	public static long find1(int s,int e,int c,int l,int r){
		if(s == l && e == r) return segtree1[c];
		int m = (s + e) >> 1;
		if(r <= m) return find1(s,m,2*c+1,l,r);
		if(l >  m) return find1(m+1,e,2*c+2,l,r);
		return merge(find1(s,m,2*c+1,l,m) , find1(m+1,e,2*c+2,m+1,r));
	}
	
	public static void update2(int s,int e,int c,int x,int v){
		if(s == e)	{
			segtree2[c] += v;
			segtree2[c] = Math.min(segtree2[c], b);
			return;
		}
		int m = (s + e) >> 1;
		if(x <= m)  update2(s,m,2*c+1,x,v);
		else		update2(m+1,e,2*c+2,x,v);
		segtree2[c] = merge(segtree2[2*c+1],segtree2[2*c+2]);
	}
	
	public static long find2(int s,int e,int c,int l,int r){
		if(s == l && e == r) return segtree2[c];
		int m = (s + e) >> 1;
		if(r <= m) return find2(s,m,2*c+1,l,r);
		if(l >  m) return find2(m+1,e,2*c+2,l,r);
		return merge(find2(s,m,2*c+1,l,m) , find2(m+1,e,2*c+2,m+1,r));
	}
	
	public static long merge(long a,long b){
		return a + b;
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
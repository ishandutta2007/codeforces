import java.io.*;
import java.util.*;

public class R345qD {
	
	static int n,m;
	static int N;
	static int t[];
	static Pair p[];
	static int l[], r[];
	static int segtree[];
	
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		m = in.nextInt();
		
		N = n + m;
		
		p = new Pair[N];
		for(int i = 0; i < n; i++)
			p[i] = new Pair(i , in.nextInt() , -1);
		
		for(int j = n; j < N; j++)
			p[j] = new Pair(in.nextInt() - 1, in.nextInt() , j);

		l = new int[N];
		r = new int[N];
		
		Arrays.sort(p);
		//System.out.println(Arrays.deepToString(p));
		
		segtree = new int[4*n];
		int LIS = 0;
		
		for(int i = 0; i < N; i++){
			int L = 0;
			if(p[i].idx != 0)
				L += find(0 , n - 1 , 0 , 0,  p[i].idx - 1);
			L++;
			if(p[i].q == -1){
				update(0 , n - 1 , 0 , p[i].idx , L);
				l[p[i].idx] = L;
				LIS = Math.max(LIS, L);
			}
			else
				l[p[i].q] = L;
		}
		
		//System.out.println(Arrays.toString(l));

		Arrays.fill(segtree, 0);
		
		for(int i = N - 1; i >= 0; i--){
			int R = 0;
			if(p[i].idx != n - 1)
				R += find(0, n - 1 , 0 , p[i].idx + 1, n - 1);
			R++;
			if(p[i].q == -1){
				update(0 , n - 1 , 0 , p[i].idx, R);
				r[p[i].idx] = R;
			}
			else
				r[p[i].q] = R;
			//System.out.println(p[i] + " " + R);
		}
		
		//System.out.println(Arrays.toString(r));
		
		int cnt[] = new int[n + 1];
		int ans[] = new int[n];
		
		for(int i = 0;i < n;i++){
			if(r[i] + l[i] - 1 < LIS)
				ans[i] = 1;
			else
				cnt[r[i]]++;
		}
		
		for(int i=0;i<n;i++)
			if(ans[i] != 1)
				ans[i] = cnt[r[i]] == 1 ? 3 : 2;
		
		
		int pa[] = new int[m];
		for(int i = 0; i < N; i++){
			if(p[i].q != -1){
				int proAns = LIS;
				if(ans[p[i].idx] == 3)
					proAns--;
				//if(p[i].q == 7)
					//System.out.println(p[i].idx + " " + p[i].q + " " + ans[p[i].idx] + " " + proAns) ;
				proAns = Math.max(proAns, l[p[i].q] + r[p[i].q] - 1);
				pa[p[i].q - n] = proAns;
			}
		}
		
		for(int i = 0; i < m; i++)
			w.println(pa[i]);
		
		w.close();
	}
	
	public static void update(int s,int e,int c,int x,int v){
		if(s == e)	{
			segtree[c] = v;
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
		if(r <= m) return find(s,m,2*c+1,l,r);
		if(l >  m) return find(m+1,e,2*c+2,l,r);
		return merge(find(s,m,2*c+1,l,m) , find(m+1,e,2*c+2,m+1,r));
	}
	
	public static int merge(int a,int b){
		return Math.max(a, b);
	}
	
	static class Pair implements Comparable<Pair>{
		int idx,val;
		int q;
		Pair(int i,int v, int q){
			idx = i;
			val = v;
			this.q = q;
		}
		public int compareTo(Pair o){
			if(val != o.val)
				return Integer.compare(val, o.val);
			return Integer.compare(o.idx, idx);
		}
		public String toString(){
			return idx + " " + val + " " + q;
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
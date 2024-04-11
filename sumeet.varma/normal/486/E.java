import java.io.*;
import java.util.*;

public class R277qELISofSequence {

	static final int mod = (int)1e9 + 7;
	static int segtree[];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		final int m = (int)1e5;
		int n = in.nextInt();
		
		@SuppressWarnings("unchecked")
		ArrayList<Integer> g[] = new ArrayList[m + 1];
		for(int i=1;i<=m;i++)
			g[i] = new ArrayList<Integer>();
		
		for(int i=1;i<=n;i++)
			g[in.nextInt()].add(i);
		
		int maxEnding[] = new int[n + 1];
		int maxStarting[] = new int[n + 1];
		
		segtree = new int[4*n];
		
		int LIS = 0;
		
		for(int i=1;i<=m;i++){
			for(int x : g[i]){
				if(x != 1)
					maxEnding[x] = find(1,n,0,1,x-1);
				maxEnding[x]++;
				LIS = Math.max(LIS, maxEnding[x]);
			}
			for(int x : g[i])
				update(1,n,0,x,maxEnding[x]);
		}
		
		segtree = new int[4*n];
		
		for(int i=m;i>=1;i--){
			for(int x : g[i]){
				if(x != n)
					maxStarting[x] = find(1,n,0,x+1,n);
				maxStarting[x]++;
			}
			for(int x : g[i])
				update(1,n,0,x,maxStarting[x]);
		}
		
		int cnt[] = new int[n + 1];
		int ans[] = new int[n + 1];
		
		for(int i=1;i<=n;i++){
			if(maxStarting[i] + maxEnding[i] - 1 < LIS)
				ans[i] = 1;
			else
				cnt[maxStarting[i]]++;
		}
		
		for(int i=1;i<=n;i++)
			if(ans[i] != 1)
				ans[i] = cnt[maxStarting[i]] == 1 ? 3 : 2;
		
		for(int i=1;i<=n;i++)
			w.print(ans[i]);
		w.println();
		
		w.close();
	}
	
	static void update(int s,int e,int c,int x,int v){
		if(s == e)
			segtree[c] = v;
		else{
			int m = (s + e) >> 1;
			if(x <= m)
				update(s,m,2*c+1,x,v);
			else
				update(m+1,e,2*c+2,x,v);
			segtree[c] = Math.max(segtree[2*c+1],segtree[2*c+2]);
		}
	}
	
	static int find(int s,int e,int c,int l,int r){
		if(s == l && e == r)
			return segtree[c];
		int m = (s + e) >> 1;
		if(r <= m)
			return find(s,m,2*c+1,l,r);
		if(l  > m)
			return find(m+1,e,2*c+2,l,r);
		return Math.max( find(s,m,2*c+1,l,m), find(m+1,e,2*c+2,m+1,r) );
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
			
			int res = 0;

			do {
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res;
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
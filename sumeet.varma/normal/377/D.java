import java.io.*;
import java.util.*;

public class R222qDDevelopingGame {

	static SegNode segtree[];

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		final int m = 3*100010;
		int n = in.nextInt();
		
		ArrayList<Pair> add[] = new ArrayList[m + 1];
		ArrayList<Pair> rem[] = new ArrayList[m + 1];
		
		for(int i=1;i<=m;i++){
			add[i] = new ArrayList<Pair>();
			rem[i] = new ArrayList<Pair>();
		}
		
		int l[] = new int[n + 1];
		int v[] = new int[n + 1];
		int r[] = new int[n + 1];

		for(int i=1;i<=n;i++){
			l[i] = in.nextInt();
			v[i] = in.nextInt();
			r[i] = in.nextInt();
			add[l[i]].add(new Pair(v[i],r[i]));
			rem[v[i]].add(new Pair(v[i],r[i]));
		}
		
		int ans = 0,L = -1,R = -1;
		
		segtree = new SegNode[4*m];
		build(1,m,0);
		
		for(int i=1;i<=m;i++){
			for(Pair p : add[i])
				upd(1,m,0,p.x,p.y,1);
			SegNode now = find(1,m,0,1,m);
			if(now.val >= ans){
				L = i;
				R = now.idx;
				ans = now.val;
			}
			for(Pair p : rem[i])
				upd(1,m,0,p.x,p.y,-1);
		}
		
		w.println(ans);
		for(int i=1;i<=n;i++)
			if(l[i] <= L && L <= v[i] && v[i] <= R && R <= r[i])
				w.print(i + " ");
		w.println();
		
		w.close();
	}
	
	static void build(int s,int e,int c){
		if(s == e)
			segtree[c] = new SegNode(s,0);
		else{
			int m = (s + e) >> 1;
			build(s,m,2*c+1);
			build(m+1,e,2*c+2);
			segtree[c] = merge(segtree[2*c+1],segtree[2*c+2]);
		}
	}
	
	static void upd(int s,int e,int c,int l,int r,int v){
		if(s == l && e == r){
			segtree[c].lazy += v;
			segtree[c].val += v;
			return;
		}
		propogate(c);
		int m = (s + e) >> 1;
		if(r <= m)
			upd(s,m,2*c+1,l,r,v);
		else if(l > m)
			upd(m+1,e,2*c+2,l,r,v);
		else{
			upd(s,m,2*c+1,l,m,v);
			upd(m+1,e,2*c+2,m+1,r,v);
		}
		segtree[c] = merge(segtree[2*c+1],segtree[2*c+2]);
	}
	
	static SegNode find(int s,int e,int c,int l,int r){
		if(s == l && e == r)
			return segtree[c].copy();
		propogate(c);
		int m = (s + e) >> 1;
		if(r <= m)
			return find(s,m,2*c+1,l,r);
		else if(l > m)
			return find(m+1,e,2*c+2,l,r);
		else
			return merge( find(s,m,2*c+1,l,m) , find(m+1,e,2*c+2,m+1,r));	
	}
	
	static SegNode merge(SegNode a,SegNode b){
		return a.val >= b.val ? a.copy() : b.copy();
	}
	
	static void propogate(int c){
		segtree[2*c+1].lazy += segtree[c].lazy;
		segtree[2*c+2].lazy += segtree[c].lazy;
		segtree[2*c+1].val += segtree[c].lazy;
		segtree[2*c+2].val += segtree[c].lazy;
		segtree[c].lazy = 0;
	}
	
	static class Pair{
		int x,y;
		Pair(int x,int y){
			this.x = x;
			this.y = y;
		}
	}
	
	static class SegNode{
		int val,idx,lazy;
		SegNode(int idx,int val){
			this.idx = idx;
			this.val = val;
			lazy = 0;
		}
		public SegNode copy(){
			return new SegNode(idx,val);
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
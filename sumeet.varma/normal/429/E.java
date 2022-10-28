import java.io.*;
import java.util.*;

public class R245qE {

	static int n;
	static TreeSet<Pair> set;
	static int ans[];
	static ArrayList<Integer> g[];
	
  	@SuppressWarnings("unchecked")
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
		
		set = new TreeSet<Pair>();
		for(int i=1;i<=n;i++)
			set.add(new Pair(i,in.nextInt(),in.nextInt()));
		
		g = new ArrayList[n + 1];
		for(int i=1;i<=n;i++)
			g[i] = new ArrayList<Integer>();
		
		while(set.size() >= 2){
			Pair a = set.pollFirst();
			Pair b = set.pollFirst();
			if(a.y < b.x)
				set.add(b);
			else{
				g[a.idx].add(b.idx);
				g[b.idx].add(a.idx);
				if(a.y < b.y){
					b.x = a.y + 1;
					set.add(b);
				}
				else if(a.y > b.y){
					a.x = b.y + 1;
					set.add(a);
				}
			}
		}
		
		ans = new int[n + 1];
		Arrays.fill(ans, -1);
		
		for(int i=1;i<=n;i++)
			dfs(i,0);
		
		for(int i=1;i<=n;i++)
			w.print(ans[i] + " ");
		w.println();
		
		w.close();
	}
  	
  	static public void dfs(int curr,int color){
  		if(ans[curr] != -1)	return;
  		ans[curr] = color;
  		for(int x : g[curr])
  			dfs(x,1 - color);
  	}
  	
	static class Pair implements Comparable<Pair>{
		int idx,x,y;
		Pair(int idx,int x,int y){
			this.idx = idx;
			this.x = x;
			this.y = y;
		}
		public int compareTo(Pair o){
			if(x != o.x)
				return Integer.compare(x, o.x);
			if(y != o.y)
				return Integer.compare(y, o.y);
			return Integer.compare(idx, o.idx);
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
import java.io.*;
import java.util.*;

public class ER8qF {
	
	static int segtree[];

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		char s[][] = new char[n + 2][m + 2];
		s[0] = new char[m + 2];
		s[n + 1] = new char[m + 2];
		for(int j = 0; j <= m; j++)
			s[0][j] = s[n + 1][j] = '.';
		for(int i = 1; i <= n; i++)
			s[i] = ("." + in.readString() + ".").toCharArray();
		
		int l[][] = new int[n + 2][m + 2];
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				l[i][j] = (s[i][j] == 'z' ? (1 + l[i][j - 1]) : 0);
		
		int r[][] = new int[n + 2][m + 2];
		for(int i = n; i >= 1; i--)
			for(int j = m; j >= 1; j--)
				r[i][j] = (s[i][j] == 'z' ? (1 + r[i][j + 1]) : 0);
		
		int ur[][] = new int[n + 2][m + 2];
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				ur[i][j] = (s[i][j] == 'z' ? (1 + ur[i - 1][j + 1]) : 0);

		long ans = 0;
		segtree = new int[4*n];
		
		MyArrayList rem[] = new MyArrayList[n + 1];
		for(int i = 0; i <= n; i++)
			rem[i] = new MyArrayList();
		
		for(int k = 1; k <= m; k++){
			
			for(int i = 0; i <= n; i++)
				rem[i].clear();
			
			Arrays.fill(segtree, 0);
			
			for(int i = n, j = k; i >= 1 && j <= m; i--,j++){
				for(int v = 0; v < rem[i].size(); v++)
					update(1 , n , 0, rem[i].get(v) , -1);
				int mine = l[i][j];
				int myself = Math.min(r[i][j], ur[i][j]);
				if(myself != 0){
					update(1 , n , 0, i , 1);
					rem[i - myself].add(i);
				}
				if(mine != 0)
					ans += find(1 , n , 0, i , Math.min(n , i + mine - 1));
			}
		}
		
		for(int k = n - 1; k >= 1; k--){
			
			for(int i = 0; i <= n; i++)
				rem[i].clear();
			
			Arrays.fill(segtree, 0);
			
			for(int i = k, j = 1; i >= 1 && j <= m; i--,j++){
				for(int v = 0; v < rem[i].size(); v++)
					update(1 , n , 0, rem[i].get(v) , -1);
				int mine = l[i][j];
				int myself = Math.min(r[i][j], ur[i][j]);
				if(myself != 0){
					update(1 , n , 0, i , 1);
					rem[i - myself].add(i);
				}
				if(mine != 0)
					ans += find(1 , n , 0, i , Math.min(n,i + mine - 1));
			}
		}
		
		w.println(ans);
		w.close();
	}
	
	public static void update(int s,int e,int c,int x,int v){
		if(s == e)	{
			segtree[c] += v;
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
	
	public static int merge(int a,int b){
		return a + b;
	}
	
	static public class MyArrayList {
		 
	    private int[] myStore;
	    private int actSize = 0;
	     
	    public MyArrayList(){
	        myStore = new int[2];
	    }
	     
	    public int get(int index){
	        if(index < actSize)
	            return myStore[index];
	         else 
	            throw new ArrayIndexOutOfBoundsException();
	    }
	     
	    public void add(int obj){
	        if(myStore.length-actSize <= 1)
	            increaseListSize();
	        myStore[actSize++] = obj;
	    }
	   
	    public int size(){
	        return actSize;
	    }
	    
	    public void clear(){
	    	actSize = 0;
	    }
	    
	    private void increaseListSize(){
	        myStore = Arrays.copyOf(myStore, myStore.length*2);
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
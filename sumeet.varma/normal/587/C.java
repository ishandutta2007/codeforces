import java.io.*;
import java.util.*;

public class R326qC {

	static int n,m,q;
	static MyArrayList g[];
	static int L[],P[][],T[];
	static final int MAXN = 100001,LOGMAXN = 18;
	static ArrayList<Integer> c[];
	static int up[][][];
	static final int oo = (int)1e8;
	
	@SuppressWarnings("unchecked")
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		n = in.nextInt();
		m = in.nextInt();
		q = in.nextInt();
		
		g = new MyArrayList[n];
		for(int i=0;i<n;i++)
			g[i] = new MyArrayList();
		
		for(int i=1;i<n;i++){
			int u = in.nextInt() - 1;
			int v = in.nextInt() - 1;
			g[u].add(v);
			g[v].add(u);
		}
		
		c = new ArrayList[n];
		for(int i=0;i<n;i++)
			c[i] = new ArrayList<Integer>();
		
		for(int i=1;i<=m;i++)
			c[in.nextInt() - 1].add(i);
		
		for(int i=0;i<n;i++)
			if(c[i].isEmpty())
				c[i].add(oo);
		
		for(int i=0;i<n;i++)
			Collections.sort(c[i]);
		
		preprocess();
		//System.out.println(Arrays.toString(P[0]));
		
		while(q-- > 0){
			int u = in.nextInt() - 1;
			int v = in.nextInt() - 1;
			int a = in.nextInt();
			int ans[] = myQuery(u,v);
			int max = 0;
			for(int i=0;i<ans.length;i++)
				if(ans[i] == oo)	break;
				else			max = i + 1;
			max = Math.min(max	, a);
			w.print(max);
			for(int i=0;i<max;i++)
				w.print(" " + ans[i]);
			w.println();
		}
		

		w.close();
	}
	
	
	
	public static int[] merge(int[] a,int[] b){
		int ans[] = new int[Math.min(a.length + b.length, 10)];
		int i = 0,j = 0;
		//System.out.println(Arrays.toString(a) + " " + Arrays.toString(b) + " " + ans.length);
		for(int k=0;k<ans.length;k++){
			if(i >= a.length)
				ans[k] = b[j++];
			else if(j >= b.length)
				ans[k] = a[i++];
			else if(a[i] <= b[j])
				ans[k] = a[i++];
			else
				ans[k] = b[j++];
		}
		return ans;
	}
	
	public static int[] myQuery(int u,int v){
		int l = getLCA(u,v);
		return merge(up[0][l] , merge(query(u,l) , query(v,l)) );
	}
	
	public static int[] query(int u,int lca){
		if(u == lca)
			return new int[]{};
		int dist = L[u] - L[lca];
		int maxBit = Integer.toBinaryString(dist).length() - 1;
		return merge( query(P[maxBit][u],lca) , up[maxBit][u]); 
	}
	
	public static void preprocess(){
		L = new int[n];
		T = new int[n];
		dfs(0,-1);
		T[0] = 0;
		
		P = new int[LOGMAXN][n];
		up = new int[LOGMAXN][n][];
		
		for(int j=0;(1<<j)<n;j++)
			for(int i=0;i<n;i++)
				P[j][i] = -1;
		
		for(int i=0;i<n;i++){
			P[0][i] = T[i];
			int x = Math.min(10,c[i].size());
			up[0][i] = new int[x];
			for(int j=0;j<x;j++)
				up[0][i][j] = c[i].get(j);
		}
		
		for(int j=1;(1<<j) < n;++j)
			for(int i=0;i<n;++i)
				if(P[j-1][i] != -1){
					P[j][i] = P[j-1][P[j-1][i]];
					up[j][i] = merge(up[j-1][i],up[j-1][P[j-1][i]]);
				}
		
	}
	
	public static void dfs(int curr,int prev){
		T[curr] = prev;
		int s = g[curr].size();
		for(int i=0;i<s;i++){
			int nxt = g[curr].get(i);
			if(nxt != prev){
				L[nxt] = L[curr] + 1;
				dfs(nxt,curr);
			}
		}
	}
	
	public static int getLCA(int p,int q){
		int tmp,log,i;
		if(L[p] < L[q]){
			tmp = p;
			p = q;
			q = tmp;
		}
		
		for(log=1;1<<log <= L[p];log++);
		log--;
		
		for(i = log; i >= 0; i--)
			if(L[p] - (1<<i) >= L[q])
				p = P[i][p];
		
		if(p == q)	return p;
		
		for(i = log; i >= 0; i--)
			if(P[i][p] != -1 && P[i][p] != P[i][q]){
				p = P[i][p];
				q = P[i][q];
			}
		
		return T[p];
	}
	
	static public class MyArrayList {
		 
	    private int[] myStore;
	    private int actSize = 0;
	     
	    public MyArrayList(){
	        myStore = new int[5];
	    }
	     
	    public int get(int index){
	        return myStore[index];
	    }
	     
	    public void add(int obj){
	        if(myStore.length-actSize <= 1)
	            increaseListSize();
	        myStore[actSize++] = obj;
	    }
	   
	    public int size(){
	        return actSize;
	    }
	     
	    private void increaseListSize(){
	        myStore = Arrays.copyOf(myStore, myStore.length*2);
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
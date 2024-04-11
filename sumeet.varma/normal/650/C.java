import java.io.*;
import java.util.*;

public class R345qC {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		int a[][] = new int[n + 2][m + 2];
		
		int r[] = new int[n + 2];
		int c[] = new int[m + 2];
			
		int k = 0;
		Pair p[] = new Pair[n*m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				p[k++] = new Pair(i,j,in.nextInt());
		
		Arrays.sort(p);
		//System.out.println(Arrays.deepToString(p));
		
		for(int i = 0; i < n*m; ){
			
			int j = i;
			while(j < n*m && p[j].v == p[i].v)
				j++;
			
			DisjointSet ds = new DisjointSet(j - i);
			Pair A[] = new Pair[j - i];
			Pair B[] = new Pair[j - i];
			
			for(k = i; k < j; k++){
				A[k - i] = new Pair(p[k].x , p[k].y , k - i);
				B[k - i] = new Pair(p[k].x , p[k].y , k - i);
				ds.max[k - i] = Math.max(r[p[k].x], c[p[k].y]);
			}
			
			Arrays.sort(A, new XComp());
			Arrays.sort(B, new YComp());
			
			for(int x = 1; x < (j-i); x++){
				if(A[x].x == A[x - 1].x)
					ds.merge(A[x].v, A[x - 1].v);
				if(B[x].y == B[x - 1].y)
					ds.merge(B[x].v, B[x - 1].v);
			}
			
			for(int x = i; x < j ; x++){
				int v = ds.max[ds.find(x - i)] + 1;
				a[p[x].x][p[x].y] = v;
				r[p[x].x] = Math.max(r[p[x].x], v);
				c[p[x].y] = Math.max(c[p[x].y], v);
			}
			
			i = j;
			
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				w.print(a[i][j] + " ");
			w.println();
		}

		w.close();
	}
	
	static class Pair implements Comparable<Pair>{
		int x,y,v;
		Pair(int x,int y, int v){	this.x = x; this.y = y; this.v = v;}
		public int compareTo(Pair o){
			return Integer.compare(v, o.v);
		}
		public String toString(){
			return x + " " + y + " " + v;
		}
	}
	
	static class XComp implements Comparator<Pair>{
		public int compare(Pair a, Pair b){
			//if(a.x != b.x)
				return Integer.compare(a.x, b.x);
			//return Integer.compare(a.y, b.y);
		}
	}
	
	static class YComp implements Comparator<Pair>{
		public int compare(Pair a, Pair b){
			//if(a.y != b.y)
				return Integer.compare(a.y, b.y);
			//	return Integer.compare(a.x, b.x);
		}
	}
	
	static public class DisjointSet {

		public int rank[],parent[],max[];
		public int n,comp;
		
		public DisjointSet(int n){
		    this.n = n;
			makeSet();
		}
		
		public void makeSet(){
			rank = new int[n];
			parent = new int[n];
			for(int i=0;i<n;i++)
				parent[i] = i;
			max = new int[n];
			comp = n;
		}
		
		public int find(int x){
			if(parent[x] != x)
				parent[x] = find(parent[x]);
			return parent[x];
		}
		
		public void merge(int x,int y){
			int xRoot = find(x);
			int yRoot = find(y);
			
			if(xRoot == yRoot)	return;
			
			max[xRoot] = max[yRoot] = Math.max(max[xRoot] , max[yRoot]);
			
			if(rank[xRoot] < rank[yRoot])
				parent[xRoot] = yRoot;
			else{
				parent[yRoot] = xRoot;
				if(rank[xRoot] == rank[yRoot]) rank[xRoot]++;
			}
			
			comp--;
		}
		
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
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;

public class AbbyCupC1Party {

	public static void main(String args[] ) throws Exception {
		   
		InputReader in = new InputReader(System.in);
	    PrintWriter w = new PrintWriter(System.out);
	    
	    int n = in.nextInt();
	          
	    DisjointSet ds = new DisjointSet(n);
	        
	    int k = in.nextInt();
	    for(int i=0;i<k;i++)
	    	ds.merge(in.nextInt()-1, in.nextInt()-1);
	    
	    int m = in.nextInt();
	    for(int i=0;i<m;i++)
	    	ds.destroy(in.nextInt()-1,in.nextInt()-1);
	    
	    int ans = 0;
	    
	    for(int i=0;i<n;i++){
	    	int root = ds.find(i);
	    	if(ds.canTake[root])
	    		ans = Math.max(ans, ds.size[root]);
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	
	static public class DisjointSet {

		public int rank[],parent[],size[];
		public int n;
		public boolean canTake[];
		
		public DisjointSet(int n){
		    this.n = n;
			makeSet();
		}
		
		public void makeSet(){
			rank = new int[n];
			parent = new int[n];
			size = new int[n];
			canTake = new boolean[n];
			for(int i=0;i<n;i++){
				parent[i] = i;
				size[i] = 1;
				canTake[i] = true;
			}
		}
		
		public int find(int x){
			if(parent[x] != x)
				parent[x] = find(parent[x]);
			return parent[x];
		}
		
		public void merge(int x,int y){
			int xRoot = find(x);
			int yRoot = find(y);
			
			if(xRoot == yRoot)
				return;
			
			if(rank[xRoot] < rank[yRoot]){
				parent[xRoot] = yRoot;
				size[yRoot] += size[xRoot];
			}
			else{
				parent[yRoot] = xRoot;
				if(rank[xRoot] == rank[yRoot]){
					parent[yRoot] = xRoot;
					rank[xRoot]++;
				}
				size[xRoot] += size[yRoot];
			}
		}
		
		public void destroy(int x,int y){
			int xRoot = find(x);
			int yRoot = find(y);
			if(xRoot == yRoot)
				canTake[xRoot] = false;
		}
		
	}
	
	static public class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;
		public InputReader(InputStream stream) {
			this.stream = stream;
		}
		
		public int snext() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
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
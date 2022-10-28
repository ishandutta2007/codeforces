import java.io.*;
import java.util.*;

public class R270QCMakeItNonDeterministic {

	static long oo = (long)1e12;
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		
		InputReader in = new InputReader(System.in);
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int n = in.readInt();
	    
	    int origDist[][] = new int[n][n];
	    for(int i=0;i<n;i++)
	    	for(int j=0;j<n;j++)
	    		origDist[i][j] = in.readInt();
	    
	    boolean yes = true;
	    
	    Edge e[] = new Edge[(n*n - n)/2];
	    int count = 0;
	    for(int i=0;i<n;i++){
		    for(int j=i+1;j<n;j++){
		    	e[count++] = new Edge(i,j,origDist[i][j]);
		    	if(origDist[i][j] <= 0)
		   			yes = false;
		    }
	    }
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<n;j++){
	    		if(origDist[i][j] != origDist[j][i])
	    			yes = false;
	    		if(i == j && origDist[i][j] != 0)
	    			yes = false;
	    	}
	    }
	    
	    Arrays.sort(e);
	    
	    int edges = 0;
	    ArrayList<Integer> g[] = new ArrayList[n];
	    for(int i=0;i<n;i++)
	    	g[i] = new ArrayList<Integer>();
	    DS ds = new DS(n);
	    
	    for(int i=0;i<n*n-n;i++){
	    	if(ds.find(e[i].u) != ds.find(e[i].v)){
	    		ds.merge(e[i].u, e[i].v);
	    		g[e[i].u].add(e[i].v);
	    		g[e[i].u].add(e[i].x);
	    		g[e[i].v].add(e[i].u);
	    		g[e[i].v].add(e[i].x);
	    		edges++;
	    		if(edges == n-1)
	    			break;
	    	}
	    }
	    
	   // for(int i=0;i<n;i++)
	    //	System.out.println(g[i]);
	    
	    if(edges != n-1)
	    	yes = false;
	    else{
	    	long[][] dist = new long[n][n];
	    	for(int i=0;i<n;i++)
	    		for(int j=0;j<n;j++)
	    			dist[i][j] = oo;
	    	
	    	for(int i=0;i<n;i++){
	    		boolean vis[] = new boolean[n];
	    		Queue<Integer> q = new LinkedList<Integer>();
	    		q.add(i);
	    		vis[i] = true;
	    		dist[i][i] = 0;
	    		while(!q.isEmpty()){
	    			int c = q.remove();
	    			int s = g[c].size();
	    			for(int j=0;j<s;){
	    				int nxt = g[c].get(j++);
	    				int x = g[c].get(j++);
	    				if(!vis[nxt]){
	    					dist[i][nxt] = dist[i][c] + x;
	    					q.add(nxt);
	    					vis[nxt] = true;
	    				}
	    			}
	    		}
	    	}
	    	
	    //	for(int i=0;i<n;i++)
	    	//	System.out.println(Arrays.toString(dist[i]));
	    	
	    	for(int i=0;i<n;i++){
	    		for(int j=0;j<n;j++)
	    			if(dist[i][j] != origDist[i][j])
	    				yes = false;
	    	}
	    }
	    
	    w.println(yes ? "YES" : "NO");
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}

class DS {

	public int rank[],parent[];
	public int n;
	
	public DS(int n){
	    this.n = n;
		makeSet();
	}
	
	public void makeSet(){
		rank = new int[n];
		parent = new int[n];
		for(int i=0;i<n;i++)
			parent[i] = i;
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
			
			if(rank[xRoot] < rank[yRoot])
				parent[xRoot] = yRoot;
			else{
				parent[yRoot] = xRoot;
				if(rank[xRoot] == rank[yRoot])
					rank[xRoot]++;
			}
		}
	
}

class Edge implements Comparable<Edge>{
	int u,v,x;
	Edge(int a,int b,int c){
		u = a;
		v = b;
		x = c;
	}
	public int compareTo(Edge arg0) {
		return x - arg0.x;
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;
	public InputReader(InputStream stream) {
		this.stream = stream;
	}
	
	public int read() {
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

	public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}

		int res = 0;

		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
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
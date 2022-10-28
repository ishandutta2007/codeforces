import java.io.*;
import java.util.*;

public class RoundAplha20qCDijkstra {

	static int n,m;
	static ArrayList<Node> g[];
	static int parent[];
	static long oo = (long)(1e11);
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		InputReader in = new InputReader(System.in);
	    PrintWriter p = new PrintWriter(System.out);
	    
	    n = in.nextInt();
	    m = in.nextInt();
	          
		g = new ArrayList[n];
		for(int i=0;i<n;i++)
			g[i] = new ArrayList<Node>();
		
		for(int i=0;i<m;i++){
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			int w = in.nextInt();
			g[a].add(new Node(b,w));
			g[b].add(new Node(a,w));
		}
		
	    if(Dijkstra(0,g) >= oo)
	    	p.println(-1);
	    else{
	    	List<Integer> ans = new ArrayList<Integer>();
	    	int next = n-1;
	    	while(next != -1){
	    		ans.add(next);
	    		next = parent[next];
	    	}
	    	Collections.reverse(ans);
	    	for(int node : ans)
	    		p.print((node+1) + " ");
	    	p.println();
	    }
	    
	    p.close(); 
	}
	
	static public long Dijkstra(int s,ArrayList<Node> g[]){
		long[] dist = new long[g.length];
		boolean[] v = new boolean[g.length];
		parent = new int[g.length];
		Arrays.fill(dist,oo);
		Arrays.fill(parent,-1);
		dist[s]=0;
		Comparator<Node> comp = new MyComparator();
		PriorityQueue<Node> q = new PriorityQueue<Node>(2*g.length,comp);
		q.add(new Node(s,0));
		
		while(!q.isEmpty()){
			Node now = q.poll();
			if(!v[now.x]){
				v[now.x]=true;
				for(int i=0;i<g[now.x].size();i++){
					int curr = g[now.x].get(i).x;
					long w = g[now.x].get(i).dist;
					if(dist[now.x]+w<dist[curr]){
						dist[curr]=dist[now.x]+w;
						parent[curr]=now.x;
						q.add(new Node(curr,dist[curr]));
					}
				}
			}
		}
		
		return dist[n-1];
	}
	
	static class MyComparator implements Comparator<Node>{
		public int compare(Node n0, Node n1) {
			if(n0.dist>n1.dist)
				return 1;
			else if(n0.dist<n1.dist)
				return -1;
			
			return 0;
		}
	}
	
	static public class Node{
		int x;
		long dist;
		public Node(int i,long j){
			x=i;
			dist=j;
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
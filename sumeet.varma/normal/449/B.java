import java.io.*;
import java.util.*;

public class R257qBJzzhuAndCities {

	static long oo = (long)(1e16);
	
	public static void main(String args[] ) throws Exception {
		   
		InputReader in = new InputReader(System.in);
	    PrintWriter p = new PrintWriter(System.out);
	    
	    int n = in.nextInt();
	    int m = in.nextInt();
		int k = in.nextInt();
	          
		@SuppressWarnings("unchecked")
		ArrayList<Node> g[] = new ArrayList[n];
		for(int i=0;i<n;i++)
			g[i] = new ArrayList<Node>();
		
		for(int i=0;i<m;i++){
			int u = in.nextInt() - 1;
			int v = in.nextInt() - 1;
			int x = in.nextInt();
			g[u].add(new Node(v,x));
			g[v].add(new Node(u,x));
		}
		
		boolean need[] = new boolean[n];
		int train[] = new int[n];
		
		for(int i=0;i<k;i++){
			int s = in.nextInt() - 1;
			int y = in.nextInt();
			need[s] = true;
			if(train[s] == 0)
				train[s] = y;
			else
				train[s] = Math.min(train[s], y);
		}
		
		long dist[] = new long[n];
		boolean[] outOfQueue = new boolean[g.length];
		
		Arrays.fill(dist,oo);
		dist[0] = 0;
		
		Comparator<Node> comp = new MyComparator();
		PriorityQueue<Node> q = new PriorityQueue<Node>(2*g.length,comp);
		q.add(new Node(0,0));
		
		for(int i=1;i<n;i++){
			if(need[i]){
				q.add(new Node(i,train[i]));
				dist[i] = train[i];
			}
		}
	
		while(!q.isEmpty()){
			Node now = q.poll();
			int curr = now.v;
			if(!outOfQueue[curr]){
				outOfQueue[curr]=true;
				int s = g[curr].size();
				for(int i=0;i<s;i++){
					int next = g[curr].get(i).v;
					long edge = g[curr].get(i).w;
					if(dist[curr] + edge < dist[next]){
						dist[next] = dist[curr] + edge;
						need[next] = false;
						q.add(new Node(next,dist[next]));
					}
					else if(dist[curr] + edge == dist[next])
						need[next] = false;
				}
			}
		}
		
		//System.out.println(Arrays.toString(dist));
		//System.out.println(Arrays.toString(need));
		
		int der = 0;
		for(int i=1;i<n;i++)
		if(train[i] != 0 && need[i])
			der++;
	    
		p.println(k - der);
	    p.close(); 
	}
	
	
	static public int ip(String s){
		return Integer.parseInt(s);
	}
	
	static class MyComparator implements Comparator<Node>{
		public int compare(Node n0, Node n1) {
			if(n0.w>n1.w)
				return 1;
			else if(n0.w<n1.w)
				return -1;
			return 0;
		}
	}
	
	static public class Node{
		int v;
		long w;
		Node(int a,long b){
			v = a;
			w = b;
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
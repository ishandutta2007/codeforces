import java.io.*;
import java.util.*;

public class ER8qE {

	static List<Edge>[] graph;
	
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int b = in.nextInt();
		int q = in.nextInt();
		
		Pair p[] = new Pair[q + 2];
		p[0] = new Pair(0 , 0);
		p[q + 1] = new Pair(b , n);
		
		for(int i = 1; i <= q; i++)
			p[i] = new Pair(in.nextInt() , in.nextInt());
		
		Arrays.sort(p);	
		
		int ranges = q + 1;
		int nodes = 2 + 5 + ranges;
		int src = 0, snk = nodes - 1;
		createGraph(nodes);
		
		
		for(int i = 0; i + 1 < p.length; i++){
			if(p[i + 1].y < p[i].y){
				System.out.println("unfair");
				return;
			}
			if(p[i + 1].x - p[i].x < p[i + 1].y - p[i].y){
				System.out.println("unfair");
				return;
			}
			int number = p[i + 1].x - p[i].x;
			int start = p[i].x + 1;
			int der = number / 5;
			int first = start % 5;
			int left = number % 5;
			addEdge(src, i + 1 , p[i + 1].y - p[i].y);
			for(int j = ranges + 1, x = 0; j <= ranges + 5; j++, x++){
				int z = x;
				if(z < first)
					z += 5;
				if(z - first < left)
					addEdge(i + 1, j , der + 1);
				else
					addEdge(i + 1 , j, der);
			}
		}
		
		for(int j = ranges + 1; j <= ranges + 5; j++)
			addEdge(j , snk, n/5);
		
		//System.out.println("ere");
		w.println(maxFlow(src, snk) == n ? "fair" : "unfair");
		w.close();
	}
	
	static class Edge {
	    int t, rev, cap, f;

	    public Edge(int t, int rev, int cap) {
	      this.t = t;
	      this.rev = rev;
	      this.cap = cap;
	    }
	  }

	  public static void createGraph(int nodes) {
	    graph = new List[nodes];
	    for (int i = 0; i < nodes; i++)
	      graph[i] = new ArrayList<>();
	  }

	  public static void addEdge(int s, int t, int cap) {
		 // System.out.println(s + " " + t + " " + cap);
	    graph[s].add(new Edge(t, graph[t].size(), cap));
	    graph[t].add(new Edge(s, graph[s].size() - 1, 0));
	  }

	  static boolean dinicBfs(int src, int dest, int[] dist) {
	    Arrays.fill(dist, -1);
	    dist[src] = 0;
	    int[] Q = new int[graph.length];
	    int sizeQ = 0;
	    Q[sizeQ++] = src;
	    for (int i = 0; i < sizeQ; i++) {
	      int u = Q[i];
	      for (Edge e : graph[u]) {
	        if (dist[e.t] < 0 && e.f < e.cap) {
	          dist[e.t] = dist[u] + 1;
	          Q[sizeQ++] = e.t;
	        }
	      }
	    }
	    return dist[dest] >= 0;
	  }

	  static int dinicDfs( int[] ptr, int[] dist, int dest, int u, int f) {
	    if (u == dest)
	      return f;
	    for (; ptr[u] < graph[u].size(); ++ptr[u]) {
	      Edge e = graph[u].get(ptr[u]);
	      if (dist[e.t] == dist[u] + 1 && e.f < e.cap) {
	        int df = dinicDfs(ptr, dist, dest, e.t, Math.min(f, e.cap - e.f));
	        if (df > 0) {
	          e.f += df;
	          graph[e.t].get(e.rev).f -= df;
	          return df;
	        }
	      }
	    }
	    return 0;
	  }

	  public static int maxFlow(int src, int dest) {
	    int flow = 0;
	    int[] dist = new int[graph.length];
	    while (dinicBfs(src, dest, dist)) {
	      int[] ptr = new int[graph.length];
	      while (true) {
	        int df = dinicDfs(ptr, dist, dest, src, Integer.MAX_VALUE);
	        if (df == 0)
	          break;
	        flow += df;
	      }
	    }
	    return flow;
	  }
	
	static class Pair implements Comparable<Pair>{
		int x,y;
		Pair(int x,int y){	this.x = x; this.y = y; }
		public int compareTo(Pair o){
			if(x != o.x)
				return Integer.compare(x, o.x);
			return Integer.compare(y, o.y);
		}
		public String toString(){
			return x + " " + y;
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
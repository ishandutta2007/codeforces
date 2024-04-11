import java.io.*;
import java.util.*;

public class R304qESoldiersAndTravelling {

	static int n,m;
	static int oo = (int)1e8;
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		int as = 0,bs = 0;
		
		int a[] = new int[n];
		for (int i = 0; i < n; i++){
			a[i] = in.nextInt();
			as += a[i];
		}

		int b[] = new int[n];
		for(int i=0;i<n;i++){
			b[i] = in.nextInt();
			bs += b[i];
		}
		
		if(as != bs){
			System.out.println("NO");
			return;
		}
		
		int N = 2*n + 2;
		int source = 2*n;
		int sink = 2*n + 1;
		
		int g[][] = new int[N][N];
		
		for(int i=0;i<n;i++)
			g[source][i] = a[i];
			
		for(int i=0;i<n;i++)
			g[n + i][sink] = b[i];
		
		for(int i=0;i<n;i++)
			g[i][n + i] = oo;
		
		int p,q;
		while(m-- > 0){
			p = in.nextInt() - 1;
			q = in.nextInt() - 1;
			g[p][n + q] = g[q][n + p] = oo;
		}
		
		MaxFlowMinCut mf = new MaxFlowMinCut(N);
		int flow = mf.findMaxFlow(g, source, sink);
		
		if(flow == as){
			w.println("YES");
			for(int i=0;i<n;i++){
				for(int j=n;j<2*n;j++){
					w.print(g[i][j] - mf.residualGraph[i][j]);
					w.print(" ");
				}
				w.println();
			}
		}
		else
			w.println("NO");
		
		w.close();
	}
	

	static class MaxFlowMinCut{
		int n;
		int parent[];
		boolean vis[];
		Queue<Integer> queue;
		ArrayList<Integer> reachable,unreachable;
		int residualGraph[][];
		
		public MaxFlowMinCut(int n){
			this.n = n;
			queue = new LinkedList<Integer>();
			parent = new int[n];
			vis = new boolean[n];
			reachable = new ArrayList<Integer>();
			unreachable = new ArrayList<Integer>();
		}
		
		public int findMaxFlow(int graph[][],int source,int sink){
			int u,v;
			int maxFlow = 0,pathFlow;
			residualGraph = new int[n][n];
			
			for(int s=0;s<n;s++)
				for(int t=0;t<n;t++)
					residualGraph[s][t] = graph[s][t];
			
			while(bfs(source,sink,residualGraph)){
				pathFlow = Integer.MAX_VALUE;
				for(v = sink;v != source;v = parent[v]){
					u = parent[v];
					pathFlow = Math.min(pathFlow, residualGraph[u][v]);
				}
				for(v = sink;v != source;v = parent[v]){
					u = parent[v];
					residualGraph[u][v] -= pathFlow;
					residualGraph[v][u] += pathFlow;
				}
				maxFlow += pathFlow;
			}
			return maxFlow;
		}
		
		
		//O(E) / O(V*V)
		//finding a path from source to goal , assigning parent to each vertex in between
		public boolean bfs(int source,int goal,int graph[][]){
			
			int curr,next;
			
			for(int i=0;i<n;i++){
				parent[i] = -1;
				vis[i] = false;
			}
			
			queue.add(source);
			parent[source] = -1;
			vis[source] = true;
			
			while(!queue.isEmpty()){
				curr = queue.remove();
				next = 0;
				while(next < n){
					if(graph[curr][next] > 0 && !vis[next]){
						parent[next] = curr;
						queue.add(next);
						vis[next] = true;
					}
					next++;
				}
			}
			
			return vis[goal];
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
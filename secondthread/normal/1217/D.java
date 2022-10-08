import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;
/*
5 5
.....
.###.
....#
.....
.....


 * 
 * 
 */
public class D {
	
	static class Edge {
		int from, to;
		public Edge(int from, int to) {
			this.from=from;
			this.to=to;
		}
	}
	
	static class Node {
		int inDegree=0;
		ArrayList<Node> to=new ArrayList<>();
		
		void dfs() {
			for (Node n:to) {
				n.inDegree--;
				if (n.inDegree==0)
					n.dfs();
			}
		}
	}

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt();
		Node[] nodes=new Node[n];
		Edge[] edges=new Edge[m];
		for (int i=0; i<n; i++) nodes[i]=new Node();
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			edges[i]=new Edge(a, b);
			nodes[b].inDegree++;
			nodes[a].to.add(nodes[b]);
		}
		ArrayDeque<Node> toRemove=new ArrayDeque<>();
		for (int i=0; i<n; i++)
			if (nodes[i].inDegree==0)
				toRemove.add(nodes[i]);
		for (Node nn:toRemove)
			nn.dfs();
		boolean cycle=false;
		for (Node nn:nodes)
			if (nn.inDegree!=0) cycle=true;
		if (cycle) {
			System.out.println(2);
			for (Edge e:edges)
				if (e.from<e.to)
					System.out.print(1+" ");
				else 
					System.out.print(2+" ");
		}
		else {
			System.out.println(1);
			for (int i=0; i<m; i++)
				System.out.print(1+" ");
			System.out.println();
		}
	}

	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}
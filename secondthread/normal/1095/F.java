import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), nEdges=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++)
			nodes[i]=new Node(fs.nextLong());
		for (int i=0; i<nEdges; i++) {
			int from=fs.nextInt()-1, to=fs.nextInt()-1;
			long cost=fs.nextLong();
			cost=Math.min(cost, nodes[from].cost+nodes[to].cost);
			nodes[from].edges.add(new Edge(cost,  nodes[to]));
			nodes[to].edges.add(new Edge(cost, nodes[from]));
		}
		Arrays.sort(nodes);
		PriorityQueue<Edge> edges=new PriorityQueue<>();
		PriorityQueue<Node> untaken=new PriorityQueue<>();
		edges.addAll(nodes[0].edges);
		for (int i=1; i<nodes.length; i++)
			untaken.add(nodes[i]);
		long totalCost=0;
		nodes[0].taken=true;
		while (!untaken.isEmpty()) {
			long nodeCost=nodes[0].cost+untaken.peek().cost;
			while (!edges.isEmpty()&&edges.peek().cost<nodeCost) {
				Edge e=edges.remove();
				if (e.to.taken)
					continue;
				e.to.taken=true;
				totalCost+=e.cost;
				edges.addAll(e.to.edges);
			}
			Node nextNode=untaken.remove();
			if (nextNode.taken)
				continue;
			nextNode.taken=true;
			totalCost+=nodeCost;
			edges.addAll(nextNode.edges);
		}
		System.out.println(totalCost);
	}
	
	static class Node implements Comparable<Node> {
		ArrayList<Edge> edges=new ArrayList<>();
		long cost;
		boolean taken=false;
		public Node(long cost) {
			this.cost=cost;
		}
		
		public int compareTo(Node o) {
			return Long.compare(cost, o.cost);
		}
	}
	
	static class Edge implements Comparable<Edge> {
		long cost;
		Node to;
		public Edge(long cost, Node to) {
			this.cost=cost;
			this.to=to;
		}
		public int compareTo(Edge o) {
			return Long.compare(cost, o.cost);
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
			
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
	}
	
}
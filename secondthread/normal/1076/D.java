import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nNodes=fs.nextInt();
		int nEdges=fs.nextInt();
		int edgesToKeep=fs.nextInt();
		Node[] nodes=new Node[nNodes];
		Edge[] allEdges=new Edge[2*nEdges];
		for (int i=0; i<nNodes; i++)
			nodes[i]=new Node();
		int edgeIndex=0;
		for (int i=0; i<nEdges; i++) {
			int from=fs.nextInt()-1, to=fs.nextInt()-1, cost=fs.nextInt();
			nodes[from].edges.add(allEdges[edgeIndex++]=new Edge(nodes[to], cost, i));
			nodes[to].edges.add(allEdges[edgeIndex++]=new Edge(nodes[from], cost, i));
		}
		nodes[0].dist=0;
		PriorityQueue<State> pq=new PriorityQueue<>();
		pq.add(new State(nodes[0], 0));
		
		int time=0;
		while (!pq.isEmpty()) {
			State next=pq.remove();
			if (next.distance!=next.n.dist)
				continue;
			for (Edge e:next.n.edges) {
				if (e.to.dist>e.weight+next.distance) {
					e.to.dist=e.weight+next.distance;
					e.to.toGetHere=e;
					e.timeTaken=time++;
					pq.add(new State(e.to, e.to.dist));
				}
			}
		}

		ArrayList<Integer> keptEdges=new ArrayList<>();
		Arrays.sort(allEdges);
		for (Edge e:allEdges) {
			if (e.to.toGetHere!=e)
				continue;
			keptEdges.add(e.index+1);
		}
		int k=Math.min(keptEdges.size(), edgesToKeep);
		System.out.println(k);
		for (int i=0; i<k; i++)
			System.out.print(keptEdges.get(i)+" ");
	}
	
	static class State implements Comparable<State> {
		Node n;
		long distance;
		
		public State(Node n, long distance) {
			this.n=n;
			this.distance=distance;
		}

		public int compareTo(State o) {
			return Long.compare(distance, o.distance);
		}
	}
	
	static class Edge implements Comparable<Edge> {
		Node to;
		int weight;
		int index=0;
		int timeTaken=Integer.MAX_VALUE;
		public Edge(Node to, int weight, int index) {
			this.to=to;
			this.weight=weight;
			this.index=index;
		}

		public int compareTo(Edge o) {
			return Integer.compare(timeTaken, o.timeTaken);
		}
	}
	
	static class Node {
		ArrayList<Edge> edges=new ArrayList<>();
		long dist=1_000_000_000_000_000_000l;
		Edge toGetHere=null;
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
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
2 0
1 2

2 1
1 2
1 2 3

6 7
1 6
2 1 6
2 3 5
3 4 9
4 6 4
4 6 5
4 5 1
3 1 3

 */
public class C {
	
	static long bestAns=Long.MAX_VALUE;
	static Edge[] candAns=null;
	
	public static void main(String[] args) throws InterruptedException {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt();
		int target1=fs.nextInt()-1, target2=fs.nextInt()-1;
		DisjointSet dj=new DisjointSet(n);
		Node[] nodes=new Node[n];
		ArrayList<Edge> allEdges=new ArrayList<>();
		for (int i=0; i<n; i++) nodes[i]=new Node(i);
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1, c=fs.nextInt();
			if (a==b) continue;
			
			Edge e=new Edge(nodes[a], nodes[b], c, i);
			allEdges.add(e);
			nodes[a].edges.add(e);
			nodes[b].edges.add(e);
			dj.union(a, b);
		}
		
		if (dj.find(target1)!=dj.find(target2)) {
			System.out.println(0);
			System.out.println(0);
			System.out.println();
			return;
		}
		
		//try one answer
		nodes[target2].containsNode2=true;
		nodes[target1].dfs0(null);
		
//		System.out.println("\n\nConsidering 2 answers now ");
		//try all two answers now
		for (Node nn:nodes) {
			if (dj.find(nn.index)!=dj.find(target1)) continue;
			
			//the first bottom node needs to be between node 1 and node 2
			if (nn.parEdge==null) continue;
			if (!nn.containsNode2) continue;
//			System.out.println("Candidate cut one: "+nn);
			
			//the second bottom node needs to not contain node 2, and have all cross edges of the first edge, and no other cross edges
			for (Node other:nodes) other.nSpecialCrossEdges=0;
			for (Edge e:nn.crossEdges) e.deeper().nSpecialCrossEdges++;
			nodes[target1].dfs2();
			for (Node other:nodes) {
				if (other.parEdge==null) continue;
				if (dj.find(nn.index)!=dj.find(other.index)) continue;
//				System.out.println("Now checking "+other);
//				System.out.println(other.nSpecialCrossEdges+" "+nn.crossEdges.size()+" "+nn);
				if (other.nSpecialCrossEdges==nn.crossEdges.size() && !other.containsNode2 && other.crossEdges.size()==nn.crossEdges.size()) {
					considerAns(new Edge[] {nn.parEdge, other.parEdge});
				}
			}
		}
		
		if (candAns==null) {
			System.out.println(-1);
		}
		else {
			long total=0;
			for (Edge e:candAns)
				total+=e.cost;
			System.out.println(total);
			System.out.println(candAns.length);
			for (Edge e:candAns) System.out.print(e.id+1+" ");
			System.out.println();
		}
	}
	
	static int preorderCounter=0;

	static class Node {
		ArrayList<Edge> edges=new ArrayList<>();
		
		Edge parEdge;
		ArrayList<Edge> crossEdges=new ArrayList<>();
		
		ArrayList<Edge> dfsEdges=new ArrayList<>();
		ArrayList<Edge> upEdges=new ArrayList<>();
		ArrayList<Edge> downEdges=new ArrayList<>();
		
		int index, preorder=-1;
		boolean containsNode2;
		
		boolean needsToContain, cantContain;
		int nSpecialCrossEdges=0;
		
		public Node(int index) {
			this.index=index;
		}
		
		public boolean dfs0(Edge parEdge) {
			if (preorder!=-1) return false;
			this.parEdge=parEdge;
			preorder=preorderCounter++;
//			System.out.println("Dfsing at "+index+" parEdge: "+parEdge+" "+preorder);
			for (Edge e:edges) {
				if (e==parEdge) continue; //parent edge
				Node other=e.other(this);
				boolean forwardEdge=other.dfs0(e);
				if (forwardEdge) {
					dfsEdges.add(e);
					containsNode2 |= other.containsNode2;
				}
				else {
					if (other.preorder<preorder) upEdges.add(e);
					else downEdges.add(e);
				}
			}
			
			for (Edge e:upEdges) {
				this.crossEdges.add(e);
				e.alive=true;
			}
			for (Edge e:downEdges) e.alive=false;
			
			for (Edge e:dfsEdges) {
				Node other=e.other(this);
				for (Edge candCross:other.crossEdges)
					if (candCross.alive) crossEdges.add(candCross);
			}
			
			if (parEdge != null && containsNode2) {
				if (this.crossEdges.isEmpty()) considerAns(new Edge[] {parEdge});
				if (this.crossEdges.size()==1) considerAns(new Edge[] {parEdge, this.crossEdges.get(0)});
			}
//			System.out.println("CrossEdges for "+index+" are "+crossEdges);
			return true;
		}
		
		public void dfs2() {
			for (Edge e:dfsEdges) {
				Node nn=e.other(this);
				nn.dfs2();
				nSpecialCrossEdges+=nn.nSpecialCrossEdges;
			}
		}
		
		public String toString() {
			return index+"";
		}
	}
	
	static void considerAns(Edge[] edges) {
//		System.out.println("Considering answer: "+Arrays.toString(edges));
		if (candAns==null) candAns=edges;
		if (edges==null) return;
		long total=0, oldTotal=0;
		for (Edge e:edges) total+=e.cost;
		for (Edge e:candAns) oldTotal+=e.cost;
		if (oldTotal>total) {
			candAns=edges;
		}
	}
	
	static class Edge {
		Node a, b;
		int id, cost;
		boolean alive;
		
		public Edge(Node a, Node b, int cost, int id) {
			this.a=a;
			this.b=b;
			if (a==b) throw null;
			this.cost=cost;
			this.id=id;
		}
		
		Node other(Node me) {
			return me==a?b:a;
		}
		
		Node deeper() {
			if (a.preorder<b.preorder) return b;
			return a;
		}
		
		Node shallower() {
			if (a.preorder<b.preorder) return a;
			return b;
		}
		
		public String toString() {
			return a+" -> "+b;
		}
	}
	
	static class DisjointSet {
		int[] s;
		
		public DisjointSet(int n) {
			Arrays.fill(s = new int[n], -1);
		}
		
		public int find(int i) {
			return s[i] < 0 ? i : (s[i] = find(s[i]));
		}
		
		public boolean union(int a, int b) {
			if ((a = find(a)) == (b = find(b))) return false;
			if(s[a] == s[b]) s[a]--;
			if(s[a] <= s[b]) s[b] = a; else s[a] = b;
			return true;
		}
	}

	
	void sort(int[] a) {
		ArrayList<Integer> list=new ArrayList<>();
		for (int i:a) list.add(i);
		Collections.sort(list);
		for (int i=0; i<a.length; i++) a[i]=list.get(i);
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
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}

}
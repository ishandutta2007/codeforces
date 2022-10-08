import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeSet;

/*
3 2
1 2
1 3
2 3
3 2

6 6
1 2
2 3
1 4
4 5
1 6

16 1
1 2
1 5
1 6
2 4
4 7
7 8
7 9
8 10
2 3
3 11
11 12
12 13
13 14
13 15
16 13
4 12

 */
public class _LiftLevel5F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), nQueries=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node();
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		nodes[0].dfs1(null, 0);
		nodes[0].dfs2(0);
		for (int e=1; e<20; e++)
			for (Node nn:nodes)
				if (nn.lift[e-1]!=null)
					nn.lift[e]=nn.lift[e-1].lift[e-1];
		
		SegTree st=new SegTree(0, n-1);
		TreeSet<Edge> additional=new TreeSet<>();
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQueries; qq++) {
			Edge newEdge=new Edge(fs.nextInt()-1, fs.nextInt()-1);
			if (additional.contains(newEdge)) {
				additional.remove(newEdge);
				update(st, newEdge, -1, nodes, nodes[0]);
			}
			else {
				additional.add(newEdge);
				update(st, newEdge, 1, nodes, nodes[0]);
			}
			out.println(st.nZeros());
		}
		out.close();
	}
	
	static void update(SegTree st, Edge e, int delta, Node[] nodes, Node root) {
		Node a=nodes[e.a], b=nodes[e.b];
		if (a==b) throw null;
		Node lca=a.lca(b, 19);
		if (lca!=a && lca!=b) {
			//case 1: LCA is neither of them
//			System.out.println("Updating "+lca.preorder+" to "+lca.postorder+" by "+delta);
//			st.update(delta, lca.preorder, lca.postorder);
			st.update(delta, root.preorder, root.postorder);
//			System.out.println("Updating "+a.preorder+" to "+a.postorder+" by "+-delta);
			st.update(-delta, a.preorder, a.postorder);
//			System.out.println("Updating "+b.preorder+" to "+b.postorder+" by "+-delta);
			st.update(-delta, b.preorder, b.postorder);
			return;
		}
		//case 2: lca is either a or b
		Node bottom=lca==a?b:a;
		Node closestToTop=bottom.atDepth(lca.depth+1);
//		System.out.println("Updating "+closestToTop.preorder+" to "+closestToTop.postorder+" by "+delta);
		st.update(delta, closestToTop.preorder, closestToTop.postorder);
//		System.out.println("Updating "+bottom.preorder+" to "+bottom.postorder+" by "+-delta);
		st.update(-delta, bottom.preorder, bottom.postorder);
		
	}
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int preorder, postorder;
		int depth;
		Node[] lift=new Node[20];
		
		public void dfs1(Node par, int depth) {
			if (par!=null) adj.remove(par);
			lift[0]=par;
			this.depth=depth;
			for (Node nn:adj) nn.dfs1(this, depth+1);
		}
		
		public int dfs2(int c) {
			this.preorder=c;
			for (Node nn:adj) {
				c=nn.dfs2(c+1);
			}
			this.postorder=c;
			return c;
		}
		
		Node atDepth(int targetDepth) {
			if (targetDepth==depth) return this;
			int dDepth=depth-targetDepth;
			if (dDepth<0) throw null;
			int exp=Integer.numberOfTrailingZeros(Integer.lowestOneBit(dDepth));
			return lift[exp].atDepth(targetDepth);
		}
		
		Node lca(Node o, int maxJump) {
			if (depth<o.depth) {
				return o.lca(this, maxJump);
			}
			if (depth!=o.depth) {
				//this.depth is greater
				return atDepth(o.depth).lca(o, maxJump);
			}
			if (this==o) return this;
			if (lift[0]==o.lift[0]) return lift[0];
			while (lift[maxJump]==o.lift[maxJump]) maxJump--;
			return lift[maxJump].lca(o.lift[maxJump], maxJump-1);
		}
	}
	
	static class Edge implements Comparable<Edge> {
		int a, b;
		public Edge(int a, int b) {
			this.a=Math.min(a, b);
			this.b=Math.max(a, b);
		}
		
		public int compareTo(Edge o) {
			if (a!=o.a) return Integer.compare(a, o.a);
			return Integer.compare(b, o.b);
		}
	}
	
	static class SegTree {
		int leftmost, rightmost;
		SegTree lChild, rChild;
		int min, minCount, toProp;
		
		public SegTree(int leftmost, int rightmost) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
			if (leftmost!=rightmost) {
				int mid=(leftmost+rightmost)/2;
				lChild=new SegTree(leftmost, mid);
				rChild=new SegTree(mid+1, rightmost);
				recalc();
			}
			else {
				minCount=1;
			}
		}
		
		int min() {
			return min+toProp;
		}
		
		int minCount() {
			return minCount;
		}
		
		int nZeros() {
			if (min()==0) return minCount();
			return 0;
		}
		
		public void update(int toAdd, int l, int r) {
			if (l<=leftmost && r>=rightmost) {
				toProp+=toAdd;
				return;
			}
			if (l>rightmost || r<leftmost) return;
			lChild.update(toAdd, l, r);
			rChild.update(toAdd, l, r);
			recalc();
		}
		
		public void recalc() {
			min=Math.min(lChild.min(), rChild.min());
			minCount=0;
			if (min==lChild.min()) minCount+=lChild.minCount();
			if (min==rChild.min()) minCount+=rChild.minCount();
//			System.out.println("  After updating in node "+leftmost+" "+rightmost+" min is "+min+" minCount: "+minCount);
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreElements()) {
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
	}
	
}
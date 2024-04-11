import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeSet;

/*
3:03 start

7
1 2
1 3
2 4
2 5
3 6
3 7
1
2 2
4 1
7 1
1 3
 */

public class _525ETry2 {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(i);
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		
		nodes[0].dfs0(null, 0, 0);
		for (int e=1; e<20; e++)
			for (Node nn:nodes) if (nn.lift[e-1]!=null) nn.lift[e]=nn.lift[e-1].lift[e-1];
		
		int nQueries=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQueries; qq++) {
			clearVT();
			TreeSet<Node> relevant=new TreeSet<>();
			
			int nViruses=fs.nextInt(), nImportant=fs.nextInt();
			for (int i=0; i<nViruses; i++) {
				int startAt=fs.nextInt()-1, speed=fs.nextInt();
				relevant.add(nodes[startAt]);
				nodes[startAt].gotVirusFrom=nodes[startAt];
				nodes[startAt].virusSpeed=speed;
				nodes[startAt].virusID=i;
				relevant.add(nodes[startAt]);
			}
			Node[] queries=new Node[nImportant];
			for (int i=0; i<nImportant; i++) {
				int city=fs.nextInt()-1;
				queries[i]=nodes[city];
				relevant.add(nodes[city]);
			}
			buildVT(relevant);
			Node root=inVirtualTree.first();
			root.dfs1();
			root.dfs2();
			
			for (Node nn:queries) {
				out.print(nn.gotVirusFrom.virusID+1+" ");
			}
			out.println();
		}
		out.close();
	}
	
	static TreeSet<Node> inVirtualTree=new TreeSet<>();
	
	static void buildVT(TreeSet<Node> relevant) {
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		for (Node nn:relevant) {
			bfs.add(nn);
			inVirtualTree.add(nn);
		}
		while (!bfs.isEmpty()) {
			Node next=bfs.remove();
			Node before=inVirtualTree.lower(next);
			Node after=inVirtualTree.higher(next.rightmostKid);
			Node par=null;
			if (before != null) {
				Node lca=before.lca(next, 19);
				if (!inVirtualTree.contains(lca)) {
					bfs.add(lca);
					inVirtualTree.add(lca);
				}
				if (par==null || par.depth<lca.depth) par=lca;
			}
			if (after != null) {
				Node lca=after.lca(next.rightmostKid, 19);
				if (!inVirtualTree.contains(lca)) {
					bfs.add(lca);
					inVirtualTree.add(lca);
				}
				if (par==null || par.depth<lca.depth) par=lca;
			}
			if (par!=null) {
				next.parInVT=par;
				par.adjInVT.add(next);
			}
		}
	}
	
	static void clearVT() {
		for (Node nn:inVirtualTree) {
			nn.adjInVT.clear();
			nn.parInVT=null;
			nn.gotVirusFrom=null;
		}
		inVirtualTree.clear();
	}
	
	static class Node implements Comparable<Node> {
		ArrayList<Node> adj=new ArrayList<>();
		Node[] lift=new Node[20];
		int preorder, postorder, depth;
		int index;
		
		ArrayList<Node> adjInVT=new ArrayList<>();
		Node parInVT, rightmostKid=this, gotVirusFrom=null;
		int virusSpeed, virusID;
		
		public Node(int index) {
			this.index=index;
		}
		
		public int dfs0(Node par, int counter, int depth) {
			this.preorder=counter;
			this.depth=depth;
			lift[0]=par;
			if (par!=null)
				adj.remove(par);
			for (Node nn:adj) {
				counter=nn.dfs0(this, 1+counter, depth+1);
				rightmostKid=nn.rightmostKid;
			}
			return this.postorder=counter;
		}
		
		public void dfs1() {
			for (Node nn:adjInVT) {
				nn.dfs1();
				getSickFrom(nn.gotVirusFrom);
			}
		}
		
		public void dfs2() {
			if (parInVT!=null) getSickFrom(parInVT.gotVirusFrom);
			for (Node nn:adjInVT)
				nn.dfs2();
		}
		
		public void getSickFrom(Node o) {
			if (gotVirusFrom==null) {
				gotVirusFrom=o;
				return;
			}
			if (o==null) return;
			int curDist=gotVirusFrom.dist(this);
			int nextDist=o.dist(this);
			int curSpeed=gotVirusFrom.virusSpeed, nextSpeed=o.virusSpeed;
			int curTime=(curDist+curSpeed-1)/curSpeed;
			int nextTime=(nextDist+nextSpeed-1)/nextSpeed;
			if (curTime>nextTime || (curTime==nextTime && gotVirusFrom.virusID>o.virusID)) {
				gotVirusFrom=o;
			}
		}
		
		public int compareTo(Node o) {
			return Integer.compare(preorder, o.preorder);
		}
		
		public Node goUp(int toGoUp) {
			if (toGoUp==0) return this;
			int lowest=Integer.lowestOneBit(toGoUp);
			return lift[Integer.numberOfTrailingZeros(lowest)].goUp(toGoUp-lowest);
		}
		
		public Node lca(Node o, int maxLift) {
			if (depth!=o.depth) {
				if (depth>o.depth)
					return goUp(depth-o.depth).lca(o, maxLift);
				else 
					return lca(o.goUp(o.depth-depth), maxLift);
			}
			if (this==o) return this;
			if (lift[0]==o.lift[0]) return lift[0];
			while (lift[maxLift]==o.lift[maxLift])
				maxLift--;
			return lift[maxLift].lca(o.lift[maxLift], maxLift);
		}
		
		int dist(Node o) {
			Node lca=lca(o, 19);
			return depth+o.depth-lca.depth*2;
		}
		
		public String toString() {
			return index+1+"";
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

}
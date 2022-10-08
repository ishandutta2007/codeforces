import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
/*
6
2 5 0 3 1 4
1 1 3 3 3
3
2
1 6 3
2

 */
public class _526C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] perm=new int[n];
		for (int i=0; i<n; i++) perm[i]=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(perm[i]);
		for (int i=1; i<n; i++) {
			int par=fs.nextInt()-1;
			nodes[i].lift[0]=nodes[par];
			nodes[par].children.add(nodes[i]);
		}
		nodes[0].dfs(0, 0);
		for (int e=1; e<20; e++)
			for (Node nn:nodes)
				if (nn.lift[e-1]!=null)
					nn.lift[e]=nn.lift[e-1].lift[e-1];
		
		Node[] nodesWithNumber=new Node[n];
		for (int i=0; i<n; i++) nodesWithNumber[nodes[i].value]=nodes[i];
//		for (int i=0; i<n; i++) System.out.println(nodesWithNumber[i]+" "+nodesWithNumber[i].preindex+" "+nodesWithNumber[i].postIndex);
		SegTree st=new SegTree(0, n-1, nodesWithNumber);
		int nQueries=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQueries; qq++) {
			int type=fs.nextInt();
			if (type==1) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				int aNumber=nodes[a].value, bNumber=nodes[b].value;
//				System.out.println("Swapping numbers "+aNumber+" and "+bNumber);
				nodes[b].value=aNumber;
				nodes[a].value=bNumber;
				nodesWithNumber[aNumber]=nodes[b];
				nodesWithNumber[bNumber]=nodes[a];
				st.onUpdate(aNumber);
				st.onUpdate(bNumber);
			}
			else {
				int max=st.getMaxPossiblePrefix(new Node[] {nodesWithNumber[0], nodesWithNumber[0]});
				out.println(max+1);
			}
		}
		out.close();
	}
	
	static class SegTree {
		int leftmost, rightmost;
		SegTree lChild, rChild;
		boolean possible;
		Node a, b;//either b and a are separate, are b is the ancestor of a
		Node[] nodeWithNumber;
		
		public SegTree(int leftmost, int rightmost, Node[] nodeWithNumber) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
			this.nodeWithNumber=nodeWithNumber;
			if (leftmost!=rightmost) {
				int mid=(leftmost+rightmost)/2;
				lChild=new SegTree(leftmost, mid, nodeWithNumber);
				rChild=new SegTree(mid+1, rightmost, nodeWithNumber);
			}
			recalc();
		}
		
		public void onUpdate(int indexUpdated) {
			if (leftmost==rightmost) {
				recalc();
				return;
			}
			if (indexUpdated<=lChild.rightmost) {
				lChild.onUpdate(indexUpdated);
			}
			else {
				rChild.onUpdate(indexUpdated);
			}
			recalc();
		}
		
		public void recalc() {
			if (leftmost==rightmost) {
				possible=true;
				a=b=nodeWithNumber[leftmost];
//				System.out.println(this);
				return;
			}
			if (!lChild.possible||!rChild.possible) {
				possible=false;
//				System.out.println(this);
				return;
			}
			Node[] res=merge(new Node[] {lChild.a, lChild.b}, new Node[] {rChild.a, rChild.b});
			if (res==null) {
				possible=false;
			}
			else {
				possible=true;
				a=res[0]; b=res[1];
			}
//			System.out.println(this);
			
		}
		
		public int getMaxPossiblePrefix(Node[] current) {
//			System.out.println("Getting max possible prefix in "+leftmost+" "+rightmost+" current: "+(Arrays.toString(current)));
			Node[] withMe=possible?merge(current, new Node[] {a, b}):null;
			if (leftmost==rightmost && withMe==null) return leftmost-1;
			if (leftmost==rightmost) return leftmost;
			Node[] withLeft=lChild.possible?merge(current, new Node[] {lChild.a, lChild.b}):null;
			if (withLeft!=null) return rChild.getMaxPossiblePrefix(withLeft);
			return lChild.getMaxPossiblePrefix(current);
		}
		
		public String toString() {
			return "leftmost: "+leftmost+" rightmost: "+rightmost+" possible: "+possible+" a: "+a+" b: "+b;
		}
	}
	
	static Node[] merge(Node[] lChild, Node[] rChild) {
		Node[] toInclude= {lChild[0], lChild[1], rChild[0], rChild[1]};
		Node a=toInclude[0], b=toInclude[0];
		for (int i=1; i<4; i++) {
			if (deeper(a, b) != a) {
				Node temp=a;
				a=b;
				b=temp;
			}
			Node next=toInclude[i];
			boolean isLine=b.contains(a);
//			System.out.println("Is line: "+isLine+" "+next.contains(b)+" "+b.contains(next)+" "+next.contains(a)+" "+a.contains(next)+" "+a+" "+b+" "+next);
			if (isLine) {
				if (next.contains(b)) {
					b=next;
				}
				else if (b.contains(next) && next.contains(a)) {
					//ignore
				}
				else if (a.contains(next)) {
					a=next;
				}
				else {
					//no longer a line
					Node newLCA=a.lca(next, 19);
					if (!newLCA.contains(b)) {
						return null;
					}
					b=next;
				}
			}
			else {
				Node oldLCA=a.lca(b, 19);
				if (!oldLCA.contains(next)) {
					return null;
				}
				if (a.contains(next)) {
					a=next;
				}
				else if (b.contains(next)) {
					b=next;
				}
				else {
					//either it has to be on a's path or on b's path
					if (!next.contains(a) && !next.contains(b)) {
						return null;
					}
				}
			}
		}
		return new Node[] {a, b};
	}
	
	static Node deeper(Node a, Node b) {
		if (a.depth>b.depth) return a;
		return b;
	}
	static Node shallower(Node a, Node b) {
		if (a.depth<=b.depth) return a;
		return b;
	}
	
	static class Node {
		Node[] lift=new Node[20];
		ArrayList<Node> children=new ArrayList<>();
		int value, depth, preindex, postIndex;
		
		public Node(int value) {
			this.value=value;
		}
		
		public int dfs(int counter, int depth) {
			this.depth=depth;
			this.preindex=counter;
			for (Node n:children) {
				counter=n.dfs(counter+1, depth+1);
			}
			return this.postIndex=counter;
		}
		
		public boolean contains(Node o) {
			return preindex<=o.preindex && postIndex>=o.postIndex;
		}
		
		public Node getAtDepth(int depth) {
			if (depth==this.depth) return this;
			int toMoveUp=Integer.numberOfTrailingZeros(Integer.lowestOneBit(this.depth-depth));
			return lift[toMoveUp].getAtDepth(depth); 
		}
		
		public Node lca(Node o, int maxMove) {
			if (depth<o.depth)
				return lca(o.getAtDepth(depth), maxMove);
			if (o.depth<depth)
				return getAtDepth(o.depth).lca(o, maxMove);
			if (this==o) return this;
			if (lift[0]==o.lift[0]) return lift[0];
			while (lift[maxMove]==o.lift[maxMove]) maxMove--;
			return lift[maxMove].lca(o.lift[maxMove], maxMove);
		}
		
		public String toString() {
			return "{"+value+"}";
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
	}
	
}
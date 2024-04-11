import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
/*
1
2 3
 */
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(i);
		Node root=null;
		for (int i=0; i<n; i++) {
			int par=fs.nextInt()-1;
			if (par==-1) root=nodes[i];
			else {
				nodes[i].par=nodes[par];
				nodes[i].par.children.add(nodes[i]);
			}
			int indeg=fs.nextInt();
			nodes[i].indeg=indeg;
		}
		root.dfs(0);
		PriorityQueue<Node> ready=new PriorityQueue<>();
		int curLabel=1;
		for (Node nn:nodes) {
			if (nn.indeg==0) ready.add(nn);
		}
		
		while (!ready.isEmpty()) {
			Node next=ready.remove();
//			System.out.println("Processing "+next.index);
			next.process(ready, curLabel++);
		}
		for (Node nn:nodes) {
			if (nn.label==-1) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
		for (Node nn:nodes) {
			System.out.print(nn.label+" ");
		}
		System.out.println();
		
	}
	
	static class Node implements Comparable<Node> {
		Node par;
		int label=-1;
		int indeg=0;
		int depth;
		ArrayList<Node> children=new ArrayList<>();
		int index;
		public Node(int index) {
			this.index=index;
		}
		
		public void dfs(int depth) {
			this.depth=depth;
			for (Node n:children)
				n.dfs(depth+1);
		}
		
		public void process(PriorityQueue<Node> toAddTo, int curLabel) {
			this.label=curLabel;
			Node curPar=par;
			while (curPar!=null) {
				curPar.indeg--;
				if (curPar.indeg==0) toAddTo.add(curPar);
				curPar=curPar.par;
			}
		}
		
		public int compareTo(Node o) {
			return Integer.compare(depth, o.depth);
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
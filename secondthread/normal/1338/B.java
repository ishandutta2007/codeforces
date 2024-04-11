import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class B {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node();
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		for (Node nn:nodes)nn.leaf=nn.adj.size()==1;
		for (Node nn:nodes) {
			for (Node a:nn.adj) if (a.leaf) nn.adjToLeaf=true;
		}
		int nNearLeafs=0;
		for (Node nn:nodes) if(nn.adjToLeaf) nNearLeafs++;
		int nonLeaves=0;
		for (Node nn:nodes) if (!nn.leaf) nonLeaves++;
		int maxAns=nNearLeafs+(nonLeaves-1);
		
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		for (Node nn:nodes) {
			if (nn.leaf) {
				nn.color=0;
				bfs.add(nn);
			}
		}
		boolean possible=true;
		while (!bfs.isEmpty()) {
			Node next=bfs.remove();
			for (Node adj:next.adj) {
				if (adj.color==-1) {
					adj.color=next.color^1;
					bfs.add(adj);
				}
				else {
					if (adj.color==next.color) {
						possible=false;
						break;
					}
				}
			}
		}
		int minAns=possible?1:3;
		System.out.println(minAns+" "+maxAns);
	}
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		boolean adjToLeaf=false;
		boolean leaf=false;
		int color=-1;
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreElements())
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
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
	
}
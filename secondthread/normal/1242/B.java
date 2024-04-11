import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeSet;
/*
6 11
1 3
1 4
1 5
1 6
2 3
2 4
2 5
2 6
3 4
3 5
3 6


 */
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(i);
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		TreeSet<Node> ts=new TreeSet<>();
		for (Node nn:nodes) {
			ts.add(nn);
		}
		int cost=0, nPicked=0;
		while (!ts.isEmpty()) {
			Node next=ts.first();
			next.picked=true;
			ts.remove(next);
			if (nPicked!=0 && next.deg==nPicked)
				cost++;
			nPicked++;
			for (Node nn:next.adj) {
				ts.remove(nn);
				nn.deg++;
				if (!nn.picked)
					ts.add(nn);
			}
		}
		System.out.println(cost);
	}
	
	static class Node implements Comparable <Node> {
		int deg, id;
		boolean picked=false;
		ArrayList<Node> adj=new ArrayList<>();
		public Node(int id) {
			this.id=id;
		}
		
		public int compareTo(Node o) {
			if (deg!=o.deg) return Integer.compare(deg, o.deg);
			return Integer.compare(id, o.id);
		}
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
	}
	
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
/*
3
1 3 3
1 2 2
1 3 2
 */
public class _526A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) {
			nodes[i]=new Node(fs.nextInt());
		}
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1, c=fs.nextInt();
			nodes[a].adj.add(nodes[b]);
			nodes[a].costs.add(c);
			nodes[b].adj.add(nodes[a]);
			nodes[b].costs.add(c);
		}
		nodes[0].dfs(null);
		System.out.println(nodes[0].maxPathInSubtree);
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
		
		int nextInt() {
			return Integer.parseInt(next());
		}
	}
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		ArrayList<Integer> costs=new ArrayList<>();
		long myValue;
		long maxPathInSubtree;
		long maxContinuablePath;
		
		public Node(long myValue) {
			this.maxContinuablePath = this.maxPathInSubtree = this.myValue=myValue;
		}
		
		public void dfs(Node par) {
			for (int edgeID=0; edgeID<adj.size(); edgeID++) {
				Node to=adj.get(edgeID);
				if (to==par) continue;
				to.dfs(this);
				maxPathInSubtree=Math.max(maxPathInSubtree, to.maxPathInSubtree);
				
				//can also merge two potential subtree answers
				maxPathInSubtree=Math.max(maxPathInSubtree, maxContinuablePath+to.maxContinuablePath-costs.get(edgeID));
				
				//can continue path
				maxContinuablePath = Math.max(maxContinuablePath, myValue+to.maxContinuablePath-costs.get(edgeID));
			}
//			System.out.println("For node with value: "+myValue+" maxPathInSubtree: "+maxPathInSubtree+" maxContinuable: "+maxContinuablePath);
		}
	}

}
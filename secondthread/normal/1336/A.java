import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		k=n-k;
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(i+1);
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		nodes[0].dfs0(null, 0);
		Arrays.sort(nodes);
//		System.out.println("Nodes: "+Arrays.toString(nodes));
		long ans=0;
		for (int i=0; i<k; i++) ans+=(nodes[i].subtreeSize-1)-nodes[i].depth;
		System.out.println(ans);
	}
	
	static class Node implements Comparable<Node> {
		int depth, subtreeSize, id;
		ArrayList<Node> adj=new ArrayList<>();
		
		public Node(int id) {
			this.id=id;
		}
		
		public void dfs0(Node par, int depth) {
			if (par!=null) adj.remove(par);
			this.depth=depth;
			this.subtreeSize=1;
			for (Node nn:adj) {
				nn.dfs0(this, depth+1);
				subtreeSize+=nn.subtreeSize;
			}
		}
		
		public int compareTo(Node o) {
			int value=depth-subtreeSize, oValue=o.depth-o.subtreeSize;
			return Integer.compare(value, oValue);
		}
		
		public String toString() {
			return "id: "+id+" depth: "+depth+" subtreeSize: "+subtreeSize; 
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
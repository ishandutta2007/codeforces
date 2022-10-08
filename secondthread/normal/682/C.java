import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
/*
3 2
1 0 2
1 1 1
3 2
1 0 2
1 1 1
 */
public class A {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(fs.nextLong());
		for (int i=1; i<n; i++) {
			int par=fs.nextInt()-1, cost=fs.nextInt();
			nodes[i].adj.add(nodes[par]);
			nodes[i].edgeCost.add((long)cost);
			nodes[par].adj.add(nodes[i]);
			nodes[par].edgeCost.add((long)cost);
		}
		nodes[0].dfs(null, 0);
		nodes[0].dfs2();
		System.out.println(total);
	}
	
	static long total=0;
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		ArrayList<Long> edgeCost=new ArrayList<>();
		long depth, number;
		int subtreeSize=1;
		public Node(long number) {
			this.number=number;
		}
		
		public void dfs(Node par, long depth) {
			depth=Math.max(depth, 0);
			for (int i=0; i<adj.size(); i++) {
				if (adj.get(i)==par) {
					adj.remove(i);
					edgeCost.remove(i);
				}
			}
			this.depth=depth;
			for (int i=0; i<adj.size(); i++) {
				adj.get(i).dfs(this, depth+edgeCost.get(i));
				subtreeSize+=adj.get(i).subtreeSize;
			}
		}
		
		public void dfs2() {
			if (number<depth) {
				total+=subtreeSize;
				return;
			}
			for (Node nn:adj) {
				nn.dfs2();
			}
		}
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
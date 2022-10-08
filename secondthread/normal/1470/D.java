import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), m=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node(i+1);
			for (int i=0; i<m; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].adj.add(nodes[a]);
			}
			ArrayList<Integer> ans=new ArrayList<>();
			boolean possible=true;
			ArrayDeque<Node> bfs=new ArrayDeque<>();
			bfs.add(nodes[0]);
			
			while (!bfs.isEmpty()) {
				Node next=bfs.remove();
				if (next.distance!=2) {
					continue;
				}
				ans.add(next.id);
				dfs(next, 0, bfs);
			}
			
			
			for (Node nn:nodes) {
				if (nn.distance>1) possible=false;
			}
			if (possible) {
				out.println("YES");
				out.println(ans.size());
				for (int i:ans) out.print(i+" ");
				out.println();
			}
			else {
				out.println("NO");
			}
		}
		out.close();
	}
	
	static void dfs(Node from, int dist, ArrayDeque<Node> bfs) {
		if (dist==2 && from.distance >=2) {
			bfs.add(from);
			return;
		}
		if (from.distance<=dist) return;
		from.distance=dist;
		for (Node nn:from.adj) {
			dfs(nn, dist+1, bfs);
		}
	}

	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int distance=2;
		int id;
		public Node(int id) {
			this.id=id;
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
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
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}
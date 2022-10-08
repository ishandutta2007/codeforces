import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
2
4 1
1 2 5
3 1 2
3 4 3
7 2
1 2 5
1 3 4
1 4 2
2 5 1
2 6 2
4 7 3


8
14

 */
public class C {
	
	static int k;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=1; tt<=T; tt++) {
			int n=fs.nextInt();
			k=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node(i+1);
			for (int i=1; i<n; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1, c=fs.nextInt();
				nodes[a].edges.add(new Edge(nodes[b], c));
				nodes[b].edges.add(new Edge(nodes[a], c));
			}
			nodes[0].dfs(null);
			long ans=nodes[0].bonus+nodes[0].km1Sum;
			out.println(ans);
		}
		out.close();
	}
	
	static class Node {
		ArrayList<Edge> edges=new ArrayList<>();
		long km1Sum=0, bonus=0;
		
		int index;
		public Node(int index) {
			this.index=index;
		}
		
		public void dfs(Node par) {
			if (par!=null) {
				for (int i=0; i<edges.size(); i++) {
					if (edges.get(i).to==par) {
						edges.remove(i);
					}
				}
			}
			
			for (int i=0; i<edges.size(); i++) {
				edges.get(i).to.dfs(this);
			}
			for (int i=0; i<edges.size(); i++) {
				edges.get(i).val-=edges.get(i).to.bonus;
			}
//			System.out.println("In node: "+index);
			Collections.sort(edges);
			for (int i=0; i<Math.min(k, edges.size()); i++) {
				Edge e=edges.get(edges.size()-1-i);
//				System.out.println("Edge has value: "+e.val);
				if (e.val<0) continue;
				if (i==k-1) {
					bonus+=e.val;
				}
				else {
					km1Sum+=e.val;
				}
			}
			for (Edge e:edges) {
				km1Sum+=e.to.km1Sum+e.to.bonus;
			}
		}
	}
	
	static class Edge implements Comparable<Edge> {
		Node to;
		long val;
		public Edge(Node to, int val) {
			this.val=val;
			this.to=to;
		}
		
		public int compareTo(Edge o) {
			return Long.compare(val, o.val);
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
					// TODO Auto-generated catch block
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
	}
	
}
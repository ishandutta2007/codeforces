import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
1
3 4
2 3
3 2
3 1
2 1
 */
public class G {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), m=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node(i);
			for (int i=0; i<m; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].indegree++;
			}
			bfs(nodes[0], nodes);
			for (Node nn:nodes) if (!nn.reachable) {
				nn.label=0;
				for (Node mm:nn.adj) mm.indegree--;
			}
			
			ArrayDeque<Node> topSort=new ArrayDeque<>();
			for (Node nn:nodes) if (nn.indegree==0 && nn.reachable) topSort.add(nn);
			while (!topSort.isEmpty()) {
				Node next=topSort.remove();
				next.hasCycle=true;
				for (Node nn:next.adj) {
					nn.indegree--;
					if (nn.indegree==0) topSort.addLast(nn);
				}
			}
//			for (Node nn:nodes) {
//				System.out.println(nn+" "+nn.indegree);
//			}
			ArrayDeque<Node> cycleStarts=new ArrayDeque<>();
			for (Node nn:nodes) {
				if (nn.indegree!=0 && nn.reachable) {
					nn.hasCycle=true;
					cycleStarts.addLast(nn);
				}
			}
			bfs(cycleStarts, nodes);
			for (Node nn:nodes) if (nn.reachable) nn.label=-1;
			
			//1/2 depending on unique paths
			nodes[0].dfs();
			for (Node nn:nodes) if (nn.label==-2) nn.label=nn.reachableTimes;
			
			for (Node nn:nodes)
				out.print(nn.label+" ");
			out.println();
		}
		out.close();
	}
	
	static void bfs(ArrayDeque<Node> from, Node[] nodes) {
		for (Node nn:nodes) nn.reachable=false;
		for (Node nn:from) nn.reachable=true;
		ArrayDeque<Node> bfs=from;
		while (!bfs.isEmpty()) {
			Node next=bfs.remove();
			for (Node other:next.adj) {
				if (!other.reachable) {
					other.reachable=true;
					bfs.add(other);
				}
			}
		}
	}
	
	static void bfs(Node from, Node[] nodes) {
		ArrayDeque<Node> ffrom=new ArrayDeque<>();
		ffrom.add(from);
		bfs(ffrom, nodes);
	}

	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int label=-2;
		boolean reachable, hasCycle=false;
		int indegree=0;
		int id;
		int reachableTimes=0;
		
		public Node(int id) {
			this.id=id;
		}
		
		public String toString() {
			return id+1+"";
		}
		
		void dfs() {
			if (this.reachableTimes==2) {
				return;
			}
			this.reachableTimes++;
			for (Node nn:adj) nn.dfs();
		}
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
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
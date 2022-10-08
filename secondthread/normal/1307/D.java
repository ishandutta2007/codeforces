import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt(), nSpecial=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node();
		for (int i=0; i<nSpecial; i++) nodes[fs.nextInt()-1].special=true;
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		bfs(nodes[0], nodes);
		for (Node nn:nodes) nn.sDist=nn.dist;
		bfs(nodes[n-1], nodes);
		for (Node nn:nodes) nn.eDist=nn.dist;
		int bestDist=0;
		int bestEDist=-1_000_000_000;
		ArrayList<Node> specialNodes=new ArrayList<>();
		for (Node nn:nodes) if (nn.special) specialNodes.add(nn);
		Collections.sort(specialNodes);
		
		for (int i=specialNodes.size()-1; i>=0; i--) {
			if (i!=specialNodes.size()-1) {
				bestDist=Math.max(bestDist, specialNodes.get(i).sDist+1+bestEDist);
			}
			bestEDist=Math.max(bestEDist, specialNodes.get(i).eDist);
		}
		bestDist=Math.min(bestDist, nodes[0].eDist);
		System.out.println(bestDist);
	}
	
	static void bfs(Node from, Node[] nodes) {
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		for (Node nn:nodes) nn.dist=-1;
		bfs.add(from);
		from.dist=0;
		while (!bfs.isEmpty()) {
			Node next=bfs.remove();
			for (Node nn:next.adj) {
				if (nn.dist==-1) {
					nn.dist=next.dist+1;
					bfs.add(nn);
				}
			}
		}
	}
	
	static class Node implements Comparable<Node> {
		int sDist=-1, eDist=-1, dist=-1;
		ArrayList<Node> adj=new ArrayList<>();
		boolean special=false;
		
		public int compareTo(Node o) {
			if (sDist!=o.sDist) return Integer.compare(sDist, o.sDist);
			return Integer.compare(eDist, o.eDist);
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
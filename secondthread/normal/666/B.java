import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class E {

	static int best=-1, bestA, bestB, bestC, bestD;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nNodes=fs.nextInt();
		int nEdges=fs.nextInt();
		int[][] dist=new int[nNodes][nNodes];
		Node[] nodes=new Node[nNodes];
		for (int i=0; i<nNodes; i++) nodes[i]=new Node();
		for (int i=0; i<nEdges; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
		}
		for (int i=0; i<nNodes; i++) {
			bfs(nodes[i], nodes);
			for (int j=0; j<nNodes; j++)
				dist[i][j]=nodes[j].dist;
		}
		
		for (int base=0; base<nNodes; base++) {
			for (int other=0; other<nNodes; other++) {
				if (other==base) continue;
				if (nodes[base].a1==-1 || dist[other][base]>dist[nodes[base].a1][base])
					nodes[base].a1=other;
			}
			for (int other=0; other<nNodes; other++) {
				if (other==base || other==nodes[base].a1) continue;
				if (nodes[base].a2==-1 || dist[other][base]>dist[nodes[base].a2][base])
					nodes[base].a2=other;
			}
			for (int other=0; other<nNodes; other++) {
				if (other==base || other==nodes[base].a1 || other==nodes[base].a2) continue;
				if (nodes[base].a3==-1 || dist[other][base]>dist[nodes[base].a3][base])
					nodes[base].a3=other;
			}
			for (int other=0; other<nNodes; other++) {
				if (other==base) continue;
				if (nodes[base].b1==-1 || dist[base][other]>dist[base][nodes[base].b1])
					nodes[base].b1=other;
			}
			for (int other=0; other<nNodes; other++) {
				if (other==base || other==nodes[base].b1) continue;
				if (nodes[base].b2==-1 || dist[base][other]>dist[base][nodes[base].b2])
					nodes[base].b2=other;
			}
			for (int other=0; other<nNodes; other++) {
				if (other==base || other==nodes[base].b1 || other==nodes[base].b2) continue;
				if (nodes[base].b3==-1 || dist[base][other]>dist[base][nodes[base].b3])
					nodes[base].b3=other;
			}
		}
		
		for (int b=0; b<nNodes; b++) {
			for (int c=0; c<nNodes; c++) {
				best=Math.max(best, tryNodes(nodes[b].a1, b, c, nodes[c].b1, dist));
				best=Math.max(best, tryNodes(nodes[b].a2, b, c, nodes[c].b1, dist));
				best=Math.max(best, tryNodes(nodes[b].a3, b, c, nodes[c].b1, dist));
				best=Math.max(best, tryNodes(nodes[b].a1, b, c, nodes[c].b2, dist));
				best=Math.max(best, tryNodes(nodes[b].a1, b, c, nodes[c].b3, dist));
				best=Math.max(best, tryNodes(nodes[b].a2, b, c, nodes[c].b2, dist));
				best=Math.max(best, tryNodes(nodes[b].a3, b, c, nodes[c].b2, dist));
				best=Math.max(best, tryNodes(nodes[b].a2, b, c, nodes[c].b3, dist));
				best=Math.max(best, tryNodes(nodes[b].a3, b, c, nodes[c].b3, dist));
			}
		}
//		System.out.println(best);
		System.out.println(bestA+" "+bestB+" "+bestC+" "+bestD);
	}
	
	static int tryNodes(int a, int b, int c, int d, int[][] dist) {
		if (a==b||a==c||a==d||b==c||b==d||c==d) return -1;
		int res=dist[a][b]+dist[b][c]+dist[c][d];
		if (res>best) {
			bestA=a+1;
			bestB=b+1;
			bestC=c+1;
			bestD=d+1;
		}
		return res;
	}
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int dist;
		
		int a1=-1, a2=-1, a3=-1;
		int b1=-1, b2=-1, b3=-1;
	}
	
	static void bfs(Node from, Node[] nodes) {
		int oo=100000;
		for (Node n:nodes) n.dist=-oo;
		from.dist=0;
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		bfs.add(from);
		while (!bfs.isEmpty()) {
			Node next=bfs.remove();
			for (Node nn:next.adj) {
				if (nn.dist!=-oo) continue;
				nn.dist=next.dist+1;
				bfs.add(nn);
			}
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
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
	}

}
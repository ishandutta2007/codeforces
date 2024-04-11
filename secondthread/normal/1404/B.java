import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int aStart=fs.nextInt()-1, bStart=fs.nextInt()-1, 
					aDist=fs.nextInt(), bDist=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node();
			for (int i=1; i<n; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].adj.add(nodes[a]);
			}
			if (aDist*2>=bDist) {
				//bob can't safely jump over alice
				out.println("Alice");
				continue;
			}
			bfs(nodes, nodes[bStart]);
			if (nodes[aStart].dist<=aDist) {
				//alice wins in one move
				out.println("Alice");
				continue;
			}
			Node farthest=farthest(nodes);
			bfs(nodes, farthest);
			farthest=farthest(nodes);
			int diam=farthest.dist;
//			out.println(diam);
			
			boolean canWin=false;
//			for (Node nn:nodes)
//				if (nn.dist>aDist+aDist)
//					canWin=true;
			canWin=diam>aDist*2;
			out.println(canWin?"Bob":"Alice");
		}
		out.close();
	}
	
	static Node farthest(Node[] nodes) {
		Node ans=nodes[0];
		for (Node nn:nodes) if (nn.dist>ans.dist) ans=nn;
		return ans;
	}
	
	static void bfs(Node[] nodes, Node from) {		
		for (Node nn:nodes) nn.dist=-1;
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		bfs.add(from);
		from.dist=0;
		while (!bfs.isEmpty()) {
			Node nn=bfs.remove();
			for (Node adj:nn.adj) {
				if (adj.dist==-1) {
					adj.dist=nn.dist+1;
					bfs.add(adj);
				}
			}
		}
	}
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int dist=-1;
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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
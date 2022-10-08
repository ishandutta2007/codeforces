import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

public class F {
	static Random rand=new Random();
	static int sqrt=0;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt();
		while (sqrt*sqrt<n) sqrt++;
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++)
			nodes[i]=new Node(i);
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adjList.add(nodes[b]);
			nodes[b].adjList.add(nodes[a]);
		}
		for (Node nn:nodes) nn.remake();
		
		for (int i=0; i<100; i++)
			if (tryCycle(nodes)) return;

		for (int i=0; i<150; i++)
			if (tryIndSet(nodes)) return;
		
		
		throw null;
	}
	
	static class Node {
		ArrayList<Node> adjList=new ArrayList<>();
		Node[] adj;
		boolean hit;
		int depth, id;
		Node par;
		
		public Node(int id) {
			this.id=id;
		}
		
		public boolean dfs(Node par, int depth) {
			this.par=par;
			this.depth=depth;
			hit=true;
			for (Node nn:adj) {
				if (!nn.hit) continue;
				int oDepth=nn.depth;
				int length=depth-oDepth+1;
				if (length>=sqrt) {
					PrintWriter out=new PrintWriter(System.out);
					out.println(2);
					out.println(length);
					Node cur=this;
					while (cur!=nn) {
						out.print(cur.id+1+" ");
						cur=cur.par;
					}
					out.println(nn.id+1);
					out.close();
					return true;
				}
			}
			for (Node nn:adj)
				if (!nn.hit)
					if (nn.dfs(this, depth+1))
						return true;
			return false;
		}
		
		public void remake() {
			adj=new Node[adjList.size()];
			for (int i=0; i<adj.length; i++) adj[i]=adjList.get(i);
		}
	}
	
	static boolean tryIndSet(Node[] nodes) {
		ArrayList<Integer> order=new ArrayList<>();
		int n=nodes.length;
		for (int i=0; i<n; i++) order.add(i);
		Collections.shuffle(order);
		
		for (Node nn:nodes) nn.hit=false;
		ArrayList<Integer> taken=new ArrayList<>();
		for (int toTakeI:order) {
			Node toTake=nodes[toTakeI];
			if (toTake.hit) continue;
			taken.add(toTakeI);
			for (Node nn:toTake.adj) nn.hit=true;
		}
		if (taken.size()>=sqrt) {
			PrintWriter out=new PrintWriter(System.out);
			out.println(1);
			for (int i=0; i<sqrt; i++) out.print(taken.get(i)+1+" ");
			out.println();
			out.close();
			return true;
		}
		return false;
	}
	
	static boolean tryCycle(Node[] nodes) {
		for (Node nn:nodes) nn.hit=false;
		int n=nodes.length;
		int start=rand.nextInt(n);
		if (nodes[start].dfs(null, 0)) {
			return true;
		}
		return false;
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
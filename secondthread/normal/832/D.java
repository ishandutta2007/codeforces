import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Round2B {

	
	public static void solve(FastScanner fs) {
		int n=fs.nextInt(), nQueries=fs.nextInt();
		int[] parOf=fs.readArray(n-1);
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(i);
		for (int i=1; i<n; i++) {
			nodes[i].lift[0]=nodes[parOf[i-1]-1];
			nodes[parOf[i-1]-1].children.add(nodes[i]);
		}
		
		for (int exp=1; exp<20; exp++)
			for (Node nn:nodes)
				nn.lift[exp]=nn.lift[exp-1]==null?null:nn.lift[exp-1].lift[exp-1];

		nodes[0].dfs(0);
		
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQueries; qq++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1, c=fs.nextInt()-1;
			int max=0;
			max=Math.max(max, eval(a, b, c, nodes));
			max=Math.max(max, eval(a, c, b, nodes));
			max=Math.max(max, eval(b, a, c, nodes));
			max=Math.max(max, eval(b, c, a, nodes));
			max=Math.max(max, eval(c, a, b, nodes));
			max=Math.max(max, eval(c, b, a, nodes));
			out.println(max+1);
		}
		out.close();
		
	}
	
	static int eval(int ai, int bi, int ci, Node[] nodes) {
		Node a=nodes[ai], b=nodes[bi], c=nodes[ci];
		Node lca1=a.lca(b, 19), lca2=b.lca(c, 19), lca3=c.lca(a, 19);
		Node tri=deepest(lca1, lca2, lca3);
		int ans=tri.dist(c);
		return ans;
	}

	static Node deepest(Node a, Node b, Node c) {
		if (a.depth>=b.depth && a.depth>=c.depth) return a;
		if (b.depth>=c.depth) return b;
		return c;
	}
	
	static class Node {
		Node[] lift=new Node[20];
		int depth, index;
		ArrayList<Node> children=new ArrayList<>();
		
		public Node(int index) {
			this.index=index;
		}
		
		public void dfs(int depth) {
			this.depth=depth;
			for (Node n:children)
				n.dfs(depth+1);
		}
		
		
		public Node lca(Node o, int toTravel) {
			if (depth!=o.depth) {
				if (depth<o.depth)
					return o.lca(this, toTravel);
				int diff=depth-o.depth;
				int exp=Integer.numberOfTrailingZeros(Integer.highestOneBit(diff));
//				System.out.println("At node "+index+" other: "+o.index+" lifting 2^"+exp);
				return lift[exp].lca(o, toTravel);
			}
			if (this==o) return this;
			if (this.lift[0]==o.lift[0]) return lift[0];
			while (lift[toTravel]==o.lift[toTravel]) toTravel--;
//			System.out.println("Getting the LCA between "+index+" and "+o.index+" lifting "+toTravel+" "+depth+" "+o.depth);
			return lift[toTravel].lca(o.lift[toTravel], toTravel);
		}
		
		int dist(Node o) {
			Node lca=lca(o, 19);
			return depth+o.depth-2*lca.depth;
		}
	}
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException, InterruptedException {
		FastScanner scanner = new FastScanner(System.in);
		Thread t=new Thread(null, null, "T", 1<<28) {
			public void run() {
				solve(scanner);
			}
		};
		t.start();
		t.join();
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}
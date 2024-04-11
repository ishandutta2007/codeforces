import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class D {
	static long mod=998244353;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++)
			nodes[i]=new Node();
		for (int i=1; i<n; i++) {
			int par=fs.nextInt()-1;
			nodes[par].children.add(nodes[i]);
			nodes[i].children.add(nodes[par]);
		}
		nodes[0].dfs(null);
		PriorityQueue<Node> pq=new PriorityQueue<>((a, b)->{return Integer.compare(a.nLeaves, b.nLeaves);});
		for (Node nn:nodes)
			pq.add(nn);
		
		PrintWriter out=new PrintWriter(System.out);
		for (int i=0; i<n; i++)
			out.print(pq.remove().nLeaves+" ");
		out.println();
		out.close();
	}

	static class Node {
		ArrayList<Node> children=new ArrayList<>();
		int nLeaves=0;
		
		public void dfs(Node par) {
			if (par!=null) children.remove(par);
			if (children.isEmpty())
				nLeaves=1;
			for (Node n:children) {
				n.dfs(this);
				nLeaves+=n.nLeaves;
			}
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
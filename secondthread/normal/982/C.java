import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		if (n%2!=0) {
			System.out.println(-1);
			return;
		}
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++)nodes[i]=new Node();
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1;
			int b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		Node leaf=nodes[0];
		for (Node nn:nodes) if (nn.adj.size()==1) leaf=nn;
		leaf.dfs(null);
		int count=0;
		for (Node nn:nodes) if (nn.size%2==0) count++;
		count--;
		System.out.println(count);
	}
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int size=0;
		
		private void dfs(Node par) {
			size=1;
			for (Node n:adj) {
				if (n==par)
					continue;
				n.dfs(this);
				size+=n.size;
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
		
		public long[] readArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
	}
	
}
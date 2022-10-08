import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {
	
	static int oo=(int)1e8;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), m=fs.nextInt(), a=fs.nextInt()-1, b=fs.nextInt()-1, c=fs.nextInt()-1;
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node();
			int[] prices=fs.readArray(m);
			sort(prices);
			long[] cs=new long[m+1];
			for (int i=1; i<=m; i++) cs[i]=cs[i-1]+prices[i-1];
			for (int i=0; i<m; i++) {
				int aa=fs.nextInt()-1, bb=fs.nextInt()-1;
				nodes[aa].adj.add(nodes[bb]);
				nodes[bb].adj.add(nodes[aa]);
			}
			bfs(nodes[a], nodes);
			for (int i=0; i<n; i++) nodes[i].aDist=nodes[i].dist;
			bfs(nodes[b], nodes);
			for (int i=0; i<n; i++) nodes[i].bDist=nodes[i].dist;
			bfs(nodes[c], nodes);
			for (int i=0; i<n; i++) nodes[i].cDist=nodes[i].dist;
			long ans=Long.MAX_VALUE;
			for (Node nn:nodes) {
				int bCost=nn.bDist;
				int otherCost=nn.aDist+nn.cDist;
				if (bCost+otherCost>m) continue;
				long totalCost=cs[otherCost+bCost];
				totalCost+=cs[bCost];
				ans=Math.min(ans, totalCost);
			}
			System.out.println(ans);
		}
	}
	
	static void bfs(Node from, Node[] nodes) {
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		for (Node nn:nodes) nn.dist=oo;
		bfs.add(from);
		from.dist=0;
		while(!bfs.isEmpty()) {
			Node next=bfs.remove();
			for (Node nn:next.adj) {
				if (nn.dist==oo) {
					nn.dist=next.dist+1;
					bfs.add(nn);
				}
			}
		}
	}
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int dist;
		int aDist, bDist, cDist;
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
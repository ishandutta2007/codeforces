import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class F {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(i);
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		Node end1=getFarthestFrom(nodes[0], nodes);
		Node end2=getFarthestFrom(end1, nodes);
		int diamLen=end2.distance;
		for (Node nn:nodes) nn.d2=nn.distance;
		bfs(end2, nodes);
		int thirdIndex=0;
		while (end1==nodes[thirdIndex] || end2==nodes[thirdIndex]) thirdIndex++;
		Node third=nodes[thirdIndex];
		for (Node nn:nodes) {
			if (nn.d2+nn.distance>third.d2+third.distance) {
				third=nn;
			}
		}
		long totalNodes=diamLen+(third.d2+third.distance-diamLen)/2;
		System.out.println(totalNodes);
		System.out.println(end1.index+" "+end2.index+" "+third.index);
	}
	
	static void bfs(Node from, Node[] nodes) {
		for (Node nn:nodes) nn.distance=-1;
		from.distance=0;
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		bfs.add(from);
		while (!bfs.isEmpty()) {
			Node next=bfs.remove();
			for (Node nn:next.adj) {
				if (nn.distance==-1) {
					nn.distance=next.distance+1;
					bfs.add(nn);
				}
			}
		}
	}
	
	static Node getFarthestFrom(Node n, Node[] nodes) {
		bfs(n, nodes);
		Node farthest=n;
		for (Node nn:nodes) {
			if (nn.distance>farthest.distance) farthest=nn;
		}
		return farthest;
	}
	
	static class Node {
		int index, distance, d2;
		ArrayList<Node> adj=new ArrayList<>();
		public Node(int index) {
			this.index=index+1;
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
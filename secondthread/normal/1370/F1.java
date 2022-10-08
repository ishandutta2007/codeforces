import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class F {
	
	static FastScanner fs;

	public static void main(String[] args) {
		fs=new FastScanner();
		//query everything to get a node on the path 							1
		//binary search distance from that node to the farther of the two		10
		//query all nodes of the right distance from the farther				1
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			ansNode=-1;
			int n=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node(i);
			for (int i=1; i<n; i++) {
				int a=fs.nextInt()-1;
				int b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].adj.add(nodes[a]);
			}
			//get root
			System.out.print("? "+n+" ");
			for (int i=1; i<=n; i++) System.out.print(i+" ");
			System.out.println(); System.out.flush();
			int root=fs.nextInt()-1;
			int distBetweenAnswers=fs.nextInt();
			
			bfs(nodes[root], nodes);
			int min=1, max=farthest(nodes);
			while (min!=max) {
				int mid=(min+max+1)/2;
				tryDistance(nodes, root, mid);
				if (distReturned>distBetweenAnswers) {
					max=mid-1;
				}
				else {
					min=mid;
				}
			}

			tryDistance(nodes, root, min);
			int n1=nodeReturned;
			tryDistance(nodes, n1, distBetweenAnswers);
			int n2=nodeReturned;
			System.out.println("! "+(n1+1)+" "+(n2+1)); System.out.flush();
			fs.next();// read correct or incorrect
			
		}
	}

	static int distReturned, nodeReturned;
	static int ansNode;
	
	static void tryDistance(Node[] nodes, int root, int dist) {
		bfs(nodes[root], nodes);
		ArrayList<Node> use=new ArrayList<>();
		for (Node nn:nodes) if (nn.dist==dist) {
			use.add(nn);
		}
		System.out.print("? "+(use.size())+" ");
		for (Node nn:use) System.out.print((nn.index+1)+" ");
		System.out.println(); System.out.flush();
		nodeReturned=fs.nextInt()-1;
		distReturned=fs.nextInt();
	}
	
	static void bfs(Node from, Node[] nodes) {
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		bfs.add(from);
		for (Node nn:nodes) nn.dist=-1;
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
	
	static int farthest(Node[] nodes) {
		int ans=0;
		for (Node nn:nodes) ans=Math.max(ans, nn.dist);
		return ans;
	}
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int dist, index;
		public Node (int index) {
			this.index=index;
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
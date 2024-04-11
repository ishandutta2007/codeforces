import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

/*

 */
public class B {

	public static void main(String[] args) {
		FastScanner fs = new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node();
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].forwards.add(nodes[b]);
			nodes[b].backwards.add(nodes[a]);
		}
		int pathLen=fs.nextInt();
		int[] path=fs.readArray(pathLen);
		for (int i=0; i<pathLen; i++) path[i]--;
		bfs(nodes, nodes[path[pathLen-1]]);
		int min=0, max=0;
		for (int i=0; i+1<pathLen; i++) {
			if (nodes[path[i]].dist!=nodes[path[i+1]].dist+1) {
				min++;
				max++;
			}
			else {
				int optimal=0;
				for (Node nn:nodes[path[i]].forwards) {
					if (nn.dist==nodes[path[i]].dist-1) optimal++;
				}
				if (optimal>1)
					max++;
			}
		}
		System.out.println(min+" "+max);
	}
	
	static void bfs(Node[] nodes, Node from) {
		for (Node nn:nodes) nn.dist=-1;
		from.dist=0;
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		bfs.add(from);
		while (!bfs.isEmpty()) {
			Node next=bfs.remove();
			for (Node nn:next.backwards) {
				if (nn.dist==-1) {
					nn.dist=next.dist+1;
					bfs.add(nn);
				}
			}
		}
	}
	
	static class Node {
		int dist;
		ArrayList<Node> forwards=new ArrayList<>();
		ArrayList<Node> backwards=new ArrayList<>();
	}

	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			while (!st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}

}
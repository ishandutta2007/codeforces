import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) throws InterruptedException {
		Thread t=new Thread(null, null, "", 1<<29) {
			public void run() {
				new C();
			}
		};
		t.start();
		t.join();
	}

	public C() {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node(i);
			for (int i=1; i<n; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].adj.add(nodes[a]);
				nodes[a].adjO.add(nodes[b]);
				nodes[b].adjO.add(nodes[a]);
			}
			nodes[0].dfs(null);
			Node cent=nodes[0];
			for (Node nn:nodes)
				if (nn.biggest(n)<cent.biggest(n)) cent=nn;
			Node nextCent=cent==nodes[0]?nodes[1]:nodes[0];
			for (Node nn:nodes) {
				if (nn==cent) continue;
				if (nn.biggest(n)<nextCent.biggest(n)) nextCent=nn;
			}
			bfs(nextCent, nodes);
			for (Node nn:nodes) nn.dist2=nn.dist;
			bfs(cent, nodes);
//			System.out.println("Using: "+cent.id+" "+nextCent.id);
//			for (Node nn:nodes) System.out.println(nn.dist+" "+nn.dist2);
			Node leaf=null;
			for (Node nn:nodes) {
				if (nn.dist<=nn.dist2) continue;
				if (nn.adjO.size()==1) {
					leaf=nn;
					break;
				}
			}
//			System.out.println("Leaf: "+leaf.id);
			System.out.println(leaf.id+1+" "+(leaf.par().id+1));
			System.out.println(leaf.id+1+" "+(cent.id+1));
		}
	}

	static void bfs(Node from, Node[] nodes) {
		for (Node nn:nodes) nn.dist=-1;
		from.dist=0;
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		bfs.add(from);
		while (!bfs.isEmpty()) {
			Node next=bfs.remove();
			for (Node nn:next.adjO) {
				if (nn.dist==-1) {
					nn.dist=next.dist+1;
					bfs.add(nn);
				}
			}
		}
	}
	
	static class Node {
		int subtreeSize, dist, dist2, id;
		Node par;
		ArrayList<Node> adj=new ArrayList<>();
		ArrayList<Node> adjO=new ArrayList<>();
		
		public Node(int id) {
			this.id=id;
		}
		
		void dfs(Node from) {
			this.par=from;
			if (from!=null) adj.remove(from);
			for (Node nn:adj) {
				nn.dfs(this);
				subtreeSize+=nn.subtreeSize;
			}
			subtreeSize++;
		}
		
		int biggest(int n) {
			int ans=n-subtreeSize;
			for (Node nn:adj) ans=Math.max(ans, nn.subtreeSize);
			return ans;
		}
		
		Node par() {
			return adjO.get(0);
		}
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
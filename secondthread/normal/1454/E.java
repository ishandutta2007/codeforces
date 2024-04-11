import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
1
3
1 2
2 3
1 3

1
4
1 2
2 3
3 4
4 2
 */
public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node(i);
			
			for (int i=0; i<n; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].adj.add(nodes[a]);
			}
			nodes[0].dfs(null, new ArrayDeque<>());
			DisjointSet dj=new DisjointSet(n);
			long nPaths=n*(long)(n-1)/2*2;
			for (Node nn:nodes)
				for (Node adj:nn.adj)
					if (!adj.inCycle)
						dj.union(nn.id, adj.id);
			boolean[] processed=new boolean[n];
			for (int i=0; i<n; i++) {
				int at=dj.find(i);
				if (processed[at]) continue;
				processed[at]=true;
//				System.out.println("Processing "+at+" "+dj.size[at]+" "+nodes[i].inCycle);
				nPaths-=dj.size[at]*(long)(dj.size[at]-1)/2;
			}
			System.out.println(nPaths);
		}
	}
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		boolean inCycle=false;
		boolean visited=false;
		Node par;
		int subtreeSize, id;
		
		public Node(int id) {
			this.id=id;
		}
		
		public void dfs(Node from, ArrayDeque<Node> stk) {
//			System.out.println("DFSing in "+id+" "+from);
			if (visited) {
				if (inCycle) return;
				//pop from cycle
				while (true) {
					Node next=stk.removeLast();
					next.inCycle=true;
//					System.out.println("Marking "+next+" as being in a cycle");
					if (next==this) {
						break;
					}
				}
				return;
			}
			visited=true;
			stk.addLast(this);
			for (Node nn:adj) if (nn!=from) nn.dfs(this, stk);
			if (!stk.isEmpty()) stk.removeLast();
		}
		public String toString() {
			return ""+id;
		}
	}

	static class DisjointSet {
		int[] s;
		int[] size;
		
		public DisjointSet(int n) {
			Arrays.fill(s = new int[n], -1);
			size=new int[n];
			Arrays.fill(size, 1);
		}
		
		public int find(int i) {
			return s[i] < 0 ? i : (s[i] = find(s[i]));
		}
		
		public boolean union(int a, int b) {
			if ((a = find(a)) == (b = find(b))) return false;
			if(s[a] == s[b]) s[a]--;
			if(s[a] <= s[b]) {
				s[b] = a; 
				size[a]+=size[b];
			}
			else {
				s[a] = b;
				size[b]+=size[a];
			}
			return true;
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
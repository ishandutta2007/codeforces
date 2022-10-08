import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/*
1
5
1
1 2
1 3
3 4
3 5
 */
public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), special=fs.nextInt()-1;
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node(i);
			for (int i=1; i<n; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].adj.add(nodes[a]);
			}
			boolean firstTurn=true;
			if (nodes[special].adj.size()<=1) {
				System.out.println("Ayush");
				continue;
			}
			outer:while (true) {
				for (Node nn:nodes) {
					if (nn.removed) continue;
					if (nn.adj.size()>1) continue;
					if (nn.adj.size()==1 && nn.adj.get(0).index==special && nodes[special].adj.size()==2) {
						//would lose next turn
						continue;
					}
					nn.removed=true;
					if (nn.adj.size()!=0) nn.adj.get(0).removeAdj(nn);
					firstTurn^=true;
					continue outer;
				}
				break;
			}
			if (firstTurn) {
				System.out.println("Ashish");
			}
			else {
				System.out.println("Ayush");
			}
		}
	}

	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int index;
		boolean removed=false;
		public Node(int index) {
			this.index=index;
		}
		
		public void removeAdj(Node x) {
			adj.remove(x);
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
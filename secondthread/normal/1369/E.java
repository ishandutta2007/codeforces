import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt();
		int[] values=fs.readArray(n);
		Node[] nodes=new Node[n];
		Edge[] edges=new Edge[m];
		for (int i=0; i<n; i++) nodes[i]=new Node(i, values[i]);
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].degree++;
			nodes[b].degree++;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
			edges[i]=new Edge(nodes[a], nodes[b], i);
		}
		
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		ArrayList<Integer> ans=new ArrayList<>();
		for (Node nn:nodes) {
			if (nn.degree<=nn.number) {
				bfs.add(nn);
				nn.added=true;
			}
		}
		while (!bfs.isEmpty()) {
			Node next=bfs.remove();
			ans.add(next.index);
			for (Node nn:next.adj) {
				if (nn.added) continue;
				nn.degree--;
				if (nn.degree<=nn.number) {
					bfs.add(nn);
					nn.added=true;
				}
			}
		}
		
		//TODO: printwriter
		PrintWriter out=new PrintWriter(System.out);
		if (ans.size()==n) {
			out.println("ALIVE");
			for (int i=0; i<ans.size(); i++) {
				nodes[ans.get(i)].removeSpot=i;
			}
			Arrays.sort(edges);
			for (int i=m-1; i>=0; i--)
				out.print(edges[i].index+1+" ");
			out.println();
		}
		else {
			out.println("DEAD");
		}
		out.close();
	}
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int number, degree, index;
		int removeSpot;
		boolean added=false;
		public Node(int index, int number) {
			this.index=index;
			this.number=number;
		}
	}
	
	static class Edge implements Comparable<Edge> {
		Node a, b;
		int index;
		
		public Edge(Node a, Node b, int index) {
			this.a=a;
			this.b=b;
			this.index=index;
		}

		int val() {
			return Math.min(a.removeSpot, b.removeSpot);
		}
		
		public int compareTo(Edge o) {
			return Integer.compare(val(), o.val());
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
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
		DisjointSet dj=new DisjointSet(n);
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(i);
		for (int i=0; i<m; i++) {
			int first=fs.nextInt()-1, second=fs.nextInt()-1;
			if (dj.union(first, second)) {
				Edge e=new Edge(nodes[first], nodes[second]);
				nodes[first].adj.add(e);
				nodes[second].adj.add(e);
			}
		}
		int nQ=fs.nextInt();
		Node[][] takenInQuery=new Node[nQ][];
		for (int qq=0; qq<nQ; qq++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			bfs(nodes[a], nodes);
			takenInQuery[qq]=new Node[nodes[b].dist+1];
			Node at=nodes[b];
			while (at!=null) {
				takenInQuery[qq][at.dist]=at;
				if (at.eFrom!=null) at.eFrom.count++;
				at=at.from;
			}
		}
		int finalAns=0;
		for (Node nn:nodes) {
			int eCount=0;
			for (Edge e:nn.adj) if (e.count%2!=0) eCount++;
			if (eCount%2!=0) finalAns++;
		}
		PrintWriter out=new PrintWriter(System.out);
		if (finalAns==0) {
			out.println("YES");
			for (int q=0; q<nQ; q++) {
				out.println(takenInQuery[q].length);
				for (Node nn:takenInQuery[q]) {
					out.print(nn.id+1+" ");
				}
				out.println();
			}
		}
		else {
			out.println("NO");
			out.println(finalAns/2);
		}
		out.close();
	}
	
	static class Node {
		ArrayList<Edge> adj=new ArrayList<>();
		int dist;
		Node from;
		Edge eFrom;
		int id;
		public Node(int id) {
			this.id=id;
		}
	}
	static class Edge {
		int count;
		Node a,b;
		public Edge(Node a, Node b) {
			this.a=a;
			this.b=b;
		}
		Node o(Node me) {
			return a==me?b:a;
		}
	}
	
	static void bfs(Node from, Node[] nodes) {
		for (Node nn:nodes) {
			nn.dist=-1;
			nn.from=null;
			nn.eFrom=null;
		}
		from.dist=0;
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		bfs.add(from);
		while (!bfs.isEmpty()) {
			Node next=bfs.remove();
			for (Edge e:next.adj) {
				Node o=e.o(next);
				if (o.dist!=-1) continue;
				o.dist=next.dist+1;
				o.from=next;
				o.eFrom=e;
				bfs.add(o);
			}
		}
	}

	static class DisjointSet {
		int[] s;
		
		public DisjointSet(int n) {
			Arrays.fill(s = new int[n], -1);
		}
		
		public int find(int i) {
			return s[i] < 0 ? i : (s[i] = find(s[i]));
		}
		
		public boolean union(int a, int b) {
			if ((a = find(a)) == (b = find(b))) return false;
			if(s[a] == s[b]) s[a]--;
			if(s[a] <= s[b]) s[b] = a; 
			else s[a] = b;
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
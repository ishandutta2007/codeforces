import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;

/*
5
13 11
11 1
3 5
17 1
9 27

 */
public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Edge[] edges=new Edge[n];
		for (int i=0; i<n; i++) edges[i]=new Edge(fs.nextInt(), fs.nextInt(), 2*i+1, 2*i+2);
		for (int answer=20; answer>=0; answer--) {
			if (tryAnswer(edges, answer)) return;
		}
		throw null;
	}
	
	static boolean tryAnswer(Edge[] edges, int answer) {
		int mask=(1<<answer)-1;
		Node[] nodes=new Node[1<<20];
		Node start=null;
		for (Edge e:edges) {
			if (nodes[e.a & mask]==null) {
				Node toAdd=start=new Node();
				nodes[e.a & mask]=toAdd;
			}
			if (nodes[e.b & mask]==null) {
				Node toAdd=start=new Node();
				nodes[e.b & mask]=toAdd;
			}
		}
		for (Edge e:edges) {
			e.hit=false;
			e.n1=nodes[e.a&mask];
			e.n2=nodes[e.b&mask];
			e.n1.adjacent.add(e);
			e.n2.adjacent.add(e);
		}
		for (Node nn:nodes) {
			if (nn!=null && nn.adjacent.size()%2!=0) return false;
		}
		ArrayDeque<Edge> ans=new ArrayDeque<>();
		start.dfs(ans);
		if (ans.size()!=edges.length) return false;
		PrintWriter out=new PrintWriter(System.out);
		out.println(answer);
		while (!ans.isEmpty()) {
			Edge cur=ans.removeLast();
			if (cur.cameFrom==cur.n2) {
				out.print(cur.index2+" "+cur.index1+" ");
			}
			else {
				out.print(cur.index1+" "+cur.index2+" ");
			}
		}
		out.println();
		out.close();
		return true;
	}
	
	static class Edge {
		int a, b;
		int index1, index2;
		Node n1, n2;
		boolean hit;
		Node cameFrom;
		
		public Edge(int a, int b, int index1, int index2) {
			this.a=a;
			this.b=b;
			this.index1=index1;
			this.index2=index2;
		}
		
		public Node other(Node me) {
			return me==n1?n2:n1;
		}
	}
	
	static class Node {
		ArrayList<Edge> adjacent=new ArrayList<>();
		int index=0;
		
		public void dfs(ArrayDeque<Edge> answer) {
			while (index<adjacent.size()) {
				Edge next=adjacent.get(index);
				if (!next.hit) {
					next.hit=true;
					next.cameFrom=this;
					next.other(this).dfs(answer);
					answer.addLast(next);
				}
				index++;
			}
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
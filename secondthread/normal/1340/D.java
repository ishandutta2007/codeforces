import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {
	
	static ArrayList<State> path=new ArrayList<>();
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(i);
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			Edge e=new Edge(nodes[a], nodes[b]);
			nodes[a].edges.add(e);
			nodes[b].edges.add(e);
		}
		nodes[0].dfs0(null);
		nodes[0].dfs1();
		PrintWriter out=new PrintWriter(System.out);
		//TODO: fast output
		out.println(path.size());
		for (State s:path) {
			out.println(s);
		}
		out.close();
	}
	
	static class Node {
		ArrayList<Edge> edges=new ArrayList<>();
		Edge parEdge;
		int index;
		public Node(int index) {
			this.index=index+1;
		}
		
		public void dfs0(Edge parEdge) {
			if (parEdge!=null)
				edges.remove(parEdge);
			this.parEdge=parEdge;
			int parEdgeColor=parEdge==null?0:parEdge.color;
			int nextFreeSmaller=parEdgeColor-1;
			int biggerIndex=parEdgeColor+1;
			for (Edge e:edges) {
				if (nextFreeSmaller>0) {
					e.color=nextFreeSmaller;
					nextFreeSmaller--;
					e.other(this).dfs0(e);
				}
				else {
					e.color=biggerIndex;
					biggerIndex++;
					e.other(this).dfs0(e);
				}
			}
		}
		
		public void dfs1() {
			int time=parEdge==null?0:parEdge.color;
			int parEdgeColor=time;
			path.add(new State(this, time));
			Collections.sort(edges);
			int startIndex=0;
			while (startIndex<edges.size() && edges.get(startIndex).color<time) {
				startIndex++;
			}
			for (int i=startIndex; i<edges.size(); i++) {
				Edge next=edges.get(i);
				next.other(this).dfs1();
				time=next.color;
				path.add(new State(this, time));
			}
			if (parEdge==null) {
				return;
			}
			int setToTime=edges.size()==0?parEdgeColor-1:Math.min(parEdgeColor-1, edges.get(0).color-1);
			time=setToTime;
			path.add(new State(this, time));
			for (int i=0; i<startIndex; i++) {
				Edge next=edges.get(i);
				next.other(this).dfs1();
				time=next.color;
				path.add(new State(this, time));
			}
		}
	}
	
	static class Edge implements Comparable<Edge> {
		Node a, b;
		int color=-1;
		public Edge(Node a, Node b) {
			this.a=a;
			this.b=b;
		}
		Node other(Node c) {
			return c==a?b:a;
		}
		
		public int compareTo(Edge o) {
			return Integer.compare(color, o.color);
		}
	}
	
	static class State {
		Node at;
		int time;
		public State(Node at, int time) {
			this.at=at;
			this.time=time;
		}
		
		public String toString() {
			return at.index+" "+time;
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
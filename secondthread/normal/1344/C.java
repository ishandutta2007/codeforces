import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
3 2
2 1
2 3
 */
public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(i);
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].edgesTo.add(nodes[b]);
			nodes[b].edgesFrom.add(nodes[a]);
			nodes[b].indegree++;
		}
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		for (Node nn:nodes) if (nn.indegree==0) bfs.add(nn);
		while (!bfs.isEmpty()) {
			Node next=bfs.remove();
			for (Node nn:next.edgesTo) {
				nn.indegree--;
				if (nn.indegree==0) bfs.add(nn);
			}
		}
		for (Node nn:nodes) {
			if (nn.indegree!=0) {
				System.out.println(-1);
				return;
			}
		}
		
		PrintWriter out=new PrintWriter(System.out);
		StringBuilder sb=new StringBuilder();
		int ans=0;
		for (Node nn:nodes) {
			nn.go();
			if (nn.madeA) {
				sb.append('A');
				ans++;
			}
			else {
				sb.append('E');
			}
		}
		out.println(ans);
		out.println(sb);
		out.close();
	}
	
	static class Node {
		boolean madeA=false;
		boolean madeE=false;
		boolean markedForward=false;
		boolean markedBackwards=false;
		
		int indegree=0;
		
		int index;
		ArrayList<Node> edgesTo=new ArrayList<>();
		ArrayList<Node> edgesFrom=new ArrayList<>();
		
		public Node (int index) {
			this.index=index;
		}
		
		public void markForward() {
			if (markedForward) return;
			markedForward=true;
			for (Node nn:edgesTo)
				nn.markForward();
		}
		
		public void markBackwards() {
			if (markedBackwards) return;
			markedBackwards=true;
			for (Node nn:edgesFrom) {
				nn.markBackwards();
			}
		}
		
		public void go() {
			if (markedForward||markedBackwards) {
				madeE=true;
				markForward();
				markBackwards();
			}
			else {
				madeA=true;
				markForward();
				markBackwards();
			}
		}
		
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
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
		long nextLong() {
			return Long.parseLong(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}
	
	public void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

}
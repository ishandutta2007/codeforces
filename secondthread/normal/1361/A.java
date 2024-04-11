import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(i);
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		for (int i=0; i<n; i++) nodes[i].color=fs.nextInt();
		Arrays.sort(nodes);
		for (Node nn:nodes) {
			int mex=nn.getMex();
			if (mex!=nn.color) {
				System.out.println(-1);
				return;
			}
			nn.colored=true;
		}
		PrintWriter out=new PrintWriter(System.out);
		for (Node nn:nodes) out.print(nn.index+1+" ");
		out.println();
		out.close();
	}
	
	static class Node implements Comparable<Node> {
		ArrayList<Node> adj=new ArrayList<>();
		int color, index;
		boolean colored=false;
		
		public Node(int index) {
			this.index=index;
		}
		
		int getMex() {
			Collections.sort(adj);
			int ans=1;
			for (Node nn:adj)
				if (nn.colored && nn.color==ans) ans++;
			return ans;
		}
		
		public int compareTo(Node o) {
			return Integer.compare(color, o.color);
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
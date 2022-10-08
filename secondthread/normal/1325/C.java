import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	static int[] deg;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		deg=new int[n];
		ArrayList<Edge>[] edges=new ArrayList[n];
		Edge[] allEdges=new Edge[n-1];
		for (int i=0; i<n; i++) edges[i]=new ArrayList<>();
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			Edge e=new Edge(a, b);
			edges[a].add(e);
			edges[b].add(e);
			deg[a]++;
			deg[b]++;
			allEdges[i-1]=e;
		}
		PrintWriter out=new PrintWriter(System.out);
		if (n<4) {
			for (int i=0; i+1<n; i++)
				out.print(i+" ");
			out.println();
			out.close();
			return;
		}
		//check if chain
		ArrayList<Integer> leaves=new ArrayList<>();
		for (int i=0; i<n; i++) if (deg[i]==1) leaves.add(i);
		if (leaves.size()==2) {
			for (int i=0; i+1<n; i++)
				out.print(i+" ");
			out.println();
			out.close();
		}
		else {
			Edge[] clone=allEdges.clone();
			Arrays.sort(clone);
			for (int i=0; i+1<n; i++) clone[i].value=i;
			for (Edge e:allEdges) out.print(e.value+" ");
			out.println();
			out.close();
		}
	}
	
	static class Edge implements Comparable<Edge> {
		int a, b;
		int value=-1;
		public Edge(int a, int b) {
			this.a=a;
			this.b=b;
		}
		
		public int compareTo(Edge o) {
			return Integer.compare(Math.min(deg[a], deg[b]), Math.min(deg[o.a], deg[o.b]));
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
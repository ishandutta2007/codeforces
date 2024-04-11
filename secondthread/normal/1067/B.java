import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {
	static int[] heights;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		heights=new int[n];
		ArrayList<Integer>[] adj=new ArrayList[n];
		for (int i=0; i<n; i++) adj[i]=new ArrayList<>();
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		int[] from0=bfs(0, adj);
		int max=0;
		for (int i=0; i<n; i++)
			if (from0[i]>from0[max])
				max=i;
		int[] fromMax1=bfs(max, adj);
		int max2=0;
		for (int i=0; i<n; i++)
			if (fromMax1[i]>fromMax1[max2])
				max2=i;
		int[] fromMax2=bfs(max2, adj);
//		System.out.println("from 1 max: "+Arrays.toString(fromMax1));
//		System.out.println("from 1 max: "+Arrays.toString(fromMax2));
		
		int centroid=0;
		for (int i=0; i<n; i++) {
			if (Math.max(fromMax1[i], fromMax2[i])<Math.max(fromMax1[centroid], fromMax2[centroid])) {
				centroid=i;
			}
		}
		if (fromMax1[centroid]!=fromMax2[centroid]||fromMax1[centroid]!=k) {
			System.out.println("No");
			return;
		}
		heightDfs(adj, heights, centroid, -1);
		boolean valid=verify(adj, centroid, -1, k);
		System.out.println(valid?"Yes":"No");
		
	}
	
	static boolean verify(ArrayList<Integer>[] adj, int node, int par, int k) {
		if (k==0) {
			return (adj[node].size()==1);
		}
		if (adj[node].size()+(par==-1?1:0)<4) {
			return false;
		}
		if (heights[node]!=k) {
			return false;
		}
		for (int i:adj[node]) {
			if (i==par)
				continue;
			if (!verify(adj, i, node, k-1))
				return false;
		}
		return true;
	}
	
	static void heightDfs(ArrayList<Integer>[] adj, int[] heights, int node, int par) {
		int height=0;
		for (int i:adj[node]) {
			if (i==par)
				continue;
			heightDfs(adj, heights, i, node);
			height=Math.max(height, heights[i]+1);
		}
		heights[node]=height;
	}
	
	static int[] bfs(int from, ArrayList<Integer>[] adj) {
		int n=adj.length;
		int[] dist=new int[n];
		Arrays.fill(dist, -1);
		ArrayDeque<Integer> bfs=new ArrayDeque<>();
		dist[from]=0;
		bfs.add(from);
		while (!bfs.isEmpty()) {
			int next=bfs.remove();
			for (int i:adj[next]) {
				if (dist[i]!=-1)
					continue;
				dist[i]=dist[next]+1;
				bfs.add(i);
			}
		}
		return dist;
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
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class B {
	
	public static void main(String[] args) throws InterruptedException {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node();
		for (int i=0; i<2*k; i++) nodes[fs.nextInt()-1].special=true;
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		nodes[0].dfs0(null);
		nodes[0].dfs2(0);
		System.out.println(total);
	}
	
	static long total=0;
	
	static class Node {
		boolean special;
		int subtreeSum=0;
		ArrayList<Node> adj=new ArrayList<>();
		
		void dfs0(Node par) {
			if (par!=null) adj.remove(par);
			for (Node nn:adj) {
				nn.dfs0(this);
				subtreeSum+=nn.subtreeSum;
			}
			if (special) subtreeSum++;
		}
		
		public void dfs2(int outside) {
			total+=Math.min(outside, subtreeSum);
			for (Node nn:adj) {
				nn.dfs2(outside+subtreeSum-nn.subtreeSum);
			}
		}
	}
	
	void sort(int[] a) {
		ArrayList<Integer> list=new ArrayList<>();
		for (int i:a) list.add(i);
		Collections.sort(list);
		for (int i=0; i<a.length; i++) a[i]=list.get(i);
	}
	
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
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
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}

}
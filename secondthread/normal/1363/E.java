import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node(i);
		for (int i=0; i<n; i++) {
			int a=fs.nextInt(), b=fs.nextInt(), c=fs.nextInt();
			nodes[i].nodeCost=a;
			nodes[i].startAs=b;
			nodes[i].wantToBe=c;
		}
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		nodes[0].dfs0(null, Long.MAX_VALUE);
		
		int ans=nodes[0].dfs1();
		if (ans!=0) {
			System.out.println(-1);
		}
		else {
			System.out.println(totalCost);
		}
		
	}

	static long totalCost=0;
	
	static class Node {
		long nodeCost;
		int startAs, wantToBe;
		
		int index;
		ArrayList<Node> adj=new ArrayList<>();
		
		public Node(int index) {
			this.index=index;
		}
		
		public void dfs0(Node par, long myCost) {
			if (par!=null) adj.remove(par);
			nodeCost=Math.min(nodeCost, myCost);
			for (Node nn:adj) nn.dfs0(this, nodeCost);
		}
		
		public int dfs1() {
			int counter=startAs-wantToBe;
			for (Node nn:adj) {
				int res=nn.dfs1();
				if (Integer.signum(res)!=Integer.signum(counter)) {
					totalCost+=nodeCost*Math.min(Math.abs(res), Math.abs(counter))*2;
				}
				counter+=res;
			}
			return counter;
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
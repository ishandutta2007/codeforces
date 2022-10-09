import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) throws InterruptedException {
		Thread t=new Thread(null, null, "T", 1<<28) {
			public void run() {
				new C(null);
			}
		};
		t.start();
		t.join();
	}
	
	public C(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int x=fs.nextInt()-1;
		int y=fs.nextInt()-1;
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node();
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1;
			int b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		nodes[y].isMarked=true;
		nodes[x].dfs(null);
		long nChoose2=((long)n*(long)(n-1));
		long invalid1=nodes[x].getInvalid1();
		long invalid2=nodes[y].numChildren;
//		System.out.println(invalid1*invalid2);
		System.out.println(nChoose2-invalid1*invalid2);
	}
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int numChildren=0;
		boolean hasMarked=false;
		boolean isMarked=false;
		
		public void dfs(Node parent) {
			numChildren=1;
			hasMarked=isMarked;
			for (Node n:adj) {
				if (n==parent) {
					continue;
				}
				n.dfs(this);
				numChildren+=n.numChildren;
				hasMarked|=n.hasMarked;
			}
		}
		
		public long getInvalid1() {
			long total=numChildren;
			for (Node n:adj) {
				if (n.hasMarked)
					total-=n.numChildren;
			}
			return total;
		}
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
		
		public long[] readArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
	}
	
}
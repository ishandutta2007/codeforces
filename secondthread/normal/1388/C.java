import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/*
1
2 10000
0 5
5 5
1 2

ans: YES

1
1 1010
5
6

1
1 1010
5
-5

1
4 4
1 1 1 1
4 1 -3 -1
1 2
1 3
1 4

1
3 13
3 3 7
13 1 4
1 2
1 3
 */
public class C2 {
	
	public static void main(String[] args) throws InterruptedException {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			works=true;
			int n=fs.nextInt(); fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n;i++) nodes[i]=new Node(fs.nextInt());
			for (int i=0; i<n; i++) nodes[i].hIndex=fs.nextInt();
			for (int i=1; i<n; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].adj.add(nodes[a]);
			}
			nodes[0].dfs(null);
			System.out.println(works?"YES":"NO");
			
		}
	}
	
	static boolean works=true;
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int hIndex;
		long subtreeSize;
		
		public Node(int pop) {
			this.subtreeSize=pop;
		}
		
		public void dfs(Node par) {
			if (par!=null) adj.remove(par);
			long happyRequired=0;
			for (Node nn:adj) {
				nn.dfs(this);
				subtreeSize+=nn.subtreeSize;
				happyRequired+=nn.minHappyInSubtree();
			}
			//10 - (5-10) = 15
			long sadInKids=(subtreeSize-happyRequired);
			long minHIndex=happyRequired-sadInKids;
			//too few happy people to distribute
			if (minHIndex>hIndex) works=false;
			if ((subtreeSize%2==0) != (hIndex%2==0)) works=false;
			//invalid happy number
			if (hIndex>subtreeSize || hIndex <-subtreeSize) works=false;
		}
		
		long minHappyInSubtree() {
			long defaultAns=(subtreeSize+hIndex)/2;
			//happy - sad = hIndex
			//happy + sad = subtreesize
			//happy = (hIndex + subtreeSize)/2
			return Math.min(subtreeSize, Math.max(0, defaultAns));
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
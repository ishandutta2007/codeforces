import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++)
			nodes[i]=new Node(i);
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].canReach.add(nodes[b]);
			nodes[a].undefinedOutDegree++;
			nodes[b].canReachMe.add(nodes[a]);
		}
		int s=fs.nextInt()-1, t=fs.nextInt()-1;
		ArrayList<Node> toProcess=new ArrayList<>();
		toProcess.add(nodes[t]);
		nodes[t].defined=false;
		nodes[t].distanceToEnd=0;
		TreeSet<Node> ts=new TreeSet<>();
		int procIndex=0;
		while (procIndex<toProcess.size()||!ts.isEmpty()) {
			while (procIndex<toProcess.size()) {
				toProcess.get(procIndex).solve(toProcess, ts);
				procIndex++;
			}
			for (Node nn:ts)
				toProcess.add(nn);
			ts.clear();
		}
		System.out.println(nodes[s].distanceToEnd);
	}
	
	static class Node implements Comparable<Node> {
		boolean defined=false;
		int distanceToEnd=-1;
		ArrayList<Node> canReach=new ArrayList<>();
		ArrayList<Node> canReachMe=new ArrayList<>();
		int undefinedOutDegree=0;
		int index;
		
		public Node(int index) {
			this.index=index;
		}
		
		void solve(ArrayList<Node> toProcess, TreeSet<Node> possiblyReachable) {
			if (defined) return;
			defined=true;
			int smallestReachable=Integer.MAX_VALUE, biggestReachable=0;
			boolean canReachUndef=false;
			for (Node n:canReach) {
				if (!n.defined) canReachUndef=true;
				else {
					smallestReachable=Math.min(smallestReachable, n.distanceToEnd);
					biggestReachable=Math.max(biggestReachable, n.distanceToEnd);
				}
			}
			if (smallestReachable!=Integer.MAX_VALUE) {
				if (!canReachUndef)
					distanceToEnd=Math.min(biggestReachable, smallestReachable+1);
				else
					distanceToEnd=smallestReachable+1;
			}
			for (Node n:canReachMe) {
				n.undefinedOutDegree--;
				if (n.undefinedOutDegree==0)
					toProcess.add(n);
				else
					possiblyReachable.add(n);
			}
		}
		
		public int compareTo(Node o) {
			return Integer.compare(index, o.index);
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
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}
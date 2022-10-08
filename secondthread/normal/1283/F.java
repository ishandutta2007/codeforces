import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) {
			nodes[i]=new Node(i, i);
		}
		int[] parOrder=new int[n-1];
		for (int i=0; i+1<n; i++) {
			int next=fs.nextInt()-1;
			nodes[next].timesUsed++;
			parOrder[i]=next;
		}
		PriorityQueue<Node> leaves=new PriorityQueue<>();
		for (Node nn:nodes)
			if (nn.timesUsed==0) leaves.add(nn);
		ArrayList<Integer> firstEdges=new ArrayList<>(), secondEdges=new ArrayList<>();
		for (int ind=n-2; ind>=0; ind--) {
			Node nextLeaf=leaves.remove();
			Node nextPar=nodes[parOrder[ind]];
			nextPar.maxSubtreeVal=Math.max(nextPar.maxSubtreeVal, nextLeaf.maxSubtreeVal);
			nextPar.children.add(nextLeaf);
			nextPar.timesUsed--;
			if (nextPar.timesUsed==0) leaves.add(nextPar);
			firstEdges.add(nextPar.index+1);
			secondEdges.add(nextLeaf.index+1);
		}
		PrintWriter out=new PrintWriter(System.out);
		out.println(leaves.peek().index+1);
		for (int i=0; i<firstEdges.size(); i++)
			out.println(firstEdges.get(i)+" "+secondEdges.get(i));
		out.close();
	}
	
	static class Node implements Comparable<Node> {
		int maxSubtreeVal, index;
		int timesUsed=0;
		ArrayList<Node> children=new ArrayList<>();
		
		public Node(int maxSubtreeVal, int index) {
			this.index=index;
			this.maxSubtreeVal=maxSubtreeVal;
		}
		
		public int compareTo(Node o) {
			return Integer.compare(maxSubtreeVal, o.maxSubtreeVal);
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

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}

		public long[] readLongArray(int n) {
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
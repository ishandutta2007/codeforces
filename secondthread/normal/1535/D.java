import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int k=fs.nextInt();
		char[] a=fs.next().toCharArray();
		allNodes=new Node[1<<k];
		Node tree=new Node(k-1, 1, a, null);
		int nQueries=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQueries; qq++) {
			int index=fs.nextInt();
			char to=fs.next().toCharArray()[0];
			a[index-1]=to;
			allNodes[allNodes.length-index].set(to);
			out.println(tree.nPossibleWinners);
		}
		out.close();
	}
	
	static Node[] allNodes;
	
	static class Node {
		Node lChild, rChild, par;
		int nPossibleWinners=0;
		int id, depth;
		char myChar;
		
		public Node(int depth, int id, char[] a, Node par) {
			this.id=id;
			this.depth=depth;
			allNodes[id]=this;
			this.par=par;
			myChar=a[a.length-id];
			if (depth==0) {
				recalc();
				return;
			}
			lChild=new Node(depth-1, id*2, a, this);
			rChild=new Node(depth-1, id*2+1, a, this);
			recalc();
		}
		
		public void recalc() {
			if (lChild==null) {
				nPossibleWinners = myChar=='?'?2:1;
				return;
			}
			if (myChar=='?') {
				nPossibleWinners = lChild.nPossibleWinners+ rChild.nPossibleWinners;
			}
			else if (myChar=='1') {
				nPossibleWinners = lChild.nPossibleWinners;
			}
			else {
				nPossibleWinners = rChild.nPossibleWinners;
			}
		}
		
		public void recalcUp() {
			recalc();
			if (par != null)
				par.recalcUp();
		}
		
		public void set(char to) {
			myChar=to;
			recalcUp();
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
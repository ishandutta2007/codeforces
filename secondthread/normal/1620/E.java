import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int q=fs.nextInt();
		TreeSet<Node> nodes=new TreeSet<>();
		ArrayList<Node> roots=new ArrayList<>();
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<q; qq++) {
			int type=fs.nextInt();
			if (type==1) {
				int val=fs.nextInt();
				Node me=getIfExists(nodes, val);
				roots.add(me);
			}
			else {
				int fromI=fs.nextInt();
				int toI=fs.nextInt();
				if (fromI==toI) continue;
				Node newFrom=getIfExists(nodes, fromI);
				Node newTo=getIfExists(nodes, toI);
				newFrom.par=newTo;
			}
		}
		for (Node nn:roots) {
			out.print(nn.getPar().value+" ");
		}
		out.println();
		out.close();
	}
	
	static Node getIfExists(TreeSet<Node> nodes, int val) {
		Node test=new Node(val);
		if (nodes.contains(test)) {
			Node toReturn=nodes.ceiling(test);
			if (toReturn.par!=null) {
				nodes.remove(toReturn);
				nodes.add(test);
				return test;
			}
			return toReturn;
		}
		nodes.add(test);
		return test; 
	}
	
	
	static class Node implements Comparable<Node> {
		Node par;
		int value;
		
		public Node(int value) {
			this.value=value;
		}
		
		public int compareTo(Node o) {
			return Integer.compare(value, o.value);
		}
		Node getPar() {
			if (par==null) return this;
			return par=par.getPar();
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
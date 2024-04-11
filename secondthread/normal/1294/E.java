import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeSet;
/*

 */
public class D {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int h=fs.nextInt(), w=fs.nextInt();
		int[][] mat=new int[w][h];
		for (int y=0; y<h; y++) {
			for (int x=0; x<w; x++) mat[x][y]=fs.nextInt()-1;
		}
		
		int moves=w*h;
		for (int x=0; x<w; x++) {
//			System.out.println("Looking at x: "+x);
			int[] counts=new int[h];
			for (int y=0; y<h; y++) {
				if (mat[x][y]%w!=x) continue;
				int val=mat[x][y]/w;
				if (val>=h) continue;
				int at=(y-val+h)%h;
//				System.out.println("Got val "+val+" belongs at "+at);
				
				counts[at]++;
			}
			int max=counts[0];
			for (int i=0; i<h; i++) {
//				System.out.println(i+" "+counts[i]);
				max=Math.max(max, counts[i]-i);
			}
			moves-=max;
		}
		System.out.println(moves);
		
		
	}
	 
	static class Node implements Comparable<Node> {
		int cost, size, id;
		ArrayList<Node> adj=new ArrayList<>();
		boolean valid;
		
		public Node(int cost, int id) {
			this.cost=cost;
			this.id=id;
		}
		
		public void preDFS(Node par) {
			if (par!=null) adj.remove(par);
			size=1;
			for (Node n:adj) {
				n.preDFS(this);
				size+=n.size;
			}
			
			Collections.sort(adj);
		}
		
		public int compareTo(Node o) {
			return -Integer.compare(size, o.size);
		}
		
		TreeSet<Node> getSmallestToBuy() {
			if (adj.isEmpty()) {
				TreeSet<Node> toReturn=new TreeSet<>((a, b)-> 
				{
					if (a.cost!=b.cost)
						return Integer.compare(a.cost, b.cost);
					return Integer.compare(a.id, b.id);
				}
				);
				toReturn.add(this);
				return toReturn;
			}
			TreeSet<Node> toReturn=adj.get(0).getSmallestToBuy();
			for (int i=1; i<adj.size(); i++) {
				TreeSet<Node> toAdd=adj.get(i).getSmallestToBuy();
				toReturn.addAll(toAdd);
			}
			
			if (toReturn.last().cost>cost) {
				toReturn.remove(toReturn.last());
				toReturn.add(this);
			}
			return toReturn;
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
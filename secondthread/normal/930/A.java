

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.StringTokenizer;

public class A {

	public static void solve(FastScanner fs) {	
			int n=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++)
				nodes[i]=new Node();
			for (int i=1; i<n; i++) {
				int parent=fs.nextInt()-1;
				nodes[parent].children.add(nodes[i]);
				nodes[i].parent=nodes[parent];
			}
			
			nodes[0].dfs();
			int ans=nodes[0].getValidTimes().set.size();
			/*for (int i:nodes[0].getValidTimes().set)
				System.out.println(i);*/
			System.out.println(ans);
	}
	

	static class Node implements Comparable<Node> {
		Node parent;
		ArrayList<Node> children=new ArrayList<>();
		int size=1;

		private void dfs() {
			for (Node n:children) {
				n.dfs();
				size+=n.size;
			}
			Collections.sort(children);
		}
		
		private Pair getValidTimes() {
			if (children.size()==0) {
				Pair toReturn=new Pair(new HashSet<>(), 0);
				toReturn.add(0);
				return toReturn;
			}
			Pair toReturn=children.get(0).getValidTimes();
			toReturn.offset++;
			toReturn.add(0);
			for (int i=1; i<children.size(); i++) {
				Pair toCombine=children.get(i).getValidTimes();
				toCombine.offset++;
				toReturn.addAll(toCombine);
			}
			return toReturn;
		}

		public int compareTo(Node o) {
			return size-o.size;
		}
		
		
	}
	
	static class Pair {
		HashSet<Integer> set;
		int offset;
		public Pair(HashSet<Integer> set, int offset) {
			this.set=set;
			this.offset=offset;
		}
		public void add(int i) {
			i-=offset;
			set.add(i);
		}
		
		/*private boolean contains(int i) {
			i-=offset;
			return set.contains(i);
		}*/
		
		public void addAll(Pair other) {
			for (int i:other.set) {
//				System.out.println(i+" "+other.offset);
				i+=other.offset;
				i-=offset;
				if (set.contains(i)) {
					set.remove(i);
				}
				else {
					set.add(i);
				}
			}
		}
	}
	
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}
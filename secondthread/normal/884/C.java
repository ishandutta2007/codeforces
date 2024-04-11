import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) {
			nodes[i]=new Node();
		}
		for (int i=0; i<n; i++) {
			nodes[i].setChild(nodes[fs.nextInt()-1]);
		}
		ArrayList<Integer> groups=new ArrayList<>();
		for (int i=0; i<n; i++) {
			if (!nodes[i].visited) {
				groups.add(nodes[i].traverse(groups.size()));
			}
		}
		Collections.sort(groups);
		if (groups.size()==1) {
			System.out.println(groups.get(0)*(long)groups.get(0));
			return;
		}
		int total=groups.remove(groups.size()-1);
		total+=groups.remove(groups.size()-1);
		groups.add(total);
		long ans=0;
		for (int i:groups) {
			ans+=i*(long)i;
		}
		System.out.println(ans);
	}
	
	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		
		public FastScanner() {
			br=new BufferedReader(new InputStreamReader(System.in));
			st=new StringTokenizer("");
		}
		
		public String next() {
			if (st.hasMoreTokens()) {
				return st.nextToken();
			}
			while (!st.hasMoreTokens()) {
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			
			return st.nextToken();
		}
		
		public String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return null;
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
	
	private static class Node {
		Node child;
		boolean visited=false;
		int group;
		
		public void setChild(Node o) {
			child=o;
		}
		
		public int traverse(int group) {
			if (visited) {
				return 0;
			}
			visited=true;
			return 1+child.traverse(group);
		}
	}

}
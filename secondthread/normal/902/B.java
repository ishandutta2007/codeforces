

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class B {

	public static void solve(FS fs) {	
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++)
			nodes[i]=new Node();
		for (int i=1; i<n; i++) {
			int parent=fs.nextInt()-1;
			nodes[parent].children.add(nodes[i]);
		}
		for (int i=0; i<n; i++) {
			nodes[i].targetColor=fs.nextInt();
		}
		int ans=nodes[0].go();
		System.out.println(ans);
	}
	
	private static class Node {
		ArrayList<Node> children=new ArrayList<>();
		int color=0;
		int targetColor;
		
		public Node() {
			
		}
		
		public int go() {
			int total=0;
			if (color!=targetColor) {
				color=targetColor;
				total++;
			}
			for (Node n:children) {
				n.color=color;
			}
			for (Node n:children) {
				total+=n.go();
			}
			return total;
		}
	}

	
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FS scanner = new FS(System.in);
		solve(scanner);
	}
	

	private static class FS {
		BufferedReader br;
		StringTokenizer st;
		public FS(InputStream in) {
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
	}
}
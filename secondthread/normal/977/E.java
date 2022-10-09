

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class E {

	public static void solve(FastScanner fs) {	
		int n=fs.nextInt();
		int m=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++)
			nodes[i]=new Node();
		for (int i=0; i<m; i++) {
			int from=fs.nextInt()-1;
			int to=fs.nextInt()-1;
			nodes[from].connected.add(nodes[to]);
			nodes[to].connected.add(nodes[from]);
		}
		boolean[] exists=new boolean[n];
		for (int comp=0; comp<n; comp++) {
			if (nodes[comp].comp!=-1)
				continue;
			exists[comp]=true;
			ArrayDeque<Node> bfs=new ArrayDeque<>();
			bfs.add(nodes[comp]);
			nodes[comp].comp=comp;
			while (!bfs.isEmpty()) {
				Node next=bfs.remove();
				for (Node nn:next.connected) {
					if (nn.comp==-1) {
						nn.comp=comp;
						bfs.add(nn);
					}
				}
			}
		}
		boolean[] invalid=new boolean[n];
		for (Node nn:nodes)
			if (nn.deg()!=2)
				invalid[nn.comp]=true;
		int count=0;
		for (int i=0; i<n; i++)
			if (exists[i]&&!invalid[i])
				count++;
		System.out.println(count);
	}
	
	static class Node {
		ArrayList<Node> connected=new ArrayList<>();
		int comp=-1;
		public int deg() {
			return connected.size();
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
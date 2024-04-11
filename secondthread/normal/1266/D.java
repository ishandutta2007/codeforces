

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class D {

	public static void solve(FastScanner fs) {	
		int n=fs.nextInt();
		int m=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++)
			nodes[i]=new Node(i);
		ArrayList<Edge> edges=new ArrayList<>();
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1, c=fs.nextInt();
			edges.add(new Edge(a, b, c));
			nodes[a].finalDelta-=c;
			nodes[b].finalDelta+=c;
		}
		
		ArrayList<Edge> used=new ArrayList<>();
		ArrayList<Node> needMoney=new ArrayList<>();
		ArrayList<Node> needDebt=new ArrayList<>();
		for (Node nn:nodes) {
			if (nn.finalDelta>0) {
				needMoney.add(nn);
			}
			else if (nn.finalDelta<0) {
				needDebt.add(nn);
			}
		}
		int needMoneyIndex=0, needDebtIndex=0;
		while (needMoneyIndex<needMoney.size()) {
			Node mon=needMoney.get(needMoneyIndex);
			Node deb=needDebt.get(needDebtIndex);
			long toGive=Math.min(mon.finalDelta, -deb.finalDelta);
			used.add(new Edge(deb.index, mon.index, toGive));
			mon.finalDelta-=toGive;
			deb.finalDelta+=toGive;
			if (mon.finalDelta==0) needMoneyIndex++;
			if (deb.finalDelta==0) needDebtIndex++;
		}
		System.out.println(used.size());
		for (Edge e:used) {
			System.out.println((e.from+1)+" "+(1+e.to)+" "+e.value);
		}
	}
	
	static class Node {
		long finalDelta;
		
		int index;
		public Node(int index) {
			this.index=index;
		}
		
	}

	static class Edge {
		int from, to;
		long value;
		public Edge(int from, int to, long value) {
			this.from=from;
			this.to=to;
			this.value=value;
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
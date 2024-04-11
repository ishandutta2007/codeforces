

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
			nodes[i]=new Node(fs.nextInt()==1);
		for (int i=0; i<m; i++) {
			int from=fs.nextInt();
			int to=fs.nextInt();
			nodes[from].addNode(nodes[to]);
		}
		ArrayDeque<Node> freeMain=new ArrayDeque<>();
		ArrayDeque<Node> freeCo=new ArrayDeque<>();
		for (Node nn:nodes) {
			if (nn.inVerticies!=0)
				continue;
			if (nn.coprocessor)
				freeCo.add(nn);
			else
				freeMain.add(nn);
		}
		int times=0;
		while (true) {
			while (!freeMain.isEmpty()) {
				Node next=freeMain.remove();
				ArrayList<Node> toTakeCareOf=next.remove();
				for (Node nn:toTakeCareOf) {
					if (nn.coprocessor)
						freeCo.add(nn);
					else
						freeMain.add(nn);
				}
			}
			if (freeCo.isEmpty())
				break;
			times++;
			while (!freeCo.isEmpty()) {
				Node next=freeCo.remove();
				ArrayList<Node> toTakeCareOf=next.remove();
				for (Node nn:toTakeCareOf) {
					if (nn.coprocessor)
						freeCo.add(nn);
					else
						freeMain.add(nn);
				}
			}
		}
		System.out.println(times);
	}
	
	private static class Node {
		boolean coprocessor;
		ArrayList<Node> connectedTo=new ArrayList<>();
		int inVerticies;
		
		public Node(boolean coprocessor) {
			this.coprocessor=coprocessor;
		}
		
		private void addNode(Node o) {
			connectedTo.add(o);
			o.inVerticies++;
		}
		private ArrayList<Node> remove() {
			ArrayList<Node> toReturn=new ArrayList<>();
			for (Node n:connectedTo) {
				n.inVerticies--;
				if (n.inVerticies==0)
					toReturn.add(n);
			}
			return toReturn;
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
	}
}
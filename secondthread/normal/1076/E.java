import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class E {

	static int n;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++)
			nodes[i]=new Node();
		for (int i=1; i<n; i++) {
			int from=fs.nextInt()-1, to=fs.nextInt()-1;
			nodes[from].children.add(nodes[to]);
			nodes[to].children.add(nodes[from]);
		}
		nodes[0].dfs(null, 0);
		BIT bit=new BIT(n);
		int nQueries=fs.nextInt();
		for (int i=0; i<nQueries; i++) {
			int baseNode=fs.nextInt()-1, length=fs.nextInt(), delta=fs.nextInt();
			Query q=new Query(delta, length);
			nodes[baseNode].queries.add(q);
		}
		nodes[0].calculateAnswer(bit);
		PrintWriter out=new PrintWriter(System.out);
		for (int i=0; i<n; i++) {
			out.print(nodes[i].answer+" ");
		}
		out.println();
		out.close();
	}

	static class Node {
		ArrayList<Node> children=new ArrayList<>();
		ArrayList<Query> queries=new ArrayList<>();
		int height;
		long answer=0;
		
		public void dfs(Node parent, int height) {
			this.height=height;
			if (parent!=null)
				children.remove(parent);
			for (Node n:children)
				n.dfs(this, height+1);
		}
		
		public void calculateAnswer(BIT bit) {
			answer+=bit.pointQuery(height);
			for (Query q:queries) {
				int end=Math.min(n, height+q.length);
				answer+=q.delta;
				bit.rangeUpdate(height, end, q.delta);
			}
			for (Node nn:children) {
				nn.calculateAnswer(bit);
			}
			for (Query q:queries) {
				int end=Math.min(n, height+q.length);
				bit.rangeUpdate(height, end, -q.delta);
			}
		}
	}
	
	static class Query {
		int delta;
		int length;
		
		public Query(int delta, int length) {
			this.delta=delta;
			this.length=length;
		}
	}

	static class BIT {
		long[] vs;

		public BIT(int s) {
			vs=new long[s+5];
		}

		public long zzrangeSum(int idx) {
			idx++;
			long ret=0;
			for (int i=idx; i>0; i-=(i&-i))
				ret+=vs[i];
			return ret;
		}

		public void zzpointUpdate(int idx, int v) {
			idx++;
			for (int i=idx; i<vs.length; i+=(i&-i))
				vs[i]+=v;
		}
		
		public void rangeUpdate(int from, int to, int delta) {
			zzpointUpdate(from, delta);
			zzpointUpdate(to+1, -delta);
		}

		public long pointQuery(int to) {
			return zzrangeSum(to);
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

		public long nextLong() {
			return Long.parseLong(next());
		}

	}

}
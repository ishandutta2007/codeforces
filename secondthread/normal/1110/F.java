import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class _GlobalRound1F {
	
	static long oo=(long)1e18;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), q=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node();
		for (int i=1; i<n; i++) {
			int parent=fs.nextInt()-1;
			long weight=fs.nextLong();
			nodes[parent].adj.add(nodes[i]);
			nodes[parent].cost.add(weight);
		}
		nodes[0].dfs0(0, null, 0);
		SegTree st=new SegTree(0, n-1);
		for (Node nn:nodes) if (nn.adj.size()==0) {
			int ind=nn.preorder;
			st.rangeAdd(ind, ind, -oo+nn.depth);
		}
		
		Query[] queries=new Query[q];
		for (int qq=0; qq<q; qq++) {
			int node=fs.nextInt()-1, l=fs.nextInt()-1, r=fs.nextInt()-1;
			queries[qq]=new Query(l, r);
			nodes[node].queries.add(queries[qq]);
		}
		nodes[0].dfs1(st);
		PrintWriter out=new PrintWriter(System.out);
		for (Query qq:queries)
			out.println(qq.ans);
		out.close();
	}
	
	static class Node {
		int preorder, postorder;
		long depth;
		ArrayList<Node> adj=new ArrayList<>();
		ArrayList<Long> cost=new ArrayList<>();
		ArrayList<Query> queries=new ArrayList<>();
		
		public int dfs0(int count, Node par, long depth) {
			this.preorder=count;
			this.depth=depth;
			for (int i=0; i<adj.size(); i++) {
				Node nn=adj.get(i);
				long c=cost.get(i);
				count=nn.dfs0(count+1, this, depth+c);
			}
			this.postorder=count;
			return count;
		}
		
		public void dfs1(SegTree st) {
			for (Query q:queries) {
				long ans=st.rangeMin(q.l, q.r);
				q.ans=ans;
			}
			for (int i=0; i<adj.size(); i++) {
				Node nn=adj.get(i);
				long c=cost.get(i);
				st.rangeAdd(nn.preorder, nn.postorder, -c);
				st.rangeAdd(0, nn.preorder-1, c);
				st.rangeAdd(nn.postorder+1, st.rightmost, c);
				nn.dfs1(st);
				st.rangeAdd(nn.preorder, nn.postorder, c);
				st.rangeAdd(0, nn.preorder-1, -c);
				st.rangeAdd(nn.postorder+1, st.rightmost, -c);
			}
		}
		
	}
	
	static class Query {
		long ans;
		int l,r;
		public Query(int l, int r) {
			this.l=l;
			this.r=r;
		}
		
	}
	
	static class SegTree {
		int leftmost, rightmost;
		SegTree lChild, rChild;
		long toProp, min;
		
		public SegTree(int leftmost, int rightmost) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
			min=0;
			toProp=0;
			if (leftmost!=rightmost) {
				int mid=(leftmost+rightmost)/2;
				lChild=new SegTree(leftmost, mid);
				rChild=new SegTree(mid+1, rightmost);
				recalc();
			}
			else {
				min=oo;
			}
		}
		
		void rangeAdd(int l, int r, long val) {
			if (l<=leftmost && r>=rightmost) {
				toProp+=val;
				return;
			}
			if (l>rightmost || r<leftmost) {
				return;
			}
			prop();
			lChild.rangeAdd(l, r, val);
			rChild.rangeAdd(l, r, val);
			recalc();
		}
		
		void prop() {
			lChild.rangeAdd(leftmost, rightmost, toProp);
			rChild.rangeAdd(leftmost, rightmost, toProp);
			toProp=0;
			recalc();
		}
		
		long rangeMin(int l, int r) {
			if (l<=leftmost && r>=rightmost) {
				return min();
			}
			if (l>rightmost || r<leftmost) {
				return oo;
			}
			prop();
			return Math.min(lChild.rangeMin(l, r), rChild.rangeMin(l, r));
		}
		
		long min() {
			return min+toProp;
		}
		
		void recalc() {
			min=Math.min(lChild.min(), rChild.min());
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
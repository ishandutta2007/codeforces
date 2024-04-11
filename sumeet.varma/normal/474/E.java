import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.Arrays;

public class Pillars {

	static int n;
	static long d;
	static long a[] , b[];
	static int dp[] , prev[];
	static SegmentTree tree;
	static final int oo = Integer.MAX_VALUE/2;
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		d = ip(st1.nextToken());
	          
		a = new long[n];
		b = new long[n];
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    for(int i=0;i<n;i++)
	    	a[i] = b[i] = Long.parseLong(st2.nextToken());
	    	
	    Arrays.sort(b);
	    
	    tree = new SegmentTree(n);
	    
	    dp = new int[n];
	    Arrays.fill(dp,1);
	    prev = new int[n];
	    Arrays.fill(prev,-1);
	  
	    for(int i=0;i<n;i++){
	    	int lo = -1, hi = n;
			while(hi - lo > 1) {
				int m = lo + (hi - lo) / 2;
				if (b[m] <= a[i] - d) {
					lo = m;
				}else {
					hi = m;
				}
			}
			if (lo != -1) {
				Node node = tree.query(0, lo);
				if (node.value != -oo) {
					if (dp[i] < node.value + 1) {
						dp[i] = node.value + 1;
						prev[i] = node.idx;
					}
				}
			}

			lo = -1;
			hi = n;
			while(hi - lo > 1) {
				int m = lo + (hi - lo) / 2;
				if (b[m] >= a[i] + d) {
					hi = m;
				}else {
					lo = m;
				}
			}

			if (hi != n) {
				Node node = tree.query(hi, n - 1);
				if (node.value != -oo) {
					if (dp[i] < node.value + 1) {
						dp[i] = node.value + 1;
						prev[i] = node.idx;
					}
				}
			}

			lo = -1;
			hi = n;
			while(hi - lo > 1) {
				int m = lo + (hi - lo) / 2;
				if (b[m] <= a[i]) {
					lo = m;
				}else {
					hi = m;
				}
			}

			tree.update(lo, dp[i], i);

	    }
	    
	    int last = -1;
		for(int i = 0; i < n; ++i) {
			if (last == -1 || dp[i] > dp[last]) {
				last = i;
			}
		}

		w.println(dp[last]);
		List<Integer> ans = new ArrayList<Integer>();
		while(last != -1) {
			ans.add(last + 1);
			last = prev[last];
		}
		Collections.reverse(ans);
		for(int i : ans) {
			w.print(i + " ");
		}
		w.println();
		// out.println(Arrays.toString(dp));
		// out.println(Arrays.toString(prev));

		w.close();

	}

	public static int ip(String s){
		return Integer.parseInt(s);
	}	

}

class SegmentTree {
	Node []tree;
	int n,oo;

	public SegmentTree(int n) {
		this.n = n;
		oo = Integer.MAX_VALUE/2;
		int N = Integer.highestOneBit(n) << 2;
		tree = new Node[N];
		build(1, 0, n - 1);
	}

	private void build(int v, int tl, int tr) {
		if (tl == tr) {
			tree[v] = new Node(-oo, -1);
			return;
		}
		int tm = (tl + tr) >> 1;
		build(2 * v, tl, tm);
		build(2 * v + 1, tm + 1, tr);

		tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
	}

	public void update(int pos, int val, int idx) {
		update(1, 0, n - 1, pos, val, idx);
	}

	private void update(int v, int tl, int tr, int pos, int val, int idx) {
		if (tl == tr) {
			tree[v].value = val;
			tree[v].idx = idx;
			return;
		}
		int tm = (tl + tr) >> 1;
		if (pos <= tm) {
			update(2 * v, tl, tm, pos, val, idx);
		}else {
			update(2 * v + 1, tm + 1, tr, pos, val, idx);
		}

		tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
	}

	public Node query(int l, int r) {
		return query(1, 0, n - 1, l, r);
	}

	private Node query(int v, int tl, int tr, int l, int r) {
		if (l > r) return new Node(-oo, -1);
		if (tl == l && tr == r) {
			return tree[v];
		}
		int tm = (tl + tr) >> 1;
		Node left = query(2 * v, tl, tm, l, Math.min(tm, r));
		Node right = query(2 * v + 1, tm + 1, tr, Math.max(l, tm + 1), r);

		return merge(left, right);
	}

	private Node merge(Node left, Node right) {
		if (left == null) return right;
		if (right == null) return left;
		if (left.value > right.value) return left;
		return right;
	}
}
	
class Node {
	int value, idx;
	public Node(int value, int idx) {
		this.value = value;
		this.idx = idx;
	}
}
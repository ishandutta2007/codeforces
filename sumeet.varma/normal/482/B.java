import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class R275QDInterestingArray {

	static int ans[] = new int[100005];
	static int segtree[] = new int[4 * 100005];
	static int andtree[] = new int[4 * 100005];
	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter w = new PrintWriter(System.out);

		StringTokenizer st1 = new StringTokenizer(br.readLine());
		int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());

		int ll[] = new int[m];
		int rr[] = new int[m];
		int qq[] = new int[m];
		
		for (int i = 0; i < m; i++) {
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			ll[i] = ip(st2.nextToken()) - 1;
			rr[i] = ip(st2.nextToken()) - 1;
			qq[i] = ip(st2.nextToken());
			update(0, n - 1, 0, ll[i], rr[i], qq[i]);
		}
		
		//all numbers are generated , hence now no lazy propogation in tree
		for(int i=0;i<n;i++)
			ans[i] = getNumber(0,n-1,0,i);
	
		//and tree built
		init(0,n-1,0);
		boolean check = true;

		for(int i=0;i<m;i++){
			if(query(0,n-1,0,ll[i],rr[i]) != qq[i]){
				check = false;
				break;
			}
		}
		
		if (check == true) {
			w.println("YES");
			for (int i = 0; i < n; i++)
				w.printf("%d ", ans[i]);
			w.println();
		} else
			w.println("NO");

		w.close();
	}

	static void update(int start,int endd,int curr,int l,int r, int q) {
		
		if (start == l && endd == r) {
			segtree[curr] |= q;
			return;
		}

		int mid = (start + endd) / 2;
		if (l <= mid && r <= mid) {
		//	segtree[2*curr+1] |= segtree[curr];
			update(start, mid, 2 * curr + 1, l, r, q);
			return;
		}

		if (l > mid && r > mid) {
			//segtree[2*curr+2] |= segtree[2*curr+1];
			update(mid + 1, endd, 2 * curr + 2, l, r, q);
			return;
		}

		if (l <= mid && r > mid) {
			//segtree[2*curr+1] |= segtree[curr];
			//segtree[2*curr+2] |= segtree[curr];
			update(start, mid, 2 * curr + 1, l, mid, q);
			update(mid + 1, endd, 2 * curr + 2, mid + 1, r, q);
		}
	}
	
	static int getNumber(int start,int end,int curr,int num){
		if(start==end){
			return segtree[curr];
		}
		
		int mid = (start+end)/2;
		if(num <= mid){
			segtree[2*curr+1] |= segtree[curr];
			return getNumber(start,mid,2*curr+1,num);
		}
		else{
			segtree[2*curr+2] |= segtree[curr];
			return getNumber(mid+1,end,2*curr+2,num);
		}
	}
	
	static void init(int start,int endd,int curr){
		if(start==endd){
			andtree[curr] = ans[start];
			return;
		}
		
		int mid = (start+endd)/2;
		init(start,mid,2*curr+1);
		init(mid+1,endd,2*curr+2);
		andtree[curr] = andtree[2*curr+1] & andtree[2*curr+2];
	}
	
	static int query(int start, int endd, int curr, int l, int r) {
		if (start == l && endd == r)
			return andtree[curr];

		int mid = (start + endd) / 2;
		if (l <= mid && r <= mid)
			return query(start, mid, 2 * curr + 1, l, r);

		if (l > mid && r > mid)
			return query(mid + 1, endd, 2 * curr + 2, l, r);

		if (l <= mid && r > mid) {
			int t1 = query(start, mid, 2 * curr + 1, l, mid);
			int t2 = query(mid + 1, endd, 2 * curr + 2, mid + 1, r);
			return t1 & t2;
		}

		return 0;
	}

	
	public static int ip(String s) {
		return Integer.parseInt(s);
	}
}
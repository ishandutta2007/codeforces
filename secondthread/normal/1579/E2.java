import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class E2 {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			long ans=0;
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			TreeSet<Integer> ts=new TreeSet<>();
			for (int i:a) ts.add(i);
			HashMap<Integer, Integer> comp=new HashMap<>();
			for (int i:ts) comp.put(i, comp.size());
			for (int i=0; i<a.length; i++) a[i]=comp.get(a[i]);
			BIT bit=new BIT(comp.size());
			
			for (int i:a) {
				int less=bit.query(0, i-1), more=bit.query(i+1, comp.size()-1);
				ans+=Math.min(less, more);
				bit.update(i, 1);
			}
			System.out.println(ans);
		}
	}

	static class BIT {
		int n, tree[];
		
		public BIT(int N) {
			n = N;  tree = new int[N + 1];
		}

		void update(int i, int val) {
			for (i++; i <= n; i += i & -i) tree[i] += val;
		}
		
		int read(int i) {
			int sum = 0;
			for (i++; i > 0; i -= i & -i) sum += tree[i];
			return sum;
		}
		
		// query sum of [l, r] inclusive
		int query(int l, int r) {
			if (l>r) return 0;
			return read(r) - read(l - 1); }
		
		// if the BIT is a freq array, returns the index of the
		// kth item (0-indexed), or n if there are <= k items.
		int getKth(int k) {
			if (k < 0) return -1;
			int i = 0;
			for (int pw = Integer.highestOneBit(n); pw > 0; pw >>= 1)
				if (i + pw <= n && tree[i + pw] <= k) k -= tree[i += pw];
			return i;
		}
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
//	static class SegTree {
//		 int leftmost, rightmost;
//		 SegTree lChild, rChild;
//		 int sum=0;
//		 
//		 public SegTree(int l, int r) {
//			 this.leftmost=l;
//			 this.rightmost=r;
//		 }
//		 public void makeKids() {
//			 if (lChild!=null || leftmost==rightmost) return;
//			 int mid=(leftmost+rightmost)/2;
//			 lChild=new SegTree(leftmost, mid);
//			 rChild=new SegTree(mid+1, rightmost);
//		 }
//		 public void pointAdd(int x) {
//			 sum++;
//			 if (leftmost==rightmost) return;
//			 makeKids();
//			 if (x<=lChild.rightmost) {
//				 lChild.pointAdd(x);
//			 }
//			 else {
//				 rChild.pointAdd(x);
//			 }
//		 }
//		 public int rangeSum(int l, int r) {
//			 if (l>rightmost ||r<leftmost) return 0;
//			 if (l<=leftmost && r>=rightmost) return sum;
//			 if (lChild==null) return 0;
//			 makeKids();
//			 return lChild.rangeSum(l, r)+rChild.rangeSum(l, r);
//		 }
//	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		long k=fs.nextLong();
		int[] a=fs.readArray(n);
		ruffleSort(a);
		a=reverse(a);
		int best=-1;
		SegTree st=new SegTree(0, 500_000);
		best=check(best, st, k);
//		System.out.println("Adding to 0");
		st.rangeAdd(0, 0, 1);
		for (int i:a) {
//			System.out.println("Querying mindex");
			int mindex=st.minNonzeroIndex();
			st.rangeAdd(mindex, mindex, -1);
			int lTail=i/2;
			int rTail=i-lTail-1;
			int minHeight=mindex+2;
			st.rangeAdd(minHeight, minHeight+lTail-1, 1);
			st.rangeAdd(minHeight, minHeight+rTail-1, 1);
			best=check(best, st, k);
		}
		System.out.println(best);
	}
	
	static int check(int best, SegTree st, long k) {
		long rangeSum=st.rangeSum();
//		System.out.println("Sum: "+rangeSum);
		if (rangeSum<k) return best;
//		System.out.println("Can get something: ");
		int first=st.whenDoesPrefSumHitX(k);
		if (best==-1) return first;
		return Math.min(best, first);
	}
	
	static class SegTree {
		int leftmost, rightmost;
		long toProp;
		long rangeSum;
		SegTree lChild, rChild;
		
		public SegTree(int leftmost, int rightmost) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
			if (leftmost!=rightmost) {
				int mid=(leftmost+rightmost)/2;
				lChild=new SegTree(leftmost, mid);
				rChild=new SegTree(mid+1, rightmost);
			}
		}
		
		public void recalc() {
			if (leftmost==rightmost) return;
			rangeSum=lChild.rangeSum()+rChild.rangeSum();
		}
		
		public long rangeSum() {
			return rangeSum+toProp*(rightmost-leftmost+1);
		}
		
		public void prop() {
			if (leftmost==rightmost) {
				rangeSum+=toProp;
			}
			else {
				lChild.toProp+=toProp;
				rChild.toProp+=toProp;
			}
			toProp=0;
			recalc();
		}
		
		public void rangeAdd(int l, int r, long dx) {
			prop();
			if (l<=leftmost && r>=rightmost) {
				toProp+=dx;
				return;
			}
			if (l>rightmost || r<leftmost) {
				return;
			}
			lChild.rangeAdd(l, r, dx);
			rChild.rangeAdd(l, r, dx);
			recalc();
		}
		
		public int minNonzeroIndex() {
			prop();
			if (rangeSum()==0) throw null;
			if (leftmost==rightmost) return leftmost;
			
			if (lChild.rangeSum()!=0) return lChild.minNonzeroIndex();
			return rChild.minNonzeroIndex();
		}
		
		public int whenDoesPrefSumHitX(long x) {
			prop();
			if (rangeSum()<x) return -1;
			
			if (leftmost==rightmost) {
				return leftmost;
			}
			if (lChild.rangeSum()>=x) {
				return lChild.whenDoesPrefSumHitX(x);
			}
			x-=lChild.rangeSum();
			return rChild.whenDoesPrefSumHitX(x);
		}
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	
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

	static int[] reverse(int[] a) {
		int n=a.length;
		int[] res=new int[n];
		for (int i=0; i<n; i++) res[i]=a[n-1-i];
		return res;
	}
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int logn=fs.nextInt();
		int nQ=fs.nextInt();
		flipped=new boolean[logn+1];
		int[] a=fs.readArray(1<<logn);
		SegTree st=new SegTree(0, (1<<logn)-1, logn, a);
		PrintWriter out=new PrintWriter(System.out);
		
		for (int qq=0; qq<nQ; qq++) {
			int type=fs.nextInt();
			if (type==1) {
				int index=fs.nextInt()-1, value=fs.nextInt();
				st.pointUpdate(index, value);
			}
			else if (type==2) {
				//reverse
				int k=fs.nextInt();
				for (int i=0; i<=k; i++) flipped[i]^=true;
//				flipped[k]^=true;
			}
			else if (type==3) {
				//swap
				int k=fs.nextInt();
				flipped[k+1]^=true;
//				flipped[k]^=true;
			}
			else if (type==4) {
				int l=fs.nextInt()-1, r=fs.nextInt()-1;
				long ans=st.rangeSum(l, r);
				out.println(ans);
			}
//			System.out.print(type+", Array now: ");
//			System.out.println(Arrays.toString(flipped));
//			System.out.println();
//			printArray(st, logn);
		}
		out.close();
	}
	
	static boolean[] flipped;
	
	static void printArray(SegTree st, int logn) {
		for (int i=0; i<1<<logn; i++) {
			System.out.print(st.rangeSum(i, i)+" ");
		}
		System.out.println();
	}
	
	static class SegTree {
		int leftmost, rightmost, level;
		long sum;
		SegTree[] kids=new SegTree[2];
		
		public SegTree(int leftmost, int rightmost, int level, int[] a) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
			this.level=level;
			if (leftmost!=rightmost) {
				int mid=(leftmost+rightmost)/2;
				kids[0]=new SegTree(leftmost, mid, level-1, a);
				kids[1]=new SegTree(mid+1, rightmost, level-1, a);
				recalc();
			}
			else {
				sum=a[leftmost];
			}
		}
		
		public void recalc() {
			sum=0;
			for (SegTree s:kids) sum+=s.sum;
		}
		
		public SegTree lChild() {
			if (flipped[level])
				return kids[1];
			return kids[0];
		}
		
		public SegTree rChild() {
			if (flipped[level])
				return kids[0];
			return kids[1];
		}
		
		public void pointUpdate(int index, int val) {
			if (leftmost==rightmost) {
				sum=val;
				return;
			}
			if (index<1<<(level-1)) {
				lChild().pointUpdate(index, val);
			}
			else {
				index-=(1<<(level-1));
				rChild().pointUpdate(index, val);
			}
			recalc();
		}
		
		public long rangeSum(int l, int r) {
			if (l<=0 && r>=(1<<level)-1) {
				return sum;
			}
			if (r<0 || l>=(1<<level)) return 0;
			long lSum=lChild().rangeSum(l, r);
			long rSum=rChild().rangeSum(l-(1<<(level-1)), r-(1<<(level-1)));
			return lSum+rSum;
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

	
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
/*
4 7
10 2 1 7
2 1 4
2 1 1
2 2 3
1 2 100
2 1 3
2 2 2
2 2 4

point update: query type 1
range sum: query type 2
 */
public class Round458D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=1<<fs.nextInt(), q=fs.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++) a[i]=fs.nextInt();
		SegTree st=new SegTree(0, n-1, a);
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<q; qq++) {
			int index=fs.nextInt()-1, setTo=fs.nextInt();
			st.pointUpdate(index, setTo);
			out.println(st.value);
		}
		out.close();
	}
	
	static class SegTree {
		int leftmost, rightmost;
		SegTree lChild, rChild;
		long value;
		
		public SegTree(int leftmost, int rightmost, int[] a) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
			if (leftmost!=rightmost) {
				int mid=(leftmost+rightmost)/2;
				lChild=new SegTree(leftmost, mid, a);
				rChild=new SegTree(mid+1, rightmost, a);
			}
			else {
				value=a[leftmost];
			}
			recalc();
		}
		
		void recalc() {
			//do different stuff depending on size of rightmost-leftmost
			if (leftmost==rightmost) return;
			int length=rightmost-leftmost+1;
			//2   10
			//4   100
			//8   1000
			//16  10000
			//...
			int level=Integer.numberOfTrailingZeros(length);
			if (level%2==0) {
				value=lChild.value^rChild.value;
			}
			else {
				value=lChild.value|rChild.value;
			}
		}
		
//		public long rangeSum(int l, int r) {
//			if (l<=leftmost && r>=rightmost) return sum;
//			if (l>rightmost ||r<leftmost) return 0;
//			return lChild.rangeSum(l, r)+rChild.rangeSum(l, r);
//		}
		
		public void pointUpdate(int position, int newValue) {
			if (leftmost==rightmost) {
				value=newValue;
				return;
			}
			if (position<=lChild.rightmost)
				lChild.pointUpdate(position, newValue);
			else
				rChild.pointUpdate(position, newValue);
			recalc();
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreElements())
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
	}


	
	
	
}
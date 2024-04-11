import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
//		int T=fs.nextInt();
		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			boolean isOpen=true;
			long prefixSum=0;
			ArrayList<Range> ranges=new ArrayList<>();
			long ans=0;
			
			for (int i:a) {
				if (isOpen) {
					Range r=new Range(prefixSum, prefixSum+i-1);
					ranges.add(r);
					prefixSum+=i;
				}
				else {
					long biggest=prefixSum-1;
					long smallest=prefixSum-i;
					prefixSum-=i;
					for (Range r:ranges) {
						ans+=r.getOverlapAndTrim(smallest, biggest);
					}
				}
				isOpen^=true;
			}
			System.out.println(ans);
		}
	}
	
	static class Range {
		long start, end;
		boolean dead=false;
		public Range(long start, long end) {
			this.start=start;
			this.end=end;
		}
		public long getOverlapAndTrim(long l, long r) {
			if (end<start) return 0;
			
			long rr=Math.min(end, r);
			long ll=Math.max(l, start);
			end=Math.min(end, l);
			long ans=Math.max(rr-ll+1, 0);
//			System.out.println("Returning "+ans+" for lr: "+l+" "+r+" on "+start+" "+end);
			return ans;
		}
	}
	
	/*
	range += 1
	range sum
	 */
//	static class ST {
//		long leftmost, rightmost;
//		ST lChild, rChild;
//		long toProp;
//		long sum;
//		
//		public ST(long l, long r) {
//			leftmost=l;
//			rightmost=r;
//		}
//		void recalc() {
//			if (leftmost!=rightmost)
//				sum=lChild.sum()+rChild.sum();
//		}
//		void prop() {
//			if (toProp==0 || leftmost==rightmost) return;
//			makeKids();
//			lChild.toProp+=toProp;
//			rChild.toProp+=toProp;
//			toProp=0;
//			recalc();
//		}
//		long sum() {
//			return sum+toProp*(rightmost-leftmost+1);
//		}
//		void rangeAdd(long l, long r, int d) {
//			if (l>rightmost || r<leftmost) return;
//			if (l<=leftmost && r>=rightmost) {
//				toProp+=d;
//			}
//			makeKids();
//			prop();
//			lChild.rangeAdd(l, r, d);
//			rChild.rangeAdd(l, r, d);
//			recalc();
//		}
//		long rangeSum(long l, long r) {
//			if (l>rightmost || r<leftmost) return 0;
//			if (l<=leftmost && r>=rightmost) {
//				return sum();
//			}
//			makeKids();
//			prop();
//			return lChild.rangeSum(l, r)+rChild.rangeSum(l, r);
//		}
//		
//		void makeKids() {
//			if (lChild!=null || (leftmost==rightmost)) return;
//			long mid=(leftmost+rightmost)/2;
//			lChild=new ST(leftmost, mid);
//			rChild=new ST(mid+1, rightmost);
//		}
//	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
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
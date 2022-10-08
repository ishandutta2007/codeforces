import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), nCopies=fs.nextInt();
		ST st=new ST(0, n*nCopies-1);
		int[] a=fs.readArray(n*nCopies);
		for (int i=0; i<a.length; i++) a[i]--;
		int[] last=new int[n];
		boolean[] used=new boolean[n];
		Arrays.fill(last, -1);
		int[][] answers=new int[n][2];
		int maxThickness=(n+nCopies-2)/(nCopies-1);
//		System.out.println("Max thickness: "+maxThickness);
		for (int i=0; i<a.length; i++) {
			if (used[a[i]]) continue; //handled this color
			if (last[a[i]]==-1) {
				last[a[i]]=i;
				continue;
			}
			int rangeStart=last[a[i]], rangeEnd=i;
//			System.out.println("Considering "+rangeStart+" "+rangeEnd+" "+st.max(rangeStart, rangeEnd));
			if (st.max(rangeStart, rangeEnd)<maxThickness) {
				st.rangeAdd(rangeStart, rangeEnd, 1);
				used[a[i]]=true;
				answers[a[i]]=new int[] {rangeStart, rangeEnd};
			}
			last[a[i]]=i;
		}
		for (int i=0; i<n; i++) if (!used[i]) throw null;
		for (int i=0; i<n; i++) {
			System.out.println(1+answers[i][0]+" "+(1+answers[i][1]));
		}
		
	}

	static class ST {
		int leftmost, rightmost;
		ST lChild, rChild;
		int max, toProp;
		
		public ST(int leftmost, int rightmost) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
			if (leftmost!=rightmost) {
				int mid=(leftmost+rightmost)/2;
				lChild=new ST(leftmost, mid);
				rChild=new ST(mid+1, rightmost);
			}
		}
		
		int max() {
			return max+toProp;
		}
		
		void recalc() {
			if (leftmost==rightmost) return;
			max=Math.max(lChild.max(), rChild.max());
		}
		void prop() {
			if (leftmost!=rightmost) {
				lChild.toProp+=toProp;
				rChild.toProp+=toProp;
				toProp=0;
			}
			recalc();
		}
		
		void rangeAdd(int l, int r, int d) {
			if (l>rightmost || r<leftmost) return;
			if (l<=leftmost && r>=rightmost) {
				toProp+=d;
				return;
			}
			prop();
			lChild.rangeAdd(l, r, d);
			rChild.rangeAdd(l, r, d);
			recalc();
		}
		int max(int l, int r) {
			if (l>rightmost || r<leftmost) return Integer.MIN_VALUE;
			if (l<=leftmost && r>=rightmost) {
				return max();
			}
			prop();
			return Math.max(lChild.max(l, r), rChild.max(l, r));
		}
	}
	
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
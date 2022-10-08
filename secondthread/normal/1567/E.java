import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
4 2
1 4 1 5
1 3 4
2 1 4

4 1
2 2 2 2
2 1 4

 */
public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt(), q=fs.nextInt();
		int[] a=fs.readArray(n);
		ST st=new ST(0, n-1);
		for (int i=0; i<n-1; i++) {
			if (a[i]>a[i+1]) st.pointUpdate(i, true);
		}
		for (int qq=0; qq<q; qq++) {
			int type=fs.nextInt();
			if (type==1) {
				//point update
				int position=fs.nextInt()-1, value=fs.nextInt();
				a[position]=value;
				if (position!=0) {
//					System.out.println("Setting index "+(position-1)+" to "+(a[position]<a[position-1]));
					st.pointUpdate(position-1, a[position]<a[position-1]);
				}
//				System.out.println("\n\n");
				if (position!=n-1)
					st.pointUpdate(position, a[position+1]<a[position]);
			}
			else {
				int l=fs.nextInt()-1, r=fs.nextInt()-1;
//				System.out.println("Quering "+l+" "+r);
				long ans=st.rangeQuery(l, r).value();
				out.println(ans);
			}
		}
		out.close();
	}
	
	static class Data {
		int leftStraight, rightStraight, size;
		long middleSum;
		public Data(int leftStraight, int rightStraight, int size, long middleSum) {
			this.leftStraight=leftStraight;
			this.rightStraight=rightStraight;
			this.size=size;
			this.middleSum=middleSum;
		}
		long value() {
			if (size==leftStraight)
				return nC2(leftStraight);
			return middleSum+nC2(leftStraight) + nC2(rightStraight);
		}
		boolean uninterrupted() {
			return rightStraight==size;
		}
		
		public String toString() {
			return "{ "+leftStraight+" ... "+middleSum+" ... "+rightStraight+" } size: "+size;
		}
	}
	
	static Data combine(Data l, Data r) {
		if (l==null) return r;
		if (r==null) return l;
		int newSize=l.size+r.size;
		int newL=-1;
		int newR=-1;
		long newM=-1;
		if (l.uninterrupted()) {
			newM=r.middleSum;
			newL=l.size+r.leftStraight;
		}
		else {
			newL=l.leftStraight;
		}
		if (r.uninterrupted()) {
			newR=r.size+l.rightStraight;
			newM=l.middleSum;
		}
		else {
			newR=r.rightStraight;
		}
		if (newM==-1) {
			newM=l.middleSum+r.middleSum+nC2(l.rightStraight+r.leftStraight);
		}
		Data ans=new Data(newL, newR, newSize, newM);
//		System.out.println("Combined "+l+" "+r+" to "+ans);
		return ans;
	}
	
	static long nC2(int n) {
		return n*(long)(n+1)/2;
	}
/*
[   ]
 O O O O O O 
  | | | | | |
 */
	static class ST {
		int leftmost, rightmost;
		ST lChild, rChild;
		Data data;
		public ST(int l, int r) {
			this.leftmost=l;
			this.rightmost=r;
			if (l!=r) {
				int mid=(l+r)/2;
				lChild=new ST(l, mid);
				rChild=new ST(mid+1, r);
				recalc();
			}
			else {
				data=new Data(1, 1, 1, 0);
			}
		}
		void recalc() {
			if (leftmost==rightmost) {
				return;
			}
			data=combine(lChild.data, rChild.data);
		}
		void pointUpdate(int position, boolean isCutPoint) {
			if (leftmost==rightmost) {
				data=new Data(1, isCutPoint?0:1, 1, 0);
				return; 
			}
			if (position<=lChild.rightmost) {
				lChild.pointUpdate(position, isCutPoint);
			}
			else {
				rChild.pointUpdate(position, isCutPoint);
			}
			recalc();
		}
		Data rangeQuery(int l, int r) {
			if (l>rightmost || r<leftmost) return null;
			if (l<=leftmost && r>=rightmost) return data;
			Data lAns=lChild.rangeQuery(l, r);
			Data rAns=rChild.rangeQuery(l, r);
			return combine(lAns, rAns);
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
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/*
3 24 60 32
16 0
17 15
18 31

3 24 60 32
16 0
17 15
18 31

4 100 4 2
1 0
1 1
1 2
1 3

 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nTrains=fs.nextInt();
		fs.next();
		int minutes=fs.nextInt();
		int phaseLen=fs.nextInt();
		SegTree st=new SegTree(0, minutes-1);
		ArrayList<Integer> startTimes=new ArrayList<>();
		for (int i=0; i<nTrains; i++) {
			fs.next();
			int minute=fs.nextInt()%(minutes/2);
			st.update(minute, 1);
			st.update(minute+minutes/2, 1);
			startTimes.add(minute);
		}
		
		int bestAns=Integer.MAX_VALUE;
		int bestTime=0;
		for (int i:startTimes) {
			int toCancel=st.query(i+1, i+phaseLen-1);
			if (toCancel<bestAns) {
				bestAns=toCancel;
				bestTime=i;
			}
		}
		PrintWriter out=new PrintWriter(System.out);
		out.println(bestAns+" "+(bestTime+phaseLen)%(minutes/2));
		for (int i=0; i<startTimes.size(); i++) {
			int l=bestTime, r=bestTime+phaseLen;
			int t=startTimes.get(i);
			if (t>l && t<r) {
				out.print((i+1)+" ");
			}
			if (t+minutes/2>l && t+minutes/2<r) {
				out.print((i+1)+" ");
			}
		}
		out.println();
		out.close();
	}
	
	static class SegTree {
		int leftmost, rightmost, sum;
		SegTree lChild, rChild;
		
		public SegTree(int leftmost, int rightmost) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
		}
		
		public void update(int index, int val) {
			sum++;
			if (leftmost==rightmost) {
				return;
			}
			if (lChild==null)makeKids();
			if (index<=lChild.rightmost) lChild.update(index, val);
			else rChild.update(index, val);
		}
		
		public void makeKids() {
			int mid=(leftmost+rightmost)/2;
			lChild=new SegTree(leftmost, mid);
			rChild=new SegTree(mid+1, rightmost);
		}
		
		public int query(int l, int r) {
			if (l<=leftmost && r>=rightmost) return sum;
			if (l>rightmost || r<leftmost) return 0;
			if (lChild==null)return 0;
			return lChild.query(l, r)+rChild.query(l, r);
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
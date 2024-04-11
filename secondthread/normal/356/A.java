import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class _207A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), q=fs.nextInt();
		SegTree st=new SegTree(0, n-1);
		for (int qq=0; qq<q; qq++) {
			int leftOfRange=fs.nextInt()-1, rightOfRange=fs.nextInt()-1, winner=fs.nextInt()-1;
			st.rangeKill(leftOfRange, winner-1, winner);
			st.rangeKill(winner+1, rightOfRange, winner);
		}
		PrintWriter out=new PrintWriter(System.out);
		for (int i=0; i<n; i++) out.print(st.killedMe(i)+1+" ");
		out.println();
		out.close();
	}
	
	static class SegTree {
		int leftmost, rightmost;
		SegTree lChild, rChild;
		int toProp = -1;//if everyone on this group was killed who killed them is stored here, or -1 otherwise
		
		public SegTree(int leftmost, int rightmost) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
			if (leftmost!=rightmost) {
				int mid=(leftmost+rightmost)/2;
				lChild=new SegTree(leftmost, mid);
				rChild=new SegTree(mid+1, rightmost);
			}
		}
		
		long killedMe(int index) {
			if (leftmost==rightmost) {
				return toProp;
			}
			propogate();
			if (index<=lChild.rightmost) return lChild.killedMe(index);
			else return rChild.killedMe(index);
		}
		
		void rangeKill(int l, int r, int killedBy) {
			if (l<=leftmost && r>=rightmost) {
				//covers range
				if (toProp!=-1) {
					//this entire range was already killed
					return;
				}
				toProp=killedBy;
				return;
			}
			if (l>rightmost || r<leftmost) {
				//entirely disjoint
				return;
			}
			
			//otherwise we contain an endpoint, and we aren't a leaf of the tree
			propogate();
			lChild.rangeKill(l, r, killedBy);
			rChild.rangeKill(l, r, killedBy);
		}
		
		void propogate() {
			if (leftmost==rightmost) return;
			
			if (toProp!=-1) {
				lChild.rangeKill(leftmost, rightmost, toProp);
				rChild.rangeKill(leftmost, rightmost, toProp);
			}
			
			toProp=-1;
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
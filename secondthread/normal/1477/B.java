import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/*
1
5 2
00000
00111
1 5
1 3

 */
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		outer: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int nQueries=fs.nextInt();
			char[] start=fs.next().toCharArray();
			char[] end=fs.next().toCharArray();
			Query[] queries=new Query[nQueries];
			for (int qq=0; qq<nQueries; qq++)
				queries[qq]=new Query(fs.nextInt()-1, fs.nextInt()-1);
			
			SegTree st=new SegTree(0, n-1);
			for (int i=0; i<n; i++) st.setTo(i, i, end[i]-'0');
			for (int i=nQueries-1; i>=0; i--) {
				Query q=queries[i];
//				System.out.println("On query "+i);
				int size=q.to-q.from+1;
				int sum=st.sum(q.from, q.to);
				if (sum*2==size) {
					out.println("NO");
					continue outer;
				}
				if (sum*2<size) {
					st.setTo(q.from, q.to, 0);
				}
				else {
					st.setTo(q.from, q.to, 1);
				}
			}
//			System.out.println("Finished all queries");
			for (int i=0; i<n; i++) {
				if (st.sum(i, i)!=start[i]-'0') {
//					System.out.println("Got "+st.sum(i, i)+" "+start[i]);
					out.println("NO");
					continue outer;
				}
			}
			
			out.println("YES");
		}
		out.close();
	}

	static class Query {
		int from, to;
		public Query(int from, int to) {
			this.from=from;
			this.to=to;
		}
	}
	
	static class SegTree {
		SegTree lChild, rChild;
		int leftmost,rightmost;
		int sum;
		int setTo=-1;
		
		public SegTree(int l, int r) {
			this.leftmost=l;
			this.rightmost=r;
			if (l!=r) {
				int mid=(leftmost+rightmost)/2;
				lChild=new SegTree(l, mid);
				rChild=new SegTree(mid+1, r);
			}
		}
		
		int sum() {
			if (setTo==-1) return sum;
			return setTo==0?0:rightmost-leftmost+1;
		}
		
		void recalc() {
			//assume that toProp==0
			if (leftmost==rightmost) {
				return;
			}
			sum=lChild.sum()+rChild.sum();
		}
		
		void prop() {
			if (setTo==-1) return;
			if (leftmost==rightmost) {
				sum=setTo;
				setTo=-1;
				return;
			}
			lChild.setTo=setTo;
			rChild.setTo=setTo;
			setTo=-1;
			recalc();
		}
		
		void setTo(int l, int r, int setTo) {
			prop();
			if (l<=leftmost && r>=rightmost) {
				this.setTo=setTo;
				return;
			}
			if (r<leftmost|| l>rightmost) {
				return;
			}
			lChild.setTo(l, r, setTo);
			rChild.setTo(l, r, setTo);
			recalc();
		}
		
		int sum(int l, int r) {
			prop();
			if (l<=leftmost && r>=rightmost) {
				return sum();
			}
			if (r<leftmost || l>rightmost) {
				return 0;
			}
			return lChild.sum(l, r)+rChild.sum(l, r);
		}
	}
	
	static void ruffleSort(int[] a) {
		int n=a.length;
		Random r=new Random();
		for (int i=0; i<a.length; i++) {
			int oi=r.nextInt(n), temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
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
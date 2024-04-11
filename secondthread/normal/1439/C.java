import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
10 3
10 10 10 6 6 5 5 5 3 1
1 3 10
1 4 7
2 2 17

10 2
10 10 10 6 6 5 5 5 3 1
1 4 7
2 2 17

10 1
10 10 10 7 6 5 5 5 3 1
2 2 17
 */
public class C {


	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int nQueries=fs.nextInt();
		int[] a=fs.readArray(n);
		ST st=new ST(0, n-1, a);
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQueries; qq++) {
			int type=fs.nextInt();
			if (type==1) {
				int r=fs.nextInt()-1, value=fs.nextInt();
				int l=st.firstIndexLessThan(value);
				if (l>r) continue;
				st.rangeSet(l, r, value);
			}
			else {
				int l=fs.nextInt()-1;
				moneyForWalk=fs.nextInt();
				nEaten=0;
				st.walk(l);
				out.println(nEaten);
			}
		}
		out.close();
	}
	
	static int moneyForWalk;
	static int nEaten=0;

	static class ST {
		int leftmost, rightmost;
		int min, max;
		int propSetTo=-1;
		long sum=0;
		ST lChild, rChild;
		
		public ST(int leftmost, int rightmost, int[] a) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
			if (leftmost!=rightmost) {
				int mid=(leftmost+rightmost)>>1;
				lChild=new ST(leftmost, mid, a);
				rChild=new ST(mid+1, rightmost, a);
				recalc();
			}
			else {
				sum=min=max=a[leftmost];
			}
		}
		
		void prop() {
			if (propSetTo==-1) return;
			if (leftmost!=rightmost) {
				lChild.rangeSet(leftmost, rightmost, propSetTo);
				rChild.rangeSet(leftmost, rightmost, propSetTo);
			}
			else {
				sum=min=max=propSetTo;
			}
			propSetTo=-1;
			recalc();
		}
		void recalc() {
			if (leftmost==rightmost)
				return;
			sum=lChild.sum()+rChild.sum();
			min=rChild.min();
			max=lChild.max();
		}
		int min() {
			if (propSetTo!=-1) return propSetTo;
			return min;
		}
		int max() {
			if (propSetTo!=-1) return propSetTo;
			return max;
		}
		long sum() {
			if (propSetTo!=-1) return (rightmost-leftmost+1)*(long)propSetTo;
			return sum;
		}
		
		void rangeSet(int l, int r, int to) {
			if (l<=leftmost && r>=rightmost) {
				propSetTo=to;
				return;
			}
			if (l>rightmost || r<leftmost) return;
			prop();
			lChild.rangeSet(l, r, to);
			rChild.rangeSet(l, r, to);
			recalc();
		}
		int lastIndexGreaterThan(int x) {
			prop();
			if (max<=x) {
				return leftmost-1;
			}
			if (leftmost==rightmost) return leftmost;
			if (rChild.max()>x) return rChild.lastIndexGreaterThan(x);
			return lChild.lastIndexGreaterThan(x);
		}
		int firstIndexLessThan(int x) {
			prop();
			if (min>=x) return rightmost+1;
			if (leftmost==rightmost) return leftmost;
			if (lChild.min()<x) return lChild.firstIndexLessThan(x);
			return rChild.firstIndexLessThan(x);
		}
		void walk(int l) {
			prop();
			//eat everything
			if (l<=leftmost && sum<=moneyForWalk) {
				moneyForWalk-=sum;
				nEaten+=rightmost-leftmost+1;
				return;
			}
			//eat nothing
			if (moneyForWalk<min || l>rightmost) {
				return;
			}
			//otherwise, at most log ranges will be eaten total
			lChild.walk(l);
			rChild.walk(l);
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
//
}
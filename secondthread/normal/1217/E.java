import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

public class E {
	static final int oo=1000+(int)1e9;
	static final long[] tenPow=new long[11];

	public static void main(String[] args) {
		PrintWriter out=new PrintWriter(System.out);
		tenPow[0]=1;
		for (int i=1; i<tenPow.length; i++)
			tenPow[i]=tenPow[i-1]*10;
		
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), nQueries=fs.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++) a[i]=fs.nextInt();
		SegTree st=new SegTree(0, n-1, a);
		for (int qq=0; qq<nQueries; qq++) {
			int type=fs.nextInt();
			if (type==1) {
				int index=fs.nextInt()-1, to=fs.nextInt();
				st.set(index, to);
			}
			else {
				int l=fs.nextInt()-1, r=fs.nextInt()-1;
				int[] tenLowest=new int[10];
				Arrays.fill(tenLowest, oo);
				st.add10Lowest(tenLowest, l, r);
				out.println(getMinSum(tenLowest));
			}
		}
		out.close();
		
//		Random r=new Random(5);
//		int T=10000;
//		final int maxn=3;
//		for (int tt=0; tt<T; tt++) {
//			int n=1+r.nextInt(maxn);
//			int[] a=new int[n];
//			for (int i=0; i<n; i++) a[i]=getValue(r);
//			System.out.println("Array: "+Arrays.toString(a));
//			SegTree st=new SegTree(0, n-1, a);
//			int nQueries=1+r.nextInt(maxn);
//			for (int qq=0; qq<nQueries; qq++) {
//				if (r.nextBoolean()) {
//					//type 1
//					int index=r.nextInt(n);
//					int to=getValue(r);
//					System.out.println("Changing index: "+index+" to "+to);
//					a[index]=to;
//					st.set(index, to);
//				}
//				else {
//					//type 2
//					int ll=r.nextInt(n), rr=r.nextInt(n);
//					if (ll>rr) {
//						int temp=ll;
//						ll=rr;
//						rr=temp;
//					}
//					ArrayList<Integer> ans=new ArrayList<>();
//					for (int i=ll; i<=rr; i++)
//						ans.add(a[i]);
//					Collections.sort(ans);
//					ArrayList<Integer> toAdd=new ArrayList<>();
//					st.add10Lowest(toAdd, ll, rr);
//					Collections.sort(toAdd);
//					if (!ans.equals(toAdd)) {
//						System.out.println("Expected "+ans+" but got "+toAdd+" for ll: "+ll+" rr: "+rr);
//						throw null;
//					}
//				}
//			}
//		}
//		System.out.println("All tests complete");
	}
	
	static int getValue(Random r) {
		return r.nextInt(10);
//		StringBuilder sb=new StringBuilder();
//		for (int i=0; i<9; i++)
//			sb.append(r.nextInt(3)==0?r.nextInt(10):0);
//		return Integer.parseInt(sb.toString());
	}
//	
//	static long getMinSum(int[] cand) {
////		System.out.println("getting min sum of "+Arrays.toString(cand));
//		long best=Long.MAX_VALUE;
//		for (int i=0; i<cand.length; i++) {
//			for (int j=i+1; j<cand.length; j++) {
//				int ii=cand[i], jj=cand[j];
//				if (ii+jj>=best) break;
//				for (int pow=0; pow<10; pow++) {
//					boolean iiWorks=ii%tenPow[pow+1]/tenPow[pow]!=0;
//					boolean jjWorks=jj%tenPow[pow+1]/tenPow[pow]!=0;
//					if (iiWorks&&jjWorks) {
//						best=ii+jj;
//					}
//				}
//			}
//		}
//		return best==Long.MAX_VALUE?-1:best;
//	}
	static long getMinSum(int[] cand) {
		long best=Long.MAX_VALUE;
		int[] minWithDigit=new int[10];
		int[] minWithDigit2=new int[10];
		Arrays.fill(minWithDigit, oo);
		Arrays.fill(minWithDigit2, oo);
		for (int i:cand) {
			for (int pow=0; pow<10; pow++) {
				boolean works=(i%tenPow[pow+1]/tenPow[pow])!=0;
				if (!works) continue;
				else {
					if (minWithDigit[pow]>i) {
						minWithDigit2[pow]=minWithDigit[pow];
						minWithDigit[pow]=i;
					}
					else if (minWithDigit2[pow]>i) {
						minWithDigit2[pow]=i;
					}
				}
			}
		}
		for (int i=0; i<10; i++) {
			if (minWithDigit2[i]!=oo) {
				best=Math.min(best, minWithDigit[i]+minWithDigit2[i]);
			}
		}
		return best==Long.MAX_VALUE?-1:best;
	}
	

	final static int required=10;
	static class SegTree {
		int leftmost, rightmost;
		int[] tenLowest;
		SegTree lChild, rChild;
		
		public SegTree(int leftmost, int rightmost, int[] a) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
			if (leftmost==rightmost) {
				tenLowest=new int[1];
				tenLowest[0]=a[leftmost];
			}
			else {
				int mid=(leftmost+rightmost)/2;
				lChild=new SegTree(leftmost, mid, a);
				rChild=new SegTree(mid+1, rightmost, a);
				tenLowest=new int[Math.min(required, rightmost-leftmost+1)];
				rebuildTenLowest();
			}
		}
		
		private void rebuildTenLowest() {
			Arrays.fill(tenLowest, oo);
			lChild.add10Lowest(tenLowest);
			rChild.add10Lowest(tenLowest);
		}
		
		public void set(int index, int to) {
			if (index<leftmost||index>rightmost) return;
			if (leftmost==rightmost) {
				tenLowest[0]=to;
				return;
			}
			lChild.set(index, to);
			rChild.set(index, to);
			rebuildTenLowest();
		}
		
		public void add10Lowest(int[] toAdd) {
			merge(toAdd, tenLowest);
		}
		
		public void add10Lowest(int[] toAdd, int l, int r) {
			if (r<leftmost||l>rightmost) return;
			if (l<=leftmost&&r>=rightmost) {
				merge(toAdd, tenLowest);
				return;
			}
			lChild.add10Lowest(toAdd, l, r);
			rChild.add10Lowest(toAdd, l, r);
		}
		
		public String toString() {
			return "("+leftmost+" "+rightmost+") lowest: "+Arrays.toString(tenLowest);
		}
		
		//merges b into a, assume both sorted
		public void merge(int[] a, int[] b) {
			int aIndex=0, bIndex=0;
			int n=a.length;
			int[] toReturn=new int[n];
			int ind=0;
			while (aIndex<a.length&&bIndex<b.length&&ind<toReturn.length) {
				 if (a[aIndex]<=b[bIndex]) {
					toReturn[ind++]=a[aIndex++]; 
				 }
				 else {
					 toReturn[ind++]=b[bIndex++];
				 }
			}
			while (ind<n) {
				toReturn[ind++]=a[aIndex++];
			}
			for (int i=0; i<n; i++) a[i]=toReturn[i];
		}
	}


	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}
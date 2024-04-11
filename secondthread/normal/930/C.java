

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	public static void solve(FastScanner fs) {	
		int nSegments=fs.nextInt();
		int size=fs.nextInt();
		int[] delta=new int[size+1];
		for (int i=0; i<nSegments; i++) {
			int start=fs.nextInt()-1;
			int end=fs.nextInt()-1;
			delta[start]++;
			delta[end+1]--;
		}
		int[] heights=new int[size];
		heights[0]=delta[0];
		for (int i=1; i<size; i++)
			heights[i]=heights[i-1]+delta[i];
		
		int[] heightsRev=new int[size];
		for (int i=0; i<size; i++)
			heightsRev[i]=heights[size-i-1];
		
		int[] empty=new int[nSegments+1];
		SegTree dp=new SegTree(empty, 0, nSegments);
		SegTree dpRev=new SegTree(empty, 0, nSegments);
		int[] maxAllRegular=new int[size+1], maxAllRev=new int[size+1];
		for (int i=0; i<size; i++) {
			int height=heights[i];
			int prevMax=dp.maxQuery(0, height);
			dp.update(height, prevMax+1);
			maxAllRegular[i+1]=dp.maxQuery(0, nSegments);
			
			int heightRev=heightsRev[i];
			prevMax=dpRev.maxQuery(0, heightRev);
			dpRev.update(heightRev, prevMax+1);
			maxAllRev[size-i-1]=dpRev.maxQuery(0, nSegments);
		}
		
		
		int ans=0;
		for (int i=0; i<=size; i++) {
			ans=Math.max(ans, maxAllRegular[i]+maxAllRev[i]);
		}
		System.out.println(ans);
	}

	private static void print(SegTree tree, int n) {
		String s="";
		for (int i=0; i<n; i++)
			s+=tree.maxQuery(i, i)+" ";
		System.out.println(s);
	}
	
	static class SegTree {
		SegTree lChild, rChild;
		int max;
		int l, r, mid;
		
		public SegTree(int[] a, int l, int r) {
			this.l=l;
			this.r=r;
			if (l==r) {
				max=a[l];
				return;
			}
			mid=(l+r)/2;
			lChild=new SegTree(a, l, mid);
			rChild=new SegTree(a, mid+1, r);
			max=Math.max(lChild.max, rChild.max);
		}
		
		public void update(int index, int to) {
			if (index<l||index>r)
				return;
			if (l==r) {
				max=to;
				return;
			}
			max=Math.max(max, to);
			if (index<=mid) {
				lChild.update(index, to);
			}
			else {
				rChild.update(index, to);
			}
		}
		
		public int maxQuery(int left, int right) {
			if (right<l||left>r)
				return -10000;
			if (left<=l&&right>=r) {
				return max;
			}
			return Math.max(lChild.maxQuery(left, right), rChild.maxQuery(left, right));
		}
	}
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}
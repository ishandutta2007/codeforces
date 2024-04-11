import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class F1 {
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), T=fs.nextInt();
		
		for (int tt=0; tt<T; tt++) {
			int target=fs.nextInt();
			int mindex=0;
			int maxdex=n-1;
			while (mindex!=maxdex) {
//				System.err.println(mindex+" "+maxdex);
				int mid=(mindex+maxdex)/2;
				System.out.println("? 1 "+(mid+1));
				int nOnes=fs.nextInt();
				int nZeros=mid+1-nOnes;
				if (nZeros<target) {
					mindex=mid+1;
				}
				else {
					maxdex=mid;
				}
			}
			System.out.println("! "+(mindex+1));
		}
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class BIT {
		int n, tree[];
		public BIT(int N) {
			n = N;  tree = new int[N + 1];
		}
		void update(int i, int val) {
			for (i++; i <= n; i += i & -i) tree[i] += val;
		}
		int read(int i) {
			int sum = 0;
			for (i++; i > 0; i -= i & -i) sum += tree[i];
			return sum;
		}
		// query sum of [l, r] inclusive
		int query(int l, int r) { return read(r) - read(l - 1); }
		// if the BIT is a freq array, returns the index of the
		// kth item (0-indexed), or n if there are <= k items.
		int getKth(int k) {
			if (k < 0) return -1;
			int i = 0;
			for (int pw = Integer.highestOneBit(n); pw > 0; pw >>= 1)
				if (i + pw <= n && tree[i + pw] <= k) k -= tree[i += pw];
			return i;
		}
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
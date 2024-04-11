import java.util.*;
import java.io.*;

public class B {
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		char[] a=fs.next().toCharArray();
		int n=a.length;
		int q=fs.nextInt();
		Query[] queries=new Query[q];
		for (int i=0; i<q; i++) queries[i]=new Query(fs.nextInt()-1, fs.nextInt()-1, i);
		Arrays.sort(queries);
		boolean[][] isPal=new boolean[n][n];
		//odd palendromes
		for (int i=0; i<n; i++) isPal[i][i]=true;
		for (int radius=1; radius*2+1<=n; radius++) {
			for (int center=radius; center+radius<n; center++) {
				if (!isPal[center-radius+1][center+radius-1])continue;
				if (a[center-radius]==a[center+radius])
					isPal[center-radius][center+radius]=true;
			}
		}
		//even palendromes
		for (int radius=0; radius*2<=n; radius++) {
			for (int lCenter=radius; lCenter+1+radius<n; lCenter++) {
				if (!(radius==0||isPal[lCenter-radius+1][lCenter+1+radius-1])) continue;
				if (a[lCenter-radius]==a[lCenter+1+radius]) 
					isPal[lCenter-radius][lCenter+1+radius]=true;
			}
		}
		int lastAdded=n;
		BIT bit=new BIT(n);
		int[] answers=new int[q];
		for (int query=q-1; query>=0; query--) {
			while (queries[query].from<lastAdded) {
				lastAdded--;
				for (int i=lastAdded; i<n; i++) {
					if (isPal[lastAdded][i]) {
						bit.update(i, 1);
					}
				}
			}
			int ans=bit.read(queries[query].to);
			answers[queries[query].index]=ans;
		}
		PrintWriter out=new PrintWriter(System.out);
		for (int i:answers) out.println(i);
		out.close();
	}
	
	private static class Query implements Comparable<Query> {
		int from, to, index;
		public Query(int from, int to, int index) {
			this.from=from;
			this.to=to;
			this.index=index;
		}
		
		public int compareTo(Query o) {
			return Integer.compare(from, o.from);
		}
	}
	
	//@
static class BIT {
	int n;
	int[] tree;
	int[] indices; // Used for compressed BIT //%
	
	public BIT(int n) {
		this.n = n;
		tree = new int[n + 1];
	}
	
	int read(int i) {
		i++;
		int sum = 0;
		while (i > 0) {
			sum += tree[i];
			i -= i & -i;
		}
		return sum;
	}
	
	void update(int i, int val) {
		i++;
		while (i <= n) {
			tree[i] += val;
			i += i & -i;
		}
	}
	
	//#
	// Compressed BIT constructor
	// A BIT that only stores the values that will be updated. 
	// indices is a sorted array of all the unique indices 
	// that would be used for this BIT.
	public BIT(int[] indices) {
		this.indices = indices;
		n = indices.length;
		tree = new int[n+1];
	}
	
	// Search for the index in the array. If the index was not found, 
	// return the first index lower than the search index.
	int binSearch(int ind) {
		int low = 0;
		int high = n-1;
		while(low < high) {
			int mid = (low + high+1)/2;
			if(indices[mid] == ind)
				return mid;
			else if(indices[mid] < ind) 
				low = mid;
			else if(indices[mid] > ind) 
				high = mid-1;
		}
		if(indices[low] > ind)
			--low;
		return low;
	}
	
	// Read the largest index less than or equal to the given index.
	int readCompr(int index) {
		return read(binSearch(index)+1);
	}
	// Update a specific index by a value. If the index is not in this 
	// compressed BIT, the index below will be updated.
	void updateCompr(int index, int val) {
		update(binSearch(index)+1, val);
	}
	//$
}

	
	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
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
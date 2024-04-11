import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class F {
	
	static long oo=(long)1e18;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		int[] deleteCost=fs.readArray(n);
		n++;
		int lisLen=fs.nextInt();
		int[] lis=fs.readArray(lisLen);
		lisLen++;
		int lisIndex=0;
		for (int i:a) {
			if (lisIndex<lisLen && lis[lisIndex]==i) lisIndex++;
		}
		if (lisIndex!=lisLen) {
			System.out.println("NO");
			return;
		}
		System.out.println("YES");
		Entry[] allEntries=new Entry[n];
		for (int i=0; i<n; i++) allEntries[i]=new Entry(i, a[i]);
		Arrays.sort(allEntries);
		ArrayList<Integer>[] indeciesOf=new ArrayList[n+1];
		for (int i=0; i<=n; i++) indeciesOf[i]=new ArrayList<>();
		for (int i=0; i<n; i++) indeciesOf[a[i]].add(i);
		BIT bit=new BIT(n);
		for (int i=0; i<n; i++)
			if (deleteCost[i]<0) bit.update(i, deleteCost[i]);
		
		long[] dp=new long[n];
		Arrays.fill(dp, oo);
		int indexInAllEntries=n-1;
		
		for (lisIndex=lisLen-1; lisIndex>=0; lisIndex--) {
			int lisValue=lis[lisIndex];
			while (indexInAllEntries>0 && allEntries[indexInAllEntries].value>lisValue) {
				//we need to pay for it, so add it to the bit if its cost is positive
				int ind=allEntries[indexInAllEntries].index;
				if (deleteCost[ind]>0) bit.update(ind, deleteCost[ind]);
				indexInAllEntries--;
			}
			if (lisIndex==lisLen-1) {
				for (int i:indeciesOf[lisValue]) {
					dp[i]=bit.rangeSum(i+1, n-1);
//					System.out.println("Index "+i+" is "+dp[i]);
				}
			}
			else {
				//we can choose from any of the above dp states
				int bestIndex=-1;
				int nextLisValue=lis[lisIndex+1];
				int candNextIndex=indeciesOf[nextLisValue].size()-1;
				for (int i=indeciesOf[lisValue].size()-1; i>=0; i--) {
					int curIndex=indeciesOf[lisValue].get(i);
					while (candNextIndex>=0) {
						int candIndex=indeciesOf[nextLisValue].get(candNextIndex);
						if (candIndex<curIndex) break;
						if (bestIndex==-1) {
							bestIndex=candIndex;
						}
						else {
							long bestIndexCost=dp[bestIndex]+bit.rangeSum(curIndex+1, bestIndex-1);
							long candIndexCost=dp[candIndex]+bit.rangeSum(curIndex+1, candIndex-1);
							if (bestIndexCost>candIndexCost)
								bestIndex=candIndex;
						}
						candNextIndex--;
					}
					if (bestIndex==-1) {
//						System.out.println("No followup for index: "+curIndex);
						dp[curIndex]=oo;
					}
					else {
//						System.out.println("BestIndex for "+curIndex+" is "+bestIndex);
						dp[curIndex]=dp[bestIndex]+bit.rangeSum(curIndex+1, bestIndex-1);
					}
				}
			}
		}
		
		long ans=oo;
		for (int i=0; i<n; i++)
			if (a[i]==lis[0]) ans=Math.min(ans, dp[i]);
		System.out.println(ans);
//		System.out.println(Arrays.toString(dp));
	}
	
	static class Entry implements Comparable<Entry> {
		int index, value;
		public Entry(int index, int value) {
			this.index=index;
			this.value=value;
		}
		
		public int compareTo(Entry o) {
			return Integer.compare(value, o.value);
		}
	}
	
	static class BIT {
		int n;
		long[] tree;
		
		public BIT(int n) {
			this.n = n;
			tree = new long[n + 2];
		}
		
		long read(int i) {
			i++;
			long sum = 0;
			while (i > 0) {
				sum += tree[i];
				i -= i & -i;
			}
			return sum;
		}
		
		void update(int i, long val) {
			i++;
			while (i <= n) {
				tree[i] += val;
				i += i & -i;
			}
		}
		
		long rangeSum(int from, int to) {
			if (from==0) return read(to);
			return read(to)-read(from-1);
		}
		
		// if the BIT is a freq array, returns the
		// index of the kth item, or n if there are fewer
		// than k items.
		int getKth(int k) {
			int e=Integer.highestOneBit(n), o=0;
			for (; e!=0; e>>=1) {
				if (e+o<=n && tree[e+o]<=k) {
					k-=tree[e+o];
					o+=e;
				}
			}
			return o;
		}
		
	}

	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int[] readArray(int n) {
			int[] a=new int[n+1];
			for (int i=0; i<n; i++) {
				a[i+1]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
	
}
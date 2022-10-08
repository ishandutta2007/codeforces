import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), nQ=fs.nextInt();
		int[] a=fs.readArray(n);
		for (int i=0; i<n; i++) a[i]--;
		Query[] queries=new Query[nQ], unsorted=new Query[nQ];
		for (int qq=0; qq<nQ; qq++)
			unsorted[qq]=queries[qq]=new Query(fs.nextInt(), n-1-fs.nextInt());
		Arrays.sort(queries);
//		System.out.println("Read input...");
		
		BIT bit=new BIT(n);
		int queryIndex=0;
		for (int r=0; r<n; r++) {
//			System.out.println("At r: "+r);
			if (a[r]>=r-bit.pointQuery(0) && a[r]<=r) {
				int min=0, max=r;
				while (min!=max) {
//					System.out.println("Min "+min+" "+max);
					int mid=(min+max+1)/2;
					int res=bit.pointQuery(mid);
					if (a[r]>=r-res && a[r]<=r) {
						//possible
						min=mid;
					}
					else {
						max=mid-1;
					}
				}
				bit.rangeUpdate(0, min, 1);
			}
			while (queryIndex<nQ && queries[queryIndex].r==r) {
				Query toAnswer=queries[queryIndex++];
				toAnswer.ans=bit.pointQuery(toAnswer.l);
			}
		}
		
		PrintWriter out=new PrintWriter(System.out);
		for (Query qq:unsorted) {
			out.println(qq.ans);
		}
		out.close();
	}
	
	static class Query implements Comparable<Query> {
		int l,r;
		int ans;
		public Query(int l, int r) {
			this.l=l;
			this.r=r;
		}
		
		public int compareTo(Query o) {
			return Integer.compare(r, o.r);
		}
	}
	
	static class BIT {
		int n;
		int[] tree;
		
		public BIT(int n) {
			this.n = n;
			tree = new int[n + 10];
		}
		
		int _read(int i) {
			i++;
			int sum = 0;
			while (i > 0) {
				sum += tree[i];
				i -= i & -i;
			}
			return sum;
		}
		
		void _update(int i, int val) {
			i++;
			while (i <= n) {
				tree[i] += val;
				i += i & -i;
			}
		}
		
		void rangeUpdate(int l, int r, int by) {
			_update(l, by);
			_update(r+1, -by);
		}
		
		int pointQuery(int x) {
			return _read(x);
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


	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
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
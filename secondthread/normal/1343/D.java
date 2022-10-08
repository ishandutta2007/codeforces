import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class D {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=fs.nextInt();
			int[] a=fs.readArray(n);
			BIT bit=new BIT(k*2+2);

			for (int i=0; i+i<n; i++) {
				int a1=a[i], a2=a[n-1-i];
//				System.out.println("a1+a2: "+(a1+a2));
				bit.rangeUpdate(0, Math.min(a1, a2), 1);
				bit.rangeUpdate(Math.max(a1, a2)+k+1, bit.n, 1);
				bit.rangeUpdate(0, bit.n, 1);
				bit.rangeUpdate(a1+a2, a1+a2, -1);
//				for (int j=0; j<=2*k; j++)
//					System.out.println(j+" got "+bit.pointQuery(j));
//				System.out.println();
			}
			
			int ans=Integer.MAX_VALUE;
			for (int i=0; i<=2*k; i++) {
//				System.out.println(i+" got "+bit.pointQuery(i));
				ans=Math.min(ans, bit.pointQuery(i));
			}
			System.out.println(ans);
		}
	}
	
	static class BIT {
		int n;
		int[] tree;
		
		public BIT(int n) {
			this.n = n;
			tree = new int[n + 2];
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
		
		public int pointQuery(int i) {
			return read(i);
		}
		
		public void rangeUpdate(int l, int r, int d) {
			if (r<l) return;
			update(l, d);
			update(r+1, -d);
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
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
	
}
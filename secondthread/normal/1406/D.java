import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		BIT bit=new BIT(n);
		for (int i=0; i<n; i++) bit.rangeUpdate(i, i, fs.nextInt());
		long dec=0, inc=0;
		for (int i=0; i+1<n; i++) {
			dec+=Math.max(0, bit.at(i)-bit.at(i+1));
			inc+=Math.max(0, bit.at(i+1)-bit.at(i));
		}
		PrintWriter out=new PrintWriter(System.out);
		out.println(solve(inc, dec, bit.at(0)));
		int q=fs.nextInt();
		for (int qq=0; qq<q; qq++) {
			int l=fs.nextInt()-1, r=fs.nextInt()-1, by=fs.nextInt();
			if (l!=0) {
				dec-=Math.max(0, bit.at(l-1)-bit.at(l));
				inc-=Math.max(0, bit.at(l)-bit.at(l-1));
			}
			if (r!=n-1) {
				dec-=Math.max(0, bit.at(r)-bit.at(r+1));
				inc-=Math.max(0, bit.at(r+1)-bit.at(r));
			}
			//TODO: range add
			bit.rangeUpdate(l, r, by);
			
			//TODO: add back in
			if (l!=0) {
				dec+=Math.max(0, bit.at(l-1)-bit.at(l));
				inc+=Math.max(0, bit.at(l)-bit.at(l-1));
			}
			if (r!=n-1) {
				dec+=Math.max(0, bit.at(r)-bit.at(r+1));
				inc+=Math.max(0, bit.at(r+1)-bit.at(r));
			}
			out.println(solve(inc, dec, bit.at(0)));
		}
		out.close();
	}
	
	static long solve(long inc, long dec, long v0) {
		long min=(long)-1e18, max=(long)1e18;
		long bestAns=max;
		while (min<=max) {
			long mid=(min+max)/2;
			long y=v0-mid;
			long mid2=mid+inc;
			long y2=y-dec;
			bestAns=Math.min(bestAns, Math.max(mid2, y));
			if (mid2<y) {
				min=mid+1;
			}
			else {
				max=mid-1;
			}
		}
		return bestAns;
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
	
	static class BIT {
		int n;
		long[] tree;
		
		public BIT(int n) {
			this.n = n;
			tree = new long[n + 2];
		}
		
		long _read(int i) {
			i++;
			long sum = 0;
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
		
		long at(int at) {
			return _read(at);
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
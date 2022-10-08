import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

/* 
 * Subscribe to galen_colin!
 * https://tinyurl.com/galencolin
*/

/*
1
3
0 1
1 2
2 3
 */

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			Seg[] segs=new Seg[n];
			for (int i=0; i<n; i++) segs[i]=new Seg(fs.nextInt(), fs.nextInt());
			TreeSet<Integer> xs=new TreeSet<>();
			for (Seg s:segs) xs.add(s.l);
			for (Seg s:segs) xs.add(s.r);
			HashMap<Integer, Integer> compress=new HashMap<>();
			for (int i:xs) compress.put(i, compress.size());
			
			for (Seg s:segs) {
				s.l=compress.get(s.l);
				s.r=compress.get(s.r);
			}
			
			BIT bit=new BIT(compress.size()+1);
			Event[] events=new Event[2*n];
			int index=0;
			for (Seg s:segs) {
				events[index++]=new Event(s.l, s.r, true);
				events[index++]=new Event(s.l, s.r, false);
			}
			Arrays.sort(events);
			int ans=0;
			for (Event e:events) {
				if (e.start)
					bit.update(e.x2, 1);
				else
					ans=Math.max(ans, bit.query(e.x1, compress.size()));
			}
			out.println(n-ans);
		}
		out.close();
	}
	
	static class Seg {
		int l, r;
		public Seg(int l, int r) {
			this.l=l;
			this.r=r;
		}
	}

	static class Event implements Comparable<Event> {
		int x1, x2;
		boolean start;
		public Event (int x1, int x2, boolean start) {
			this.x1=x1;
			this.x2=x2;
			this.start=start;
		}
		
		int x() {
			if (start) return x1;
			return x2;
		}
		
		public int compareTo(Event o) {
			if (x()!=o.x())
				return Integer.compare(x(), o.x());
			if (start==o.start) return 0;
			if (start) return -1;
			return 1;
		}
	}
	
	static class BIT {
		int n, tree[];

		public BIT(int N) {
			n=N;
			tree=new int[N+1];
		}

		void update(int i, int val) {
			for (i++; i<=n; i+=i&-i)
				tree[i]+=val;
		}

		int read(int i) {
			int sum=0;
			for (i++; i>0; i-=i&-i)
				sum+=tree[i];
			return sum;
		}

		// query sum of [l, r] inclusive
		int query(int l, int r) {
			return read(r)-read(l-1);
		}

		// if the BIT is a freq array, returns the index of the
		// kth item (0-indexed), or n if there are <= k items.
		int getKth(int k) {
			if (k<0)
				return -1;
			int i=0;
			for (int pw=Integer.highestOneBit(n); pw>0; pw>>=1)
				if (i+pw<=n&&tree[i+pw]<=k)
					k-=tree[i+=pw];
			return i;
		}
	}

	static void ruffle_sort(int[] a) {
		// shandom_ruffle
		Random r=new Random();
		int n=a.length;
		for (int i=0; i<n; i++) {
			int oi=r.nextInt(i);
			int temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
		}

		// sort
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
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

}
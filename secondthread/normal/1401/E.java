import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nHorizontal=fs.nextInt(), nVertical=fs.nextInt();
		ArrayList<Event> events=new ArrayList<>();
		for (int i=0; i<nHorizontal; i++) {
			int y=fs.nextInt(), x1=fs.nextInt(), x2=fs.nextInt();
			if (x2==1_000_000) x2++;
			events.add(new Event(x1, 1, y, y));
			events.add(new Event(x2, -1, y, y));
		}
		for (int i=0; i<nVertical; i++) {
			int x=fs.nextInt(), y1=fs.nextInt(), y2=fs.nextInt();
			events.add(new Event(x, 0, y1, y2));
		}
		events.add(new Event(1_000_000, 0, 0, 1_000_000));
		Collections.sort(events);
		TreeSet<Integer> noEndpoints=new TreeSet<>();
		BIT bit=new BIT(1_000_001);
		bit.update(0, 1);
		bit.update(1_000_000, 1);
		long parts=0;
		for (Event e:events) {
//			System.out.println("Processing "+e);
			if (e.delta==1) {
				if (e.x==0) {
					//just add it
					bit.update(e.y1, 1);
				}
				else {
					noEndpoints.add(e.y1);
				}
			}
			else if (e.delta==-1) {
				bit.update(e.y1, -1);
			}
			else {
				int nIntersect=bit.rangeSum(e.y1, e.y2);
				parts+=nIntersect-1;
//				System.out.println("  Intersect "+nIntersect);
				if (e.y1==0) {
					while (!noEndpoints.isEmpty() && noEndpoints.first()<=e.y2) {
						int first=noEndpoints.first();
						noEndpoints.remove(first);
						bit.update(first, 1);
					}
				}
				else {
					while (!noEndpoints.isEmpty() && noEndpoints.last()>=e.y1) {
						int last=noEndpoints.last();
						noEndpoints.remove(last);
						bit.update(last, 1);
					}
				}
			}
		}
		System.out.println(parts);
	}
	
	
	static class Event implements Comparable<Event> {
		int x;
		int delta;//0 for queries
		int y1=-1;
		int y2=-1;
		
		public Event(int x, int delta, int y1, int y2) {
			this.x=x;
			this.delta=delta;
			this.y1=y1;
			this.y2=y2;
		}
		
		public int compareTo(Event o) {
			if (x!=o.x)
				return Integer.compare(x, o.x);
			return -Integer.compare(delta, o.delta);
		}
		
		public String toString() {
			return "x: "+x+" y1: "+y1+" y2: "+y2+" delta: "+delta;
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
		
		int rangeSum(int from, int to) {
			return read(to)-read(from-1);
		}
		
		void update(int i, int val) {
			i++;
			while (i <= n) {
				tree[i] += val;
				i += i & -i;
			}
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
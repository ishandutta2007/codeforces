import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class _526E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Vec[] points=new Vec[n];
		for (int i=0; i<n; i++) points[i]=new Vec(fs.nextInt(), fs.nextInt(), fs.nextLong());
		Arrays.sort(points);
		/*
		ConvexHullLinear cho=new ConvexHullLinear(n, -1, -1, true);
		long ans=0;
		for (int i=0; i<n; i++) {
			long prevBest=i==0?0:cho.query(points[i].y);
			long curVal=prevBest + points[i].x*points[i].y - points[i].cost;
			ans=Math.max(ans, curVal);
			cho.add(-points[i].x, curVal);
		}*/
//		CHT cho=new CHT(1);
		ConvexHullLinear cho=new ConvexHullLinear(n+1, -1, -1, true);
		cho.add(0, 0);
		long ans=0;
		for (int i=0; i<n; i++) {
			long prevBest=i==0?0:cho.query(points[i].y);
			long curVal=prevBest + points[i].x*points[i].y - points[i].cost;
			ans=Math.max(ans, curVal);
			cho.add(-points[i].x, curVal);
		}
		System.out.println(ans);
	}
	
	static class Vec implements Comparable<Vec> {
		long x, y, cost;
		public Vec(long x, long y, long cost) {
			this.x=x;
			this.y=y;
			this.cost=cost;
		}
		public int compareTo(Vec o) {
			return Long.compare(x, o.x);
		}
	}
	/*Linear version of Convex hull optimization. Written by Joshua Fair
	Constructor(a, b, c, d):
	a = max number of lines that will be added
	b = 1 if lines are added in increasing slope and -1 if added in decreasing order
	c =
		-1 if points are queried in order from large X to small X
		0 if the query points are in no specific order
		1 if the points are queries in order from small X to large X
	d = true if the queries are max, and false if the queries are min
	!!! If you add lines in one order and query points in the opposite order, it will only be linear if all lines are 
	added before any points are queried !!!
	*/
	static class ConvexHullLinear {
		boolean upd, isMin;
		int type, inc, s, p;
		long[] ms,bs;
		public ConvexHullLinear(int numLines, int ii, int tt, boolean mm) {
			s = -1;
			p = 0;
			ms = new long[numLines];
			bs = new long[numLines];
			inc = ii;
			type = tt;
			isMin = !mm;
			upd = false;
			if(isMin) inc = -inc;
		}
		public void add(long m, long b) {
			if(isMin) { m=-m; b=-b; }
			if(s >= 0 && ms[s] == m && b <= bs[s]) return;
			upd = true;
			s++;
			ms[s] = m;
			bs[s] = b;
			while((s > 0 && ms[s] == ms[s-1] && bs[s] >= bs[s-1])
				|| (s-2 >= 0 && bad(s-2,s-1,s))) {
				ms[s-1] = m;
				bs[s-1] = b;
				s--;
			}
		}
		public long query(long x) {
			return wrapper(x) * (isMin ? -1 : 1);
		}
		public long wrapper(long x) {
			if(p > s || (upd && type*inc < 0)) p = s;
			upd = false;
			if(type == 0) { //Binary search in log(n)
				int lo = 0;
				int hi = s;
				while(lo < hi) {
					int mid = lo + (hi-lo)/2;
					if(eval(mid,x) < eval(mid+1,x)) lo = mid+1;
					else hi = mid;
				}
				return eval(lo,x);
			}
			else if(type*inc < 0) { //search from p -> 0
				while(p >= 1 && eval(p,x) < eval(p-1,x)) p--;
				return eval(p, x);
			}
			else { //search from p -> s
				while(p < s && eval(p,x) < eval(p+1,x)) p++;
				return eval(p, x);
			}
		}
		public boolean bad(int l1, int l2, int l3) {
			if(inc == 1) return intersect(l2,l3) <= intersect(l1,l2);
			return intersect(l2,l3) >= intersect(l1,l2);
		}
		public double intersect(int l1, int l2) {
			return (double)(bs[l2]-bs[l1])/(double)(ms[l1]-ms[l2]);
		}
		public long eval(int l1, long x) { 
			return ms[l1]*x + bs[l1]; 
		}
	}

	static class CHT {
		TreeSet<Line> hull;
		int type;  boolean query  = false;
		Comparator<Line> comp = new Comparator<Line>() {
			public int compare(Line a, Line b) {
				if (!query) return type * Long.compare(a.m, b.m);
				if (a.left == b.left) return Long.compare(a.m, b.m);
				return Double.compare(a.left, b.left);
			}
		};
		// -1 for min; +1 for max
		public CHT(int typee) { type = typee;  hull = new TreeSet<>(comp); }

		public void add(long m, long b) { add(new Line(m, b)); }

		public void add(Line a) {
			Line[] LR = { hull.lower(a), hull.ceiling(a) };
			for (int i = 0; i < 2; i++)
				if (LR[i] != null && LR[i].m == a.m) {
					if (type == 1 && LR[i].b >= a.b) return;
					if (type == -1 && LR[i].b <= a.b) return;
					remove(LR[i]);
				}
			hull.add(a);
			Line L = hull.lower(a), R = hull.higher(a);
			if (L != null && R != null && a.inter(R) <= R.left) {
				hull.remove(a);
				return;
			}
			Line LL = (L != null) ? hull.lower(L) : null;
			Line RR = (R != null) ? hull.higher(R) : null;
			if (L != null) a.left = a.inter(L);
			if (R != null) R.left = a.inter(R);
			while (LL != null && L.left >= a.inter(LL)) {
				remove(L);
				a.left = a.inter(L = LL);
				LL = hull.lower(L);
			}
			while (RR != null && R.inter(RR) <= a.inter(RR)) {
				remove(R);
				RR.left = a.inter(R = RR);
				RR = hull.higher(R);
			}
		}

		public long query(long x) {
			Line temp = new Line(0, 0, 0);
			temp.left = x;  query = true;
			long ans = (long) hull.floor(temp).eval(x);
			query = false;  return ans;
		}

		private void remove(Line x) { hull.remove(x); }

		public int size() { return hull.size(); }

		static class Line {
			long m, b; double left = Long.MIN_VALUE;
			public Line(long mm, long x, long y) { m = mm; b = -m * x + y; }
			public Line(long mm, long bb) { m = mm; b = bb; }
			public long eval(long x) { return m * x + b; }
			public double inter(Line x) {
				return (double) (x.b - this.b) / (double) (this.m - x.m);
			}
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
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

}
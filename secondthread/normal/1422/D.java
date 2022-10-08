import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		fs.next();
		int n=fs.nextInt();
		Vec start=new Vec(fs.nextInt(), fs.nextInt()), 
				end=new Vec(fs.nextInt(), fs.nextInt());
		
		Vec[] points=new Vec[n];
		for (int i=0; i<n; i++) points[i]=new Vec(fs.nextInt(), fs.nextInt());
		
		Arrays.sort(points, (a, b) -> {
			return Integer.compare(a.x, b.x);
		});
		for (int i=1; i<n; i++) {
			int dx=points[i].x-points[i-1].x;
			points[i-1].adj.add(points[i]);
			points[i-1].cost.add((long)dx);
			points[i].adj.add(points[i-1]);
			points[i].cost.add((long)dx);
		}
		Arrays.sort(points, (a, b) -> {
			return Integer.compare(a.y, b.y);
		});
		for (int i=1; i<n; i++) {
			int dy=points[i].y-points[i-1].y;
			points[i-1].adj.add(points[i]);
			points[i-1].cost.add((long)dy);
			points[i].adj.add(points[i-1]);
			points[i].cost.add((long)dy);
		}
		
		for (Vec v:points) {
			start.adj.add(v);
			start.cost.add((long)Math.min(Math.abs(start.x-v.x), 
					Math.abs(start.y-v.y)));
			end.adj.add(v);
			end.cost.add((long)Math.abs(end.x-v.x) 
					+ Math.abs(end.y-v.y));
		}
		
		dij(end, points);
		for (Vec v:points) v.d2=v.d1;
		dij(start, points);
		long ans=Math.abs(start.x-end.x)+Math.abs(start.y-end.y);
		for (Vec v:points) {
//			System.out.println(v+" "+v.d1+" "+v.d2);
			ans=Math.min(v.d1+v.d2, ans);
		}
		
		System.out.println(ans);
	}
	
	static class Vec {
		int x,y;
		ArrayList<Vec> adj=new ArrayList<>();
		ArrayList<Long> cost=new ArrayList<>();
		long d1=Long.MAX_VALUE, d2=Long.MAX_VALUE;
		public Vec(int x, int y) {
			this.x=x;
			this.y=y;
		}
		
		public String toString() {
			return "("+x+", "+y+")";
		}
	}
	
	static class State implements Comparable<State> {
		Vec n;
		long dist;
		public State(Vec n, long dist) {
			this.dist=dist;
			this.n=n;
		}
		
		public int compareTo(State o) {
			return Long.compare(dist, o.dist);
		}
	}
	
	static void dij(Vec from, Vec[] points) {
		PriorityQueue<State> pq=new PriorityQueue<>();
		from.d1=0;
		for (Vec v:points) v.d1=Long.MAX_VALUE;
		pq.add(new State(from, 0));
		while (!pq.isEmpty()) {
			State next=pq.remove();
			if (next.dist!=next.n.d1)
				continue;
			for (int i=0; i<next.n.adj.size(); i++) {
				Vec to=next.n.adj.get(i);
				long newCost=next.dist+next.n.cost.get(i);
				if (newCost<to.d1) {
					to.d1=newCost;
					pq.add(new State(to, to.d1));
				}
			}
		}
		
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
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
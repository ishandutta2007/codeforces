import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Random;
import java.util.StringTokenizer;

/*

1
1 1
5
5

1
7 1
1 5 2 3 1 5 4
1 3 6 7 2 5 4

 */
public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int nPoints=fs.nextInt(), length=fs.nextInt();
			ArrayList<Event> events1=new ArrayList<>();
			ArrayList<Event> events2=new ArrayList<>();
			
			int[] xs=fs.readArray(nPoints);
			for (int i=0; i<xs.length; i++) xs[i]*=2;
			length*=2;
			fs.readArray(nPoints);
			for (int i:xs) {
				events1.add(new Event(i, 1));
				events1.add(new Event(i+length, -1));
				events2.add(new Event(i-length, -1));
				events2.add(new Event(i, 1));
				
				events1.add(new Event(i-length+1, 0));
				events1.add(new Event(i+1, 0));
				events1.add(new Event(i+length+1, 0));
				events1.add(new Event(i-length-1, 0));
				events1.add(new Event(i-1, 0));
				events1.add(new Event(i+length-1, 0));
				
				events2.add(new Event(i-length+1, 0));
				events2.add(new Event(i+1, 0));
				events2.add(new Event(i+length+1, 0));
				events2.add(new Event(i-length-1, 0));
				events2.add(new Event(i-1, 0));
				events2.add(new Event(i+length-1, 0));
			}
			
			ArrayList<Integer> m1=go(events1);
			ArrayList<Integer> m2=go2(events2);
			if (m1.size()!=m2.size()) throw null;
			int ans=0;
			for (int i=0; i<m1.size(); i++)
				ans=Math.max(m1.get(i)+m2.get(m2.size()-1-i), ans);
			out.println(ans);
		}
		out.close();
	}
	
	static ArrayList<Integer> go(ArrayList<Event> events) {
		ArrayList<Integer> res=new ArrayList<>();
		Collections.sort(events);
		int bestSeen=0;
		int curIntersect=0;
		for (Event e:events) {
			if (e.d==0) res.add(bestSeen);
			curIntersect+=e.d;
			bestSeen=Math.max(bestSeen, curIntersect);
		}
		return res;
	}
	
	static ArrayList<Integer> go2(ArrayList<Event> events) {
		ArrayList<Integer> res=new ArrayList<>();
		for (Event e:events) e.x*=-1;
		Collections.sort(events);
		for (Event e:events) e.x*=-1;
		int bestSeen=0;
		int curIntersect=0;
		for (Event e:events) {
			if (e.d==0) res.add(bestSeen);
			curIntersect+=e.d;
			bestSeen=Math.max(bestSeen, curIntersect);
		}
		return res;
	}
	
	static class Event implements Comparable<Event> {
		int x, d;//0 if query
		public Event(int x, int d) {
			this.x=x;
			this.d=d;
		}
		
		public int compareTo(Event o) {
			if (x!=o.x)return Integer.compare(x, o.x);
			return Integer.compare(o.d, d);
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
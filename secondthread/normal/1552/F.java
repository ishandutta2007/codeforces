import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class F {
	
	static long mod=998244353;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Event[] events=new Event[2*n];
		Event[] endEvents=new Event[n];
		for (int i=0; i<n; i++) {
			int end=fs.nextInt(), start=fs.nextInt();
			boolean on=fs.next().equals("1");
			Event startEvent=new Event(start, on, null);
			Event endEvent=new Event(end, on, startEvent);
			events[2*i]=startEvent;
			endEvents[i]=events[2*i+1]=endEvent;
		}
		long ans=endEvents[n-1].x+1;
		Arrays.sort(events);
		long times=1;
		for (Event e:events) {
			if (e.earlier!=null) {
				//end
				long timesEdgeTaken;
				if (e.on) {
					timesEdgeTaken = times;
				}
				else {
					timesEdgeTaken = times-1;
				}
				times=add(times, timesEdgeTaken);
				e.timesEdgeUsed=e.earlier.timesEdgeUsed=timesEdgeTaken;
			}
			else {
				//start
				times=sub(times, e.timesEdgeUsed);
			}
		}
//		System.out.println(ans);
		for (Event e:endEvents) {
//			System.out.println("Event ending at "+e.x+" was hit "+e.timesEdgeUsed+" times");
			ans=add(ans, mul(e.timesEdgeUsed, e.x-e.earlier.x));
		}
		System.out.println(ans);
	}
	
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return (a-b+mod)%mod;
	}
	static long mul(long a, long b) {
		return a*b%mod;
	}
	
	static class Event implements Comparable<Event> {
		int x;
		boolean on;
		long timesEdgeUsed;
		Event earlier;
		public Event(int x, boolean on, Event earlier) {
			this.x=x;
			this.on=on;
			this.earlier=earlier;
		}
		
		public int compareTo(Event o) {
			return Integer.compare(o.x, x);
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
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Seg[] segs=new Seg[n];
		for (int i=0; i<n; i++)
			segs[i]=new Seg(fs.nextInt(), fs.nextInt());
		Event[] events=new Event[2*n];
		int index=0;
		for (Seg s:segs) {
			events[index++]=new Event(s.from, true, s);
			events[index++]=new Event(s.to, false, s);
		}
		Arrays.sort(events);
		int numDeep=0;
		long timesNDeep=0;
		long timesNm1Deep=0;
		for (int e=0; e<events.length; e++) {
			if (numDeep==n) {
				timesNDeep+=events[e].x-events[e-1].x;
			}
			if (numDeep==n-1) {
				timesNm1Deep+=events[e].x-events[e-1].x;
			}
			Seg s=events[e].s;
			if (events[e].start) {
				s.nDeepBefore=timesNDeep;
				s.nm1DeepBefore=timesNm1Deep;
				numDeep++;
			}
			else {
				s.nDeepAfter=timesNDeep;
				s.nm1DeepAfter=timesNm1Deep;
				numDeep--;
			}
			
		}
		//numNs+numN-1s-myNumN-1s
		long best=0;
		for (Seg s:segs) {
			long score=timesNDeep+timesNm1Deep-(s.nm1DeepAfter-s.nm1DeepBefore);
			best=Math.max(best, score);
		}
		System.out.println(best);
	}
	
	
	static class Event implements Comparable<Event> {
		boolean start;
		long x;
		Seg s;
		
		public Event(int x, boolean start, Seg s) {
			this.x=x;
			this.start=start;
			this.s=s;
		}
		
		public int compareTo(Event o) {
			return Long.compare(x, o.x);
		}
	}

	static class Seg {
		int from, to;
		long nDeepBefore, nDeepAfter, nm1DeepBefore, nm1DeepAfter;
		public Seg(int from, int to) {
			this.from=from;
			this.to=to;
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
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
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}
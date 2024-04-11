import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class C2 {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nTimes=fs.nextInt();
		int dayLength=fs.nextInt();
		int minMinutes=fs.nextInt();
		Break[] breaks=new Break[nTimes];
		for (int i=0; i<nTimes; i++)
			breaks[i]=new Break(i, fs.nextInt());
		Arrays.sort(breaks);
		PriorityQueue<Event> pq=new PriorityQueue<>();
		int[] ans=new int[nTimes];
		for (Break b:breaks) {
			if (!pq.isEmpty()&&pq.peek().nextTime<=b.time) {
				Event o=pq.remove();
				ans[b.oIndex]=o.day;
				pq.add(new Event(o.day, b.time+minMinutes+1));
			}
			else {
				ans[b.oIndex]=pq.size();
				pq.add(new Event(pq.size(), b.time+minMinutes+1));
			}
		}
		System.out.println(pq.size());
		for (int i=0; i<ans.length; i++)
			System.out.print(ans[i]+1+" ");
		System.out.println();
	}
	
	static class Event implements Comparable<Event> {
		int day, nextTime;
		public Event(int day, int nextTime) {
			this.day=day;
			this.nextTime=nextTime;
		}
		
		public int compareTo(Event o) {
			return Integer.compare(nextTime, o.nextTime);
		}
	}
	
	static class Break implements Comparable<Break> {
		int oIndex, time;
		public Break(int oIndex, int time) {
			this.oIndex=oIndex;
			this.time=time;
		}
		
		public int compareTo(Break o) {
			return Integer.compare(time, o.time);
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
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}
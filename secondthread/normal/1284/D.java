import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeMap;
/*
5 6 4 14
1 2 3 4 5
1 5 2
1 2 5
2 3 5
3 5 3

 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Lecture[] lectures=new Lecture[n];
		for (int i=0; i<n; i++) lectures[i]=new Lecture(fs.nextInt(), fs.nextInt()+1, fs.nextInt(), fs.nextInt()+1);
		boolean possible1=possible(lectures);
		for (Lecture l:lectures) {
			int t=l.startA;
			l.startA=l.startB;
			l.startB=t;
			t=l.endA;
			l.endA=l.endB;
			l.endB=t;
		}
		boolean possible2=possible(lectures);
		if (possible1 && possible2) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
	
	static boolean possible(Lecture[] lectures) {
		ArrayList<Event> events=new ArrayList<>();
		for (Lecture l:lectures) {
			events.add(new Event(l, l.startA, true));
			events.add(new Event(l, l.endA, false));
		}
		Collections.sort(events);
		TreeMap<Integer, Integer> startsOf=new TreeMap<>();
		TreeMap<Integer, Integer> endsOf=new TreeMap<>();
		for (Event e:events) {
			Lecture l=e.l;
			if (e.start) {
//				System.out.println("Adding in "+l);
				startsOf.put(l.startB, startsOf.getOrDefault(l.startB, 0)+1);
				endsOf.put(l.endB, endsOf.getOrDefault(l.endB, 0)+1);
			}
			else {
//				System.out.println("Removing "+l);
				removeFrom(startsOf, l.startB);
				removeFrom(endsOf, l.endB);
			}
			//All these things need to overlap now
			if (!startsOf.isEmpty()) {
				int latestStart=startsOf.lastKey();
				int firstEnd=endsOf.firstKey();
				if (latestStart>=firstEnd) {
					return false;
				}
			}
		}
		
		return true;
	}
	
	static class Lecture {
		int startA, endA;
		int startB, endB;
		
		public Lecture(int startA, int endA, int startB, int endB) {
			this.startA=startA;
			this.endA=endA;
			this.startB=startB;
			this.endB=endB;
		}
		
		public String toString() {
			return startA+" "+endA+" "+startB+" "+endB;
		}
	}
	
	static void removeFrom(TreeMap<Integer, Integer> map, int toRemove) {
		if (map.get(toRemove)==1) map.remove(toRemove);
		else map.put(toRemove, map.get(toRemove)-1);
	}
	
	static class Event implements Comparable<Event> {
		Lecture l;
		int time;
		boolean start;
		public Event(Lecture l, int time, boolean start) {
			this.l=l;
			this.time=time;
			this.start=start;
		}
		
		public int compareTo(Event o) {
			if (time!=o.time) {
				return Integer.compare(time, o.time);
			}
			if (start==o.start) return 0;
			if (start) return 1;
			else return -1;
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		String next() {
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
	}

}
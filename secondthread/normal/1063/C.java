import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class C {

	static final boolean debug=false;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int topTimes=Math.min(n, 15);
		int bottomTimes=n-topTimes;
	
		int topLeft=0, topRight=1_000_000_000;
		for (int i=0; i<topTimes; i++) {
			int x=(topLeft+topRight)/2;
			System.out.println(x+" 1");
			System.out.flush();
			boolean white=fs.next().equals("white");
			if (white) {
				topLeft=x+1;
			}
			else {
				topRight=x-1;
			}
		}
		
		int bottomLeft=0, bottomRight=1_000_000_000;
		for (int i=0; i<bottomTimes; i++) {
			int x=(bottomLeft+bottomRight)/2;
			System.out.println(x+" 0");
			System.out.flush();
			boolean white=fs.next().equals("white");
			if (white) {
				bottomLeft=x+1;
			}
			else {
				bottomRight=x-1;
			}
		}
		System.out.println(topLeft+" 1 "+bottomLeft+" 0 ");
	}
	
	static void print(boolean[] include) {
		ArrayList<Integer> toExclude=new ArrayList<>();
		ArrayList<Integer> toInclude=new ArrayList<>();
		for (int i=0; i<include.length; i++)
			if (include[i])
				toInclude.add(i);
			else
				toExclude.add(i);
		PrintWriter out=new PrintWriter(System.out);
		for (int i=1; i<toExclude.size(); i++) {
			out.println("1 "+(toExclude.get(i)+1)+" "+(toExclude.get(0)+1));
		}
		if (!toExclude.isEmpty())
			out.println("2 "+(toExclude.get(0)+1));
		for (int i=1; i<toInclude.size(); i++) {
			out.println("1 "+(toInclude.get(i)+1)+" "+(toInclude.get(0)+1));
		}
		out.close();
	}
	
	static class Event implements Comparable<Event> {
		int person;
		int time;
		int peopleThere;
		public Event(int person, int time, int peopleThere) {
			this.person=person;
			this.time=time;
			this.peopleThere=peopleThere;
		}
		
		public int compareTo(Event o) {
			return Integer.compare(time, o.time);
		}
		
		public String toString() {
			return "Person: "+person+", time: "+time+", people there: "+peopleThere;
		}
	}
	
	static class Person implements Comparable<Person> {
		int maxStart=Integer.MAX_VALUE, minEnd=Integer.MIN_VALUE;
		int index;
		
		public Person(int index) {
			this.index=index;
		}
		
		public int compareTo(Person o) {
			int endComp=Integer.compare(minEnd, o.minEnd);;
			if (endComp!=0)
				return endComp;
			return Integer.compare(index, o.index);
		}
		
		public String toString() {
			return "Person "+index+"maxStart: "+maxStart+" minEnd: "+minEnd;
		}
	}

	static class FastScanner {
		StringTokenizer st = new StringTokenizer("");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		public String next() {
			while (!st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public int[] readArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

	}
	
}
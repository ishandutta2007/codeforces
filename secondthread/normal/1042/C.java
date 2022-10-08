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
		int[] a=fs.readArray(n);
		int negCount=0;
		int posCount=0;
		int negIndexToRemove=-1;
		for (int i:a) if (i<0) negCount++;
		for (int i:a) if (i>0) posCount++;
		for (int i=0; i<n; i++) {
			if (a[i]<0)
				if (negIndexToRemove==-1||a[negIndexToRemove]<a[i])
					negIndexToRemove=i;
		}
		//remove the smallest odd negative
		//if there are 2 or more negatives or at least 1 positive, remove all zeros
		boolean[] include=new boolean[n];
		Arrays.fill(include, true);
		if (negCount%2==1) {
			include[negIndexToRemove]=false;
		}
		if (negCount>1||posCount>=1) {
			for (int i=0; i<n; i++) {
				if (a[i]==0) include[i]=false;
			}
		}
		print(include);
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
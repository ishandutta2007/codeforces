import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class E {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		for (int i=0; i<n; i++)
			a[i]--;
		
		Event[] events=new Event[2*n];
		for (int i=0; i<n; i++) {
			events[2*i]=new Event(true, i, Math.min(n, a[i]));
			events[2*i+1]=new Event(false, Math.min(i, a[i]+1), i);
		}
		Arrays.sort(events);
		
		FenwickTree bit=new FenwickTree(n+2);
		long count=0;
		for (Event e:events) {
			if (e.isIndex) {
				bit.update(e.value, 1);
			}
			else {
				count+=bit.sum(e.value, n);
			}
		}
		System.out.println(count);
	}
	
	static class Event implements Comparable<Event> {
		boolean isIndex;//otherwise its a query
		int time;
		int value;
		
		public Event(boolean isIndex, int time, int value) {
			this.isIndex=isIndex;
			this.time=time;
			this.value=value;
		}

		public int compareTo(Event o) {
			int tmpCmp=Integer.compare(time, o.time);
			if (tmpCmp!=0)return tmpCmp;
			if (isIndex==o.isIndex)
				return 0;
			
			//do queries before updating indecies
			if (isIndex)
				return 1;
			else
				return -1;
		}
		
	}
	
	static class FenwickTree {
		int[] vs;
		public FenwickTree (int s) {
			vs=new int[s+5];
		}
		
		public long sum(int idx) {
			idx++;
			long ret=0;
			for (int i=idx; i>0; i-=(i&-i))
				ret+=vs[i];
			return ret;
		}
		
		public long sum(int from, int to) {
			return sum(to)-sum(from-1);
		}
		
		public void update(int idx, int v) {
			idx++;
			for (int i=idx; i<vs.length; i+=(i&-i))
				vs[i]+=v;
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
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		
	}

}
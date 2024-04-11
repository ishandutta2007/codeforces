

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class C {

	public static void solve(FastScanner fs) {	
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int nProblems=fs.nextInt();
			int time=fs.nextInt();
			int easyTime=fs.nextInt(), hardTime=fs.nextInt();
			int nEasy=0, nHard=0;
			boolean[] easy=new boolean[nProblems];
			for (int i=0; i<nProblems; i++) easy[i]=fs.nextInt()==0;
			for (boolean b:easy) if (b) nEasy++; else nHard++;
			
			TreeSet<Integer> times=new TreeSet<>();
			times.add(0);
			times.add(time);
			PriorityQueue<Event> events=new PriorityQueue<>();
			for (int i=0; i<nProblems; i++) {
				int t=fs.nextInt();
				times.add(t);
				times.add(t-1);
				events.add(new Event(easy[i], t));
			}
			
			int easyReq=0, hardReq=0;
			long best=0;
			for (int toTake:times) {
				while (!events.isEmpty() && events.peek().time==toTake) {
					Event next=events.poll();
					if (next.easy) easyReq++;
					else hardReq++;
				}
				
				long timeLeft=toTake-easyTime*(long)easyReq-hardTime*(long)hardReq;
				if (timeLeft<0) continue;
				int easyLeft=nEasy-easyReq, hardLeft=nHard-hardReq;
				
				long bought=easyReq+hardReq;
				long easyBuy=Math.min(easyLeft, timeLeft/easyTime);
				timeLeft-=easyBuy*easyTime;
				long hardBuy=Math.min(hardLeft, timeLeft/hardTime);
				
				best=Math.max(best, bought+easyBuy+hardBuy);
			}
			out.println(best);
		}
		out.close();
		
	}

	
	static class Event implements Comparable<Event> {
		boolean easy;
		int time;
		public Event(boolean easy, int time) {
			this.easy=easy;
			this.time=time;
		}
		
		public int compareTo(Event o) {
			return Integer.compare(time, o.time);
		}
	}
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}
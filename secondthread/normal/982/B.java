import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B {
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Seat[] seats=new Seat[n];
		for (int i=0; i<n; i++)
			seats[i]=new Seat(fs.nextInt(), i+1);
		char[] type=fs.next().toCharArray();
		PriorityQueue<Seat> empty=new PriorityQueue<>();
		PriorityQueue<Seat> partFull=new PriorityQueue<>() ;
		for (Seat s:seats) empty.add(s);
		for (int i=0; i<2*n; i++) {
			if (type[i]=='0') {
				Seat s=empty.remove();
				System.out.print(s.indexOf+" ");
				s.partFull=true;
				partFull.add(s);
			}
			else {
				System.out.print(partFull.remove().indexOf+" ");
			}
		}
	}

	static class Seat implements Comparable<Seat> {
		int width;
		boolean partFull;
		int indexOf;
		public Seat(int width, int indexOf) {
			this.width=width;
			this.indexOf=indexOf;
			this.partFull=false;
		}
		public int compareTo(Seat o) {
			if (partFull) {
				return Integer.compare(o.width, width);
			}
			return width-o.width;
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
	}
	
}
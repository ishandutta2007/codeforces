import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		if (n==3) {
			System.out.println("1 2 3");
			return;
		}
		int steps=0;
		Kid[] kids=new Kid[n];
		for (int i=0; i<n; i++) {
			kids[i]=new Kid(fs.nextInt()-1, fs.nextInt()-1, i);
		}
		Kid cur=kids[0];
		while (steps<n) {
			System.out.print((cur.id+1)+" ");
			steps++;
			if (cur.canComeAfter(kids[cur.next1]))
				cur=kids[cur.next1];
			else
				cur=kids[cur.next2];
		}
	}
	static class Kid {
		int id;
		int next1, next2;
		public Kid(int next1, int next2, int id) {
			this.next1=next1;
			this.next2=next2;
			this.id=id;
		}
		
		public boolean canComeAfter(Kid o) {
			return o.next1==next1||o.next2==next2||o.next1==next2||o.next2==next1;
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
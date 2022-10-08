import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] board=fs.readArray(n);
		Space[] spaces=new Space[n];
		for (int i=0; i<n; i++) spaces[i]=new Space(board[i], i);
		Arrays.sort(spaces);
		boolean[] losingSpaces=new boolean[n];
		for (int i=n-1; i>=0; i--) {
			Space cur=spaces[i];
			boolean canHitLose=false;
			for (int dx=0; dx<=n; dx+=spaces[i].value) {
				int newPos=cur.pos+dx;
				if (newPos<0||newPos>=n) continue;
				if (board[newPos]>cur.value && losingSpaces[newPos]) {
					canHitLose=true;
				}
			}
			for (int dx=0; dx<=n; dx+=spaces[i].value) {
				int newPos=cur.pos-dx;
				if (newPos<0||newPos>=n) continue;
				if (board[newPos]>cur.value && losingSpaces[newPos]) {
					canHitLose=true;
				}
			}
			losingSpaces[cur.pos]=!canHitLose;
		}
		for (int i=0; i<n; i++) {
			System.out.print(losingSpaces[i]?"B":"A");
		}
		System.out.println();
	}
	
	static class Space implements Comparable<Space>{
		int value, pos;
		public Space(int value, int pos) {
			this.value=value;
			this.pos=pos;
		}
		
		public int compareTo(Space o) {
			return Integer.compare(value, o.value);
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
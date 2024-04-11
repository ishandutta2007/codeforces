import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		int[][] board=new int[n][n];
		solve(board, a, 0);
		PrintWriter out=new PrintWriter(System.out);
		for (int y=0; y<n; y++) {
			for (int x=0; x<=y; x++) {
				if (x!=0) out.print(' ');
				out.print(board[x][y]);
			}
			out.println();
		}
		out.close();
	}
	
	static void solve(int[][] board, int[] a, int turn) {
		if (a.length==0) return;
		//fill diagonal
		for (int i=0; i<a.length; i++) {
			int x=i;
			int y=turn+i;
			board[x][y]=a[i];
		}
		int mindex=0;
		for (int i=0; i<a.length; i++) if (a[mindex]>a[i]) mindex=i;
		int[] newA=new int[a.length -1];
		for (int i=0; i<mindex; i++) newA[i]=a[i];
		for (int i=mindex+1; i<a.length; i++) newA[i-1]=a[i];
		solve(board, newA, turn+1);
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
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
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}
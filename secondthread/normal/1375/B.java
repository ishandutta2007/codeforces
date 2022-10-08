import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		outer: for (int tt=0; tt<T; tt++) {
			int h=fs.nextInt(), w=fs.nextInt();
			int[][] board=new int[w][h];
			for (int y=0; y<h; y++)
				for (int x=0; x<w; x++) board[x][y]=fs.nextInt();
			if (board[0][0]>2 || board[w-1][0]>2 || board[0][h-1]>2 || board[w-1][h-1]>2) {
				out.println("NO");
				continue;
			}
			for (int x=0; x<w; x++) {
				for (int y=0; y<h; y++) {
					if (board[x][y]>4) {
						out.println("NO");
						continue outer;
					}
					if ((x==0||y==0||x==w-1||y==h-1) && board[x][y]>3) {
						out.println("NO");
						continue outer;
					}
				}
			}
			out.println("YES");
			for (int y=0; y<h; y++) {
				for (int x=0; x<w; x++) {
					int val=4;
					if (x==0||x==w-1) val--;
					if (y==0||y==h-1) val--;
					out.print(val+" ");
				}
				out.println();
			}
		}
		out.close();
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
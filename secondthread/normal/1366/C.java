import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int h=fs.nextInt(), w=fs.nextInt();
			int[][] board=new int[w][h];
			for (int y=0; y<h; y++) for (int x=0; x<w; x++) board[x][y]=fs.nextInt();
			
			int length=w-1 + h-1 +1;
			ArrayList<Integer>[] groups=new ArrayList[length];
			for (int i=0; i<groups.length; i++) groups[i]=new ArrayList<>();
			for (int y=0; y<h; y++) for (int x=0; x<w; x++) {
				int position=Math.min(x+y, length-1-(x+y));
				if (x+y == (length-1-(x+y))) {
					//middle
					continue;
				}
				groups[position].add(board[x][y]);
			}
			int toChange=0;
			for (ArrayList<Integer> a:groups) {
				int nZeros=0;
				int nOnes=0;
				for (int i:a) if (i==0) nZeros++; else nOnes++;
				toChange+=Math.min(nZeros, nOnes);
			}
			System.out.println(toChange);
		}
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
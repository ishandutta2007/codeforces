import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[][] r=new int[n][5];
			for (int i=0; i<n; i++) r[i]=fs.readArray(5);
			int bestInd=0;
			for (int i=1; i<n; i++) {
				bestInd=better(bestInd, i, r);
			}
			boolean works=true;
			for (int i=0; i<n; i++) {
				if (better(bestInd, i, r)!=bestInd) works=false;
			}
			System.out.println(works?bestInd+1:"-1");
		}
	}
	
	static int better(int i, int j, int[][] r) {
		int count=0;
		for (int k=0; k<5; k++) if (r[i][k]<r[j][k]) count++;
		return count>2?i:j;
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
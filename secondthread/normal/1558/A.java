import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int aWins=fs.nextInt(), bWins=fs.nextInt();
			TreeSet<Integer> ans=new TreeSet<>();
			int totalGames=aWins+bWins;
			{
				//A first
				int plusLeft=Math.min(aWins, (totalGames+1)/2);
				int plusRight=aWins-plusLeft;
				int emptyRight=totalGames/2-plusRight;
				int emptyLeft=(totalGames+1)/2-plusLeft;
				int minScore=emptyLeft+plusRight;
				int maxAdd=Math.min(emptyRight, plusLeft);
				for (int i=0; i<=maxAdd; i++)
					ans.add(minScore+2*i);
			}
			{
				//B first
				int plusLeft=Math.min(aWins, (totalGames)/2);
				int plusRight=aWins-plusLeft;
				int emptyRight=(totalGames+1)/2-plusRight;
				int emptyLeft=(totalGames)/2-plusLeft;
				int minScore=emptyLeft+plusRight;
				int maxAdd=Math.min(emptyRight, plusLeft);
				for (int i=0; i<=maxAdd; i++)
					ans.add(minScore+2*i);
			}
			System.out.println(ans.size());
			for (int i:ans)
				System.out.print(i+" ");
			System.out.println();
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
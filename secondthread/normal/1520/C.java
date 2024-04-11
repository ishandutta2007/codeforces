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
			int n=fs.nextInt();
			if (n==1) {
				System.out.println(1);
				continue;
			}
			if (n==2) {
				System.out.println(-1);
				continue;
			}
			if (n==3) {
				System.out.println("2 9 7\n" + 
						"4 6 3\n" + 
						"1 8 5");
				continue;
			}
			int[][] grid=new int[n][n];
			int[][] newG=new int[n][n];
			int counter=1;
			for (int y=0; y<n; y++) {
				for (int x=0; x<n; x++) {
					grid[x][y]=newG[x][y]=counter++;
				}
			}
			for (int x=0; x<n; x++) {
				for (int y=0; y<n; y++) {
					if ((x+y)%2==0) continue;
					int newY=y+2;
					if (newY>=n) {
						if (n%2==0) newY%=n;
						else {
							newY=(newY)%2;
						}
					}
					newG[x][newY]=grid[x][y];
				}
			}
			for (int y=0; y<n; y++) {
				for (int x=0; x<n; x++)
					System.out.print(newG[x][y]+" ");
				System.out.println();
			}
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
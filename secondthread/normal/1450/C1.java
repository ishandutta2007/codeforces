import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/* 
 * Subscribe to galen_colin!
 * https://tinyurl.com/galencolin
*/

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[][] board=new char[n][n];
			char[][][] boards=new char[3][n][n];
			for (int y=0; y<n; y++) {
				char[] line=fs.next().toCharArray();
				for (int x=0; x<n; x++) {
					board[x][y]=line[x];
					for (int i=0; i<3; i++) boards[i][x][y]=board[x][y];
				}
			}
			int[] changes=new int[3];
			for (int x=0; x<n; x++)
				for (int y=0; y<n; y++) {
					if (board[x][y]=='.') continue;
					changes[(x+y)%3]++;
					boards[(x+y)%3][x][y]='O';
				}
			char[][] ans;
			if (changes[0]<=changes[1] && changes[0] <= changes[2]) {
				ans=boards[0];
			}
			else if (changes[1]<=changes[2]) {
				ans=boards[1];
			}
			else {
				ans=boards[2];
			}
			for (int y=0; y<n; y++) {
				for (int x=0; x<n; x++) System.out.print(ans[x][y]);
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
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

public class C2 {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		testcase: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[][] board=new char[n][n];
			for (int y=0; y<n; y++) {
				char[] line=fs.next().toCharArray();
				for (int x=0; x<n; x++) {
					board[x][y]=line[x];
				}
			}
			int[] changesX=new int[3];
			int[] changesO=new int[3];
			int nThings=0;
			for (int x=0; x<n; x++) {
				for (int y=0; y<n; y++) {
					if (board[x][y]=='.') continue;
					if (board[x][y]=='X') changesO[(x+y)%3]++;
					else changesX[(x+y)%3]++;
					nThings++;
				}
			}
			
			for (int i=0; i<3; i++) {
				for (int j=0; j<3; j++) {
					if (i==j) continue;
					if (changesX[i]+changesO[j]>nThings/3) continue;
					
					for (int y=0; y<n; y++) {
						for (int x=0; x<n; x++) {
							if (board[x][y]=='.') {
								System.out.print('.');
							}
							else {
								if ((x+y)%3==i) {
									System.out.print('X');
								}
								else if ((x+y)%3==j) {
									System.out.print('O');
								}
								else {
									System.out.print(board[x][y]);
								}
							}
						}
						System.out.println();
					}
					continue testcase;
				}
			}
			throw null;
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
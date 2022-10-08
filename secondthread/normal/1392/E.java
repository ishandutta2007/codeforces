import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		long[][] grid=new long[n][n];
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				long exp=(i+j-1);
				boolean have=(j%2!=0);
				if (have) grid[i][j]=1l<<exp;
			}
		}
		
		for (int y=0; y<n; y++) {
			for (int x=0; x<n; x++) System.out.print(grid[x][y]+" ");
			System.out.println();
		}
		System.out.flush();
		int q=fs.nextInt();
		for (int qq=0; qq<q; qq++) {
			long total=fs.nextLong();
			int x=0, y=0;
			while (x!=n && y!=n) {
				print(x, y);
				if ((total&(1l<<(x+y)))!=0) {
					//should be at odd height
					if (y%2==0) {
						y++;
					}
					else {
						x++;
					}
				}
				else {
					//even height
					if (y%2==0) {
						x++;
					}
					else {
						y++;
					}
				}
			}
			System.out.flush();
		}
				
	}
	
	static void print(int x, int y) {
		x++;
		y++;
		System.out.println(y+" "+x);
		System.out.flush();
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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
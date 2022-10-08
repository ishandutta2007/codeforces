import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/*
1
2 3
 */
public class D {

	static int ind1, ind2;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt();
		
		int[][] arrays=new int[n][m];
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				arrays[i][j]=fs.nextInt();
		int low=0, high=1000_000_001;
		while (low!=high) {
			int mid=(low+high+1)/2;
			if (possible(mid, arrays, n, m)) {
				low=mid;
			}
			else {
				high=mid-1;
			}
		}
		possible(low, arrays, n, m);
		System.out.println(ind1+" "+ind2);
	}
	
	static boolean possible(int min, int[][] arrays, int n, int m) {
		boolean[] possible=new boolean[1<<m];
		int[] used=new int[1<<m];
		int arrayInd=0;
		for (int[] a:arrays) {
			arrayInd++;
			int mask=0;
			for (int i=0; i<m; i++)
				if (a[i]>=min) mask+=1<<i;
			possible[mask]=true;
			used[mask]=arrayInd;
		}
		for (int i=0; i<1<<m; i++)
			for (int j=0; j<1<<m; j++)
				if (possible[i]&&possible[j]&&((i|j)==((1<<m)-1))) {
					ind1=used[i];
					ind2=used[j];
					return true;
				}
		return false;
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		String next() {
			while (!st.hasMoreElements())
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
	}

}
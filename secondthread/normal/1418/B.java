import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Temp {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			int[] fixed=fs.readArray(n);
			ArrayList<Integer> fix=new ArrayList<>(), free=new ArrayList<>();
			for (int i=0; i<n; i++) if (fixed[i]==1) fix.add(a[i]); else free.add(a[i]);
			Collections.sort(free);
			int freeInd=free.size()-1, fixedInd=0;
			for (int i=0; i<n; i++) {
				if (fixed[i]==1) System.out.print(fix.get(fixedInd++)+" ");
				else System.out.print(free.get(freeInd--)+" ");
			}
			System.out.println();
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
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
		
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}

}
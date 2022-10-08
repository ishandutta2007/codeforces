

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			int from=fs.nextInt(), to=fs.nextInt();
			if (Integer.bitCount(to)>Integer.bitCount(from) || to<from) {
				System.out.println("NO");
				continue;
			}

			int count=0;
			for (int i=0; i<30; i++) {
				if ((from&(1<<i))!=0) count++;
				if ((to&(1<<i))!=0) count--;
				if (count<0) {
					System.out.println("NO");
					continue outer;
				}
			}
			System.out.println("YES");
			
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
		
		int[] readArray(int n) {
			int[] a=new int[n]; 
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		int nextInt () {
			return Integer.parseInt(next());
		}
	}

}
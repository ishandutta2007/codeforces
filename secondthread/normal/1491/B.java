

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
3
2 3 4
2 2
2 3 4
3 2
2 4 3
1 10
 */
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), vCost=fs.nextInt(), hCost=fs.nextInt();
			int[] a=fs.readArray(n);
			int ans=Math.min(hCost+hCost, hCost+vCost);
			for (int i=0; i+1<n; i++) { 
				if (a[i]!=a[i+1]) ans=Math.min(ans, Math.min(hCost, vCost));
				if (Math.abs(a[i]-a[i+1])>1) ans=0;
			}
				
			
			System.out.println(ans);
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
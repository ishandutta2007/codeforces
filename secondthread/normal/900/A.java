import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class a {
	
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++) {
			a[i]=fs.nextInt();
			fs.nextInt();
		}
		
		int before=0, after=0;
		for (int i:a)
			if (i<0)
				before++;
			else
				after++;
		if (before<=1||after<=1)
			System.out.println("Yes");
		else {
			System.out.println("No");
		}
	}	
	
	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			br=new BufferedReader(new InputStreamReader(System.in));
			st=new StringTokenizer("");
		}
		
		public String next() {
			if (st.hasMoreTokens())
				return st.nextToken();
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}

}
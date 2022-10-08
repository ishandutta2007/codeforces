import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int m=fs.nextInt();
		boolean[] covered=new boolean[m+1];
		for (int i=0; i<n; i++) {
			int l=fs.nextInt(), r=fs.nextInt();
			for (int j=l; j<=r; j++)
				covered[j]=true;
		}
		int count=0;
		for (int i=1; i<=m; i++)
			if (!covered[i])
				count++;
		System.out.println(count);
		for (int i=1; i<=m; i++)
			if (!covered[i])
				System.out.print(i+" ");
		System.out.println();
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
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		
	}

}
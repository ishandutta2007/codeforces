import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int m=fs.nextInt();
		int[] counts=new int[n];
		int p=0;
		for (int i=0; i<m; i++) {
			int next=fs.nextInt()-1;
			counts[next]++;
			boolean hasFalse=false;
			for (int j=0; j<n; j++) {
				if (counts[j]==0)
					hasFalse=true;
			}
			if (!hasFalse) {
				p++;
				for (int j=0; j<n; j++)
					counts[j]--;
			}
		}
		System.out.println(p);
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
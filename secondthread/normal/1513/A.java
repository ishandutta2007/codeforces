
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=fs.nextInt();
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=i+1;
			
			if (k*2>=n) {
				System.out.println(-1);
				continue;
			}
			for (int i=0; i<k; i++) {
				int i1=i*2+1, i2=i1+1;
				int temp=a[i1];
				a[i1]=a[i2];
				a[i2]=temp;
			}
			for (int i:a) System.out.print(i+" ");
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
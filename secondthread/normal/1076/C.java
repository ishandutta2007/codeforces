import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			if (n==0) {
				System.out.println("Y 0.000000000 0.000000000");
			}
			else if (n==1||n==2||n==3) {
				System.out.println("N");
			}
			else if (n==4) {
				System.out.println("Y 2.000000000 2.000000000");
			}
			else {
				double min=1, max=Math.sqrt(n);
				for (int i=0; i<1000; i++) {
					double mid=(min+max)/2;
					double total=mid+n/mid;
					if (total>n) {
						min=mid;
					}
					else {
						max=mid;
					}
				}
				double a=min, b=n/min;
				System.out.printf("Y %.9f %.9f\n", a, b);
//				System.out.printf("\t%.11f %.11f%n", Math.abs(a+b-a*b), Math.abs(a+b-n));
			}
		}
		
	}
	
	static class FastScanner {
		StringTokenizer st = new StringTokenizer("");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		public String next() {
			while (!st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public int[] readArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

	}
	
}
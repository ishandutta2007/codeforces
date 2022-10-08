import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++) a[i]=fs.nextInt();
		int max=a[0];
		for (int i:a) max=Math.max(i, max);
		int[] real=new int[n];
		for (int i=0; i<n; i++) real[i]=max-a[i];
		int gcd=0;
		for (int i:real) gcd=gcd(gcd, i);
		long total=0;
		for (int i:real) total+=i/gcd;
		System.out.println(total+" "+gcd);
	}
	
	static int gcd(int a, int b) {
		return b==0?a:gcd(b, a%b);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(""	);
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
	}

}
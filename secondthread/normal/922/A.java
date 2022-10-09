import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		long numberOfCopies=fs.nextInt();
		long numberOfOriginal=fs.nextInt()-1;
		numberOfCopies-=numberOfOriginal;
		if (numberOfCopies<0||numberOfOriginal<0||numberOfCopies%2!=0) {
			System.out.println("No");
		}
		else {
			if (numberOfOriginal==0&&numberOfCopies!=0) {
				System.out.println("No");
			}
			else {				
				System.out.println("Yes");
			}
		}
	}
	
	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			br=new BufferedReader(new InputStreamReader(System.in));
			st=new StringTokenizer("");
		}
		
		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}

}
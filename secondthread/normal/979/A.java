import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		long n=fs.nextLong()+1;
		if (n==1)
		{
			System.out.println(0);
		}
		else if (n%2==0) {
			System.out.println(n/2);
		}
		else {
			System.out.println(n);
		}
				
	}

	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
			
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}

}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		long n=fs.nextInt(), d=fs.nextInt(), e=fs.nextInt()*5;
		long min=n;
		for (int i=0; i<600; i++) {
			if (n<e*i) break;
			long left=n-e*i;
			left%=d;
			min=Math.min(min, left);
		}
		System.out.println(min);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}

}
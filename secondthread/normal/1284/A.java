import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt();
		String[] a=new String[n], b=new String[m];
		for (int i=0; i<n; i++) a[i]=fs.next();
		for (int i=0; i<m; i++) b[i]=fs.next();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int aa=fs.nextInt()-1;
			System.out.println(a[aa%n]+b[aa%m]);
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
	}

}
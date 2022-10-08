import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int changes=0;
		char[] s=fs.next().toCharArray();
		for (int i=0; i<n; i+=2) {
			if (s[i]==s[i+1]) {
				s[i]=s[i]=='a'?'b':'a';
				changes++;
			}
		}
		System.out.println(changes);
		for (char c:s) {
			System.out.print(c);
		}
		System.out.println();
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
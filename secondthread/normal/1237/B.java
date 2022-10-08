import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=new int[n], b=new int[n];
		for (int i=0; i<n; i++) a[n-1-i]=fs.nextInt()-1;
		for (int i=0; i<n; i++) b[n-1-i]=fs.nextInt()-1;
		int[] indexOf=new int[n];
		for (int i=0; i<n; i++) indexOf[a[i]]=i;
		for (int i=0; i<n; i++) b[i]=indexOf[b[i]];
		int maxSeen=b[0];
		int ans=0;
		for (int i=0; i<n; i++) {
			maxSeen=Math.max(maxSeen, b[i]);
			if (maxSeen>b[i]) {
				ans++;
//				System.out.println("i: "+i+" "+maxSeen);
			}
		}
		System.out.println(ans);
		
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
	}
	
}
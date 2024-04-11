import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*

 */
public class C {
	
	static int mod=998244353;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		int minCut=n-k+1;
		int[] a=fs.readArray(n);
		int seen=0;
		long ans=0;
		long ans2=1;
		for (int i:a) {
			if (i>=minCut) {
				if (ans!=0)
					ans2=(ans2*(seen+1))%mod;
				seen=0;
				ans+=i;
			}
			else {
				seen++;
			}
		}
		
		System.out.println(ans+" "+ans2);
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
		
		boolean hasNext() {
			String next=null;
			try {
				next = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (next==null) {
				return false;
			}
			st=new StringTokenizer(next);
			return true;
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}

}
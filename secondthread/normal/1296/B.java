import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/*
5
6 10
010010
5 3
10101
1 0
0
2 0
01
1 100
0

2
1 100
0
2 51
00
3 -100
101
 */
public class B {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int t=fs.nextInt();
		for (int tt=0; tt<t; tt++) {
			int n=fs.nextInt();
			long ans=0;
			while (n>=10) {
				int buy=n/10;
				ans+=buy*10;
				n-=buy*10;
				n+=buy;
			}
			ans+=n;
			System.out.println(ans);
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
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}
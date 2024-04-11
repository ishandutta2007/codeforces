import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
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
		outer: for (int tt=0; tt<t; tt++) {
			int n=fs.nextInt(), target=fs.nextInt();
			char[] line=fs.next().toCharArray();
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=line[i]=='0'?1:-1;
			int[] cs=new int[n+1];
			for (int i=1; i<=n; i++)
				cs[i]=cs[i-1]+a[i-1];

			if (cs[n]==0) {
				for (int i:cs) {
					if (target==i) {
						System.out.println(-1);
						continue outer;
					}
				}
				System.out.println(0);
				continue outer;
			}
			
			int delta=cs[n];
			int total=0;
			for (int i=0; i<n; i++) {
				int toGet=target-cs[i];
				if (toGet%delta!=0) continue;
				if (toGet/delta>=0) total++;
			}
			System.out.println(total);
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
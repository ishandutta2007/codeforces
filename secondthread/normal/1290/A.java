import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*
4
6 4 2
2 9 2 3 8 5
4 4 1
2 13 60 4
4 1 3
1 2 2 1
2 2 0
1 2

1
6 4 2
2 9 2 3 8 5

1
4 4 1
2 13 60 4
 */
public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), yourPos=fs.nextInt()-1, k=fs.nextInt();
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=fs.nextInt();
			if (yourPos==0) {
				out.println(Math.max(a[0], a[n-1]));
				continue;
			}
			k=Math.min(yourPos, k);
			int theyForce=yourPos-k;
			int ans=-1;
			for (int front=0, back=n-k-1; front<=k; front++, back++) {
//				System.out.println("Front: "+front+" back "+back);
				int themAns=Integer.MAX_VALUE;
				for (int them=0; them<=theyForce; them++) {
					int realFront=front+them;
					int themLeft=theyForce-them;
					int realBack=back-themLeft;
//					System.out.println("Choosing between "+realFront+" and "+realBack);
					themAns=Math.min(themAns, Math.max(a[realFront], a[realBack]));
				}
				ans=Math.max(ans, themAns);
			}
			out.println(ans);
		}
		out.close();
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
		long nextLong() {
			return Long.parseLong(next());
		}
	}

}
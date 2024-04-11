import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/*

 */
public class EReal {

	static long mod=998244353;
	
	static long[] tenPow=new long[300000];
	static long[] dp1=new long[300000], dp2=new long[300000];
	
	public static void main(String[] args) throws InterruptedException {
		Thread t=new Thread(null, null, "", 1<<27) {
			public void run() {
				A();
			}
		};
		t.start();
		t.join();
	}
	
	public static void A() {
		precomp();
		Arrays.fill(dp1, -1);
		Arrays.fill(dp2, -1);
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int i=n; i>0; i--) {
			out.print(go(10, i)+" ");
		}
		out.println();
		out.close();
	}
	
	static long go(int choices, int n) {
		if (n==1) return choices;
		if (choices==9 && dp1[n]!=-1) return dp1[n];
		int L=n-1;
		long ways=mul(mul(choices, 9), tenPow[L-1]);
		ways=add(ways, mul(choices, csGo(n-1)));
		if (choices==9) dp1[n]=ways;
		return ways;
	}
	
	static long csGo(int n) {
		if (n<=0) return 0;
		if (dp2[n]!=-1) return dp2[n];
		return dp2[n]=add(go(9, n), csGo(n-1));
	}
	
	static void precomp() {
		tenPow[0]=1;
		for (int i=1; i<tenPow.length; i++) tenPow[i]=mul(tenPow[i-1], 10);
	}
	
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	
	static long mul(long a, long b) {
		return a*b%mod;
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
		int[] readArrayM1(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt()-1;
			return a;
		}
	}

}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
1
4 1 3
a**a

1
200 1 1000000000000000000
a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*

1
3 0 1
aaa
 */
public class C {

	static long oo=(long)2e18;
	static long[][] dp;
	static int n, k;
	static long x;
	static char[] line;
	static int[] nextA;
	static PrintWriter out;
	
	static boolean killMePls = false;
	public static void main(String[] args) throws Exception {
		Thread.UncaughtExceptionHandler h = new Thread.UncaughtExceptionHandler() {
			public void uncaughtException(Thread t, Throwable e) {killMePls = true;}
		};
		Thread t = new Thread(null, ()->A(args), "", 1<<27);
		t.setUncaughtExceptionHandler(h);
		t.start();
		t.join();
		if(killMePls) throw null;
	}
	public static void A(String args[]) {
		FastScanner fs=new FastScanner();
		out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			n=fs.nextInt(); k=fs.nextInt(); x=fs.nextLong();
			line=fs.next().toCharArray();
			dp=new long[n][k+1];
			for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], -1);
			nextA=new int[n];
			int nextAInd=n;
			for (int i=n-1; i>=0; i--) {
				nextA[i]=nextAInd;
				if (line[i]=='a') nextAInd=i;
			}
			
			for (int originalPos=n-1; originalPos>=0; originalPos--) {
				for (int kk=k; kk>=0; kk--) {
					go(originalPos, kk);
				}
			}
			//TODO: build it
			x--;
			print(x, 0, 0);
			out.println();
		}
		out.close();
	}
	
	static long go(int originalPos, int nBs) {
		if (originalPos==n) return 1;
		if (dp[originalPos][nBs]!=-1) return dp[originalPos][nBs];
		//place b or not
		long ans=0;
		{
			//not place b
			if (line[originalPos]!='*') {
				ans+=go(originalPos+1, 0);
			}
			else if (nBs==k) {
				ans+=go(originalPos+1, 0);
			}
			else {
				ans+=go(nextA[originalPos], 0);
			}
		}
		{
			//place b
			if (line[originalPos]=='*' && nBs<k) {
				ans+=go(originalPos, nBs+1);
			}
		}
		
		return dp[originalPos][nBs]=Math.min(ans, oo);
	}
	
	static void print(long x, int originalPos, int nBs) {
		while (true) {
			if (originalPos==n)
				return;
			if (line[originalPos]=='a') {
				out.print('a');
				originalPos++;
				nBs=0;
				continue;
			}
			//cost of not printing a b
			int nextInd=nBs<k?nextA[originalPos]:originalPos+1;
			long costNow=go(nextInd, 0);
			if (costNow>x) {
				if (nBs<k) {
					originalPos=nextA[originalPos];
					nBs=0;
				}
				else {
					originalPos++;
					nBs=0;
				}
			}
			else {
				out.print("b");
				x-=costNow;
				nBs++;
			}
		}
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
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
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {
	
	static long mod=998244353;
	static char[] s, t;
	static long[][] dp;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		s=fs.next().toCharArray(); t=fs.next().toCharArray();
		int ns=s.length, nt=t.length;
		char[] newT=new char[ns];
		Arrays.fill(newT, '*');
		for (int i=0; i<nt; i++) newT[i]=t[i];
		t=newT;
		
		dp=new long[ns+1][ns+1];
		for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], -1);
		long ans=0;
		for (int targetLen=nt; targetLen<=ns; targetLen++) {
			ans+=go(targetLen, 0);
			ans%=mod;
		}
		System.out.println(ans);
	}
	
	static long go(int tLen, int tStart) {
		if (dp[tLen][tStart]!=-1) return dp[tLen][tStart];
		if (tLen==0) {
			return dp[tLen][tStart]=1;
		}
		long ways=0;
		char currentlyPlacing=s[tLen-1];
		if (eq(currentlyPlacing, t[tStart])) ways+=go(tLen-1, tStart+1);
		if (eq(currentlyPlacing, t[tStart+tLen-1])) ways+=go(tLen-1, tStart);
		ways%=mod;
		return dp[tLen][tStart]=ways;
	}
	
	static boolean eq(char a, char b) {
		return a==b||a=='*'||b=='*';
	}
	
	static long add(long a, long b) {
		return (a+b)%mod;
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

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
	
}
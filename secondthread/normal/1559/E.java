import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/*
50 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
1 100000
 */
public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
//		int T=fs.nextInt();
		int T=1;
		buildMobius();
		long time=System.currentTimeMillis();
		for (int tt=0; tt<T; tt++) {
			//dp[sumLeft][
			//suppose I know the number of ways for the GCD to be a multiple of x
			//+1 -2, -3, -5 +6 => that one math thing with the u symbol
			
			int nStars=fs.nextInt();
			int maxSum=fs.nextInt();
			int[] ls=new int[nStars], rs=new int[nStars];
			for (int i=0; i<nStars; i++) {
				ls[i]=fs.nextInt();
				rs[i]=fs.nextInt();
			}
//			System.out.println("Read input");
			
			long finalAns=0;
			for (int gcd=1; gcd<=maxSum; gcd++) {
//				if (gcd%10==0) {
//					System.out.println("Gcd: "+gcd);
//				}
				int[] newLs=new int[nStars], newRs=new int[nStars];
				for (int i=0; i<nStars; i++) {
					newLs[i]=(ls[i]+gcd-1)/gcd;
					newRs[i]=rs[i]/gcd;
				}
				int newMaxSum=maxSum/gcd;
				int ans=solve(newMaxSum, newLs, newRs, nStars);
				finalAns+=ans*mobius[gcd];
			}
			finalAns=(finalAns%mod+mod)%mod;
			System.out.println(finalAns);
		}
		System.err.println(System.currentTimeMillis()-time);
	}
	
	static int mod=998244353;
	
	static int solve(int maxSum, int[] ls, int[] rs, int nStars) {
		dp=new int[nStars+1][maxSum+1];
//		for (int i=0; i<dp.length; i++)
//			Arrays.fill(dp[i], -1);
		long[] cs;
		for (int sum=0; sum<=maxSum; sum++) dp[nStars][sum]=1;
		cs=new long[maxSum+2];
		for (int i=1; i<cs.length; i++) cs[i]=cs[i-1]+dp[nStars][i-1];
		for (int i=nStars-1; i>=0; i--) {
			for (int sumLeft=ls[i]; sumLeft<=maxSum; sumLeft++) {
				long ways=0;
//				for (int toPlace=ls[i]; toPlace<=Math.min(sumLeft, rs[i]); toPlace++) {
//					ways+=dp[i+1][sumLeft-toPlace];
//				}
				ways=cs[sumLeft-ls[i]+1]-cs[Math.max(0, sumLeft-rs[i])];
				ways%=mod;
				dp[i][sumLeft]=(int)ways;
			}
			Arrays.fill(cs, 0);
			for (int j=1; j<cs.length; j++) cs[j]=cs[j-1]+dp[i][j-1];
		}
		
		return dp[0][maxSum];
	}
	
	static int[][] dp;
	
//	static int go(int i, int sumLeft, int[] ls, int[] rs, int nStars) {
//		if (sumLeft<0) return 0;
//		if (i==nStars) return 1;
//		if (dp[i][sumLeft]!=-1) return dp[i][sumLeft];
//		long ways=0;
//		for (int toPlace=ls[i]; toPlace<=rs[i] && sumLeft>=toPlace; toPlace++) {
//			ways+=go(i+1, sumLeft-toPlace, ls, rs, nStars);
//		}
//		ways%=mod;
//		return dp[i][sumLeft]=(int)ways;
//	}

	static final Random random=new Random();
	static int MAX=1_000_000;
	static int[] mobius = new int[1_000_000];
	
	static void buildMobius() {
		int ptr = 0;
		int[] primes = new int[MAX];
		boolean[] comp = new boolean[MAX];
		mobius[1] = 1;
		
		for(int i = 2; i < MAX; i++) {
			if(!comp[i]) {
				primes[ptr++] = i;
				mobius[i] = -1;
			}
			for(int j = 0; j < ptr && i * primes[j] < MAX; j++) {
				int val = primes[j] * i;
				comp[val] = true;
				if(i % primes[j] == 0) {
					mobius[val] = 0;
					break;
				}
				else {
					mobius[val] = mobius[i] * mobius[primes[j]];
				}
			}
		}
	}
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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
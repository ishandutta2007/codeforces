import java.util.Arrays;
import java.util.Scanner;

public class gitGud589E {

	static int[][] nCk=new int[501][501];
	static int[] kPow=new int[501];
	static int[] km1Pow=new int[501];
	static int n, k;
	static int mod=1_000_000_007;
	static int[][] dp=new int[500][500];
	
	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		n=fs.nextInt(); k=fs.nextInt();
		precomp();
		int ans=(go(0, 0)+mod)%mod;
		System.out.println(ans);
	}
	
	static int go(int column, int nSatisfiedRows) {
		if (column==n) return nSatisfiedRows==n?1:0;
		if (dp[column][nSatisfiedRows]!=-1) return dp[column][nSatisfiedRows];
		long totalWays=0;

		//Option A: place a 1 in at least on of the satisfied rows
		long satisfiedWays=kPow[nSatisfiedRows]-km1Pow[nSatisfiedRows];
		for (int onesToPlace=0; onesToPlace+nSatisfiedRows<=n; onesToPlace++) {
			int nonOnesToPlace=n-onesToPlace-nSatisfiedRows;
			long waysNow=km1Pow[nonOnesToPlace]*(long)nCk[onesToPlace+nonOnesToPlace][onesToPlace]%mod;
			long waysFuture=go(column+1, nSatisfiedRows+onesToPlace);
			totalWays=(totalWays+waysNow*waysFuture%mod*satisfiedWays)%mod;
		}
		
		//Option B: place no 1s in satisfied rows, and at least 1 in an unsatisfied row
		satisfiedWays=km1Pow[nSatisfiedRows];
		for (int onesToPlace=1; onesToPlace+nSatisfiedRows<=n; onesToPlace++) {
			int nonOnesToPlace=n-onesToPlace-nSatisfiedRows;
			long waysNow=km1Pow[nonOnesToPlace]*(long)nCk[onesToPlace+nonOnesToPlace][onesToPlace]%mod;
			long waysFuture=go(column+1, nSatisfiedRows+onesToPlace);
			totalWays=(totalWays+waysNow*waysFuture%mod*satisfiedWays)%mod;
		}
		
//		System.out.println("Answer for column: "+column+" nSatisfiedRows: "+nSatisfiedRows+" is "+totalWays);
		
		return dp[column][nSatisfiedRows]=(int)(totalWays%mod);
	}

	
	static void precomp() {
		nCk[0][0]=1;
		for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], -1);
		for (int n=1; n<nCk.length; n++) {
			nCk[n][0]=nCk[n][n]=1;
			for(int k=1; k<n; k++)
				nCk[n][k]=(nCk[n-1][k-1]+nCk[n-1][k])%mod;
		}
		kPow[0]=1;
		for (int i=1; i<kPow.length; i++)
			kPow[i]=(int)(kPow[i-1]*(long)k%mod);
		km1Pow[0]=1;
		for (int i=1; i<km1Pow.length; i++)
			km1Pow[i]=(int)(km1Pow[i-1]*(long)(k-1)%mod);
	}
}
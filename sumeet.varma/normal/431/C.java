import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R247QCktree {

	static long dp[][][];
	static int n,k,d;
	static long mod = (long)(1e9 + 7);
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		k = ip(st1.nextToken());
	    d = ip(st1.nextToken());
	    
	    dp = new long[n+5][n+5][2];
	    for(int i=0;i<=n+4;i++)
	    	for(int j=0;j<=n+4;j++)
	    		dp[i][j][0] = dp[i][j][1] = -1;
	    w.println(solve(0,n,1));
	    w.close(); 
	}
	
	public static long solve(int lvl,int sumLeft,int dNeeded){
		//System.out.println(lvl + " " + sumLeft + " " + dNeeded);
		if(sumLeft < 0)
			return 0;
		if(sumLeft == 0){
			if(dNeeded == 1)
				return 0;
			else
				return 1;
		}
		if(dp[lvl][sumLeft][dNeeded] == -1){
			dp[lvl][sumLeft][dNeeded] = 0;
			for(int i=1;i<=k;i++)
				dp[lvl][sumLeft][dNeeded] = (dp[lvl][sumLeft][dNeeded] + solve(lvl+1,sumLeft-i,i>=d ? 0 : dNeeded)) % mod;
		}
		return dp[lvl][sumLeft][dNeeded];
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R89qDCaesarRegions {

	static int n1,n2,k1,k2;
	static long dp[][][][];
	static int mod = (int)(1e8);
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n1 = ip(st1.nextToken());
		n2 = ip(st1.nextToken());
	    k1 = ip(st1.nextToken());
	    k2 = ip(st1.nextToken());      
	    
	    dp = new long[n1+1][n2+1][2][11];
	    for(int i=0;i<=n1;i++)
	    	for(int j=0;j<=n2;j++)
	    		for(int k=0;k<=1;k++)
	    			for(int x=0;x<=10;x++)
	    				dp[i][j][k][x] = -1;
	    
	    w.println(solve(n1,n2,0,0));
	    
	    w.close(); 
	}
	
	public static long solve(int aleft,int bleft,int prev,int prevCount){
		if(prev == 1 && prevCount > k2)	return 0;
		if(prev == 0 && prevCount > k1)	return 0;
		if(aleft < 0 || bleft < 0)		return 0;
		if(aleft == 0 && bleft == 0)	return 1;
		
		if(dp[aleft][bleft][prev][prevCount] == -1){
			long ans = 0;
			if(prev == 0)
				ans += solve(aleft-1,bleft,prev,prevCount+1) + solve(aleft,bleft-1,1,1);
			else
				ans += solve(aleft-1,bleft,0,1) + solve(aleft,bleft-1,prev,prevCount+1);
			if(ans >= mod)	ans %= mod;
			dp[aleft][bleft][prev][prevCount] = ans;
		}
		
		return dp[aleft][bleft][prev][prevCount];
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	
}
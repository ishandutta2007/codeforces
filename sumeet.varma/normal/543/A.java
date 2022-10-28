import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R302qC {

	static int n,m,b,mod,zeroes;
	static int a[];
	static long dp[][][];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		m = ip(st1.nextToken());
		b = ip(st1.nextToken());
	    mod = ip(st1.nextToken());
	   
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	    
	    dp = new long[2][m+1][b+1];
	  
	    dp[0][0][0] = 1;
	    for(int j=1;j<=m && a[0]*j <= b;j++)
	    	dp[0][j][a[0]*j] = 1;
	    
	    for(int i=1;i<n;i++){
	    	dp[1][0][0] = 1;
	    	for(int j=1;j<=m;j++)
	    		for(int k=0;k<=b;k++)
	    			dp[1][j][k] = dp[0][j][k] + (k >= a[i] ? dp[1][j-1][k - a[i]] : 0);
	    	for(int j=1;j<=m;j++)
	    		for(int k=0;k<=b;k++)
	    			dp[0][j][k] = dp[1][j][k] % mod;
	    }
	    
	    long ans = 0;
	    for(int i=0;i<=b;i++)
	    	ans += dp[0][m][i];
	    w.println(ans % mod);
	    w.close();
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}
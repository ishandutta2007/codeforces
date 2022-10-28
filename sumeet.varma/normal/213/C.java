import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R131qCRelayRace {

	static int n;
	static int a[][];
	static int dp[][][];
	static int oo = (int)(1e9);
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    n = ip(br.readLine());
	          
	    a = new int[n][n];
	    for(int i=0;i<n;i++){
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	for(int j=0;j<n;j++)
	    		a[i][j] = ip(st2.nextToken());
	    }
	    
	    dp = new int[n][n][2];
	    for(int i=0;i<n;i++)
	    	for(int j=0;j<n;j++)
	    		dp[i][j][1] = a[n-1][n-1];
	    
	    for(int total = 2*n-2;total>=0;total--){
	    	for(int aR=Math.max(0,total-(n-1));aR<=Math.min(n-1,total);aR++){
	    		for(int bR=Math.max(0,total-(n-1));bR<=Math.min(n-1,total);bR++){
	    			int ax = total - aR;
	    			int ay = aR;
	    			int bx = total - bR;
	    			int by = bR;
	    			
	    			int ans = -oo;
	    			if(ax+1 < n && bx+1 < n)
	    				ans = Math.max(ans,dp[aR][bR][1]);
	    			if(ax+1 < n && by+1 < n)
	    				ans = Math.max(ans,dp[aR][bR+1][1]);
	    			if(ay+1 < n && bx+1 < n)
	    				ans = Math.max(ans,dp[aR+1][bR][1]);
	    			if(ay+1 < n && by+1 < n)
	    				ans = Math.max(ans,dp[aR+1][bR+1][1]);
	    			
	    			ans = (ans == -oo) ? 0 : ans;
	    			ans += a[ax][ay] + a[bx][by];
	    			if(ax == bx && ay == by)	ans -= a[ax][by];
	    			
	    			dp[aR][bR][0] = ans;
	    		}
	    	}
	    	
	    	for(int aR=0;aR<=Math.min(n-1,total);aR++)
	    		for(int bR=0;bR<=Math.min(n-1,total);bR++)
	    			dp[aR][bR][1] = dp[aR][bR][0];
	    }
	    
	    w.println(dp[0][0][1]);
	    w.close(); 
	}
	
	public static int solve(int aR,int bR,int total){
		
		if(total == 2*n - 1)	return 0;
		
		if(dp[aR][bR][total] == -oo){
			int ax = total - aR;
			int ay = aR;
			int bx = total - bR;
			int by = bR;
			
			int ans = -oo;
			if(ax+1 < n && bx+1 < n)
				ans = Math.max(ans,solve(aR,bR,total+1));
			if(ax+1 < n && by+1 < n)
				ans = Math.max(ans,solve(aR,bR+1,total+1));
			if(ay+1 < n && bx+1 < n)
				ans = Math.max(ans,solve(aR+1,bR,total+1));
			if(ay+1 < n && by+1 < n)
				ans = Math.max(ans,solve(aR+1,bR+1,total+1));
			
			ans = (ans == -oo) ? 0 : ans;
			ans += a[ax][ay] + a[bx][by];
			if(ax == bx && ay == by)	ans -= a[ax][by];
			
			dp[aR][bR][total] = ans;
		}
		
		return dp[aR][bR][total];
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R208qDDimaAndHares {

	static int n;
	static int a[],b[],c[];
	static int dp[][];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	     
	    StringTokenizer st3 = new StringTokenizer(br.readLine());
	    b = new int[n];
	    for(int i=0;i<n;i++)
	    	b[i] = ip(st3.nextToken());
	    
	    StringTokenizer st4 = new StringTokenizer(br.readLine());
	    c = new int[n];
	    for(int i=0;i<n;i++)
	    	c[i] = ip(st4.nextToken());
	    
	    dp = new int[n][2];
	    for(int i=0;i<n;i++)
	    	dp[i][0] = dp[i][1] = -1;
	    
	    w.println(solve(0,0));
	    w.close(); 
	}
	
	//type = 0 == prev not taken,1 = prev taken
	public static int solve(int curr,int type){
		if(dp[curr][type] == -1){
			int ans = 0;
			if(curr == n-1){
				if(type == 0)	ans = a[curr];
				if(type == 1)	ans = b[curr];
			}
			else if(curr == 0){
				ans = Math.max(ans, solve(curr+1,0) + b[curr]);
				ans = Math.max(ans, solve(curr+1,1) + a[curr]);
			}
			else{
				if(type == 0){
					ans = Math.max(ans, solve(curr+1,0) + b[curr]);
					ans = Math.max(ans, solve(curr+1,1) + a[curr]);
				}
				else{
					ans = Math.max(ans, solve(curr+1,0) + c[curr]);
					ans = Math.max(ans, solve(curr+1,1) + b[curr]);
				}
			}
			dp[curr][type] = ans;
		}
		return dp[curr][type];
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}
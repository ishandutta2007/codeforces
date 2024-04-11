import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R204qCJeffAndRounding {
	
	static int n,oo = (int)(1e8);
	static int a[],dp[][];

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[2*n];
	    for(int i=0;i<2*n;i++){
	    	StringTokenizer st3 = new StringTokenizer(st2.nextToken(),".");
	    	st3.nextToken();
	    	a[i] = ip(st3.nextToken());
	    }
	    
	    //System.out.println(Arrays.toString(a));
	    dp = new int[2*2000+1][2*2000+1];
	    Arrays.fill(dp[2*n],oo);
	    dp[2*n][n] = 0;
	    
	    for(int curr=2*n-1;curr>=0;curr--){
	    	for(int roundedDown=0;roundedDown<=curr;roundedDown++){
		    	int ans1 = dp[curr+1][roundedDown] + (a[curr] != 0 ? 1000 - a[curr] : 0);
				int ans2 = dp[curr+1][roundedDown+1] - a[curr];
				if(Math.abs(ans1) < Math.abs(ans2))
					dp[curr][roundedDown] = ans1;
				else
					dp[curr][roundedDown] = ans2;
	    	}
	    }
	    
	    w.printf("%.3f\n",Math.abs(dp[0][0])/1000.0);
	    w.close(); 
	}
	
	public static int solve(int curr,int roundedDown){
		if(curr == 2*n)
			return roundedDown == n ? 0 : oo;
		if(dp[curr][roundedDown] == -1){
			int ans1 = a[curr] != 0 ? solve(curr+1,roundedDown) + 1000 - a[curr] : solve(curr+1,roundedDown);
			int ans2 = solve(curr+1,roundedDown+1) - a[curr];
			if(Math.abs(ans1) < Math.abs(ans2))
				dp[curr][roundedDown] = ans1;
			else
				dp[curr][roundedDown] = ans2;
		}
		return dp[curr][roundedDown];
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}
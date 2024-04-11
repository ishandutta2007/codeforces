import java.io.*;
import java.util.*;

public class R165qD {

	static int n,m;
	static int s[];
	static int dp[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		m = ip(st1.nextToken());
	    
		s = new int[n + 1];
		for(int i=1;i<=n;i++){
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			s[i] = ip(st2.nextToken());
		}
		
		dp = new int[n+1];
		
		for(int i=1;i<=n;i++){
			int j = s[i];
			for(int k=j;k>=1;k--)
				dp[j] = Math.max(dp[j],1 + dp[k]);
		}
		
		int ans = 0;
		for(int i=1;i<=n;i++)
			ans = Math.max(ans,dp[i]);
		
		w.println(n - ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}
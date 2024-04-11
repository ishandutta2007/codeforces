import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R214qCDimaAndSalad {

	static int n,k;
	static int a[],b[];
	static int dp[][];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		k = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    
	    StringTokenizer st3 = new StringTokenizer(br.readLine());
	    b = new int[n];
	    for(int i=0;i<n;i++)
	    	b[i] = ip(st3.nextToken());
	    
	    dp = new int[101][200001];
	    for(int i=0;i<n;i++)
	    	Arrays.fill(dp[i], -1);
	    
	    solve(0,m(0));
	    w.println(dp[0][m(0)] <= 0 ? -1 : dp[0][m(0)]);
	    w.close(); 
	}
	
	public static int solve(int curr,int bal){
		if(curr == n)
			return bal == m(0) ? 0 : -100000000;	
		if(dp[curr][bal] == -1){
			dp[curr][bal] =  solve(curr + 1,bal);
			dp[curr][bal] = Math.max(dp[curr][bal] , a[curr] + solve(curr + 1,bal + a[curr] - k*b[curr]));
		}
		return dp[curr][bal];
	}
	
	public static int m(int i){
		return 100000 + i;
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}
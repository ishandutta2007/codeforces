import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R145qFFence {

	static int n,a,b;
	static int h[],pre[];	
	static int dp[][][];
	static int oo = (int)(1e9);
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    //PrintWriter w = new PrintWriter(System.out);
	    
	    n = ip(br.readLine());
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    a = ip(st1.nextToken());
		b = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    h = new int[n];
	    for(int i=0;i<n;i++)
	    	h[i] = ip(st2.nextToken());
	    
	    pre = new int[n];
	    pre[0] = h[0];
	    for(int i=1;i<n;i++)
	    	pre[i] = pre[i-1] + h[i];
	    
	    dp = new int[2][a+1][2];
	    for(int i=0;i<=a;i++)
	    	dp[1][i][0] = dp[1][i][1] = 0;
	    
	    for(int curr=n-1;curr>=1;curr--){
	    	for(int usedA=0;usedA<=Math.min(a, pre[curr-1]);usedA++){
	    		for(int prev=0;prev<2;prev++){
	    			int ans = oo;
	    			int usedB = pre[curr-1] - usedA;
					if(usedA + h[curr] <= a)	ans = Math.min(ans, dp[1][usedA+h[curr]][0] + ((prev == 1) ? Math.min(h[curr-1], h[curr]) : 0) );
					if(usedB + h[curr] <= b)	ans = Math.min(ans, dp[1][usedA][1] + ((prev == 0) ? Math.min(h[curr-1],h[curr]) : 0));
					dp[0][usedA][prev] = ans;
	    		}
	    	}
	    	for(int usedA=0;usedA<=Math.min(a, pre[curr-1]);usedA++)
	    		for(int prev=0;prev<2;prev++)
	    			dp[1][usedA][prev] = dp[0][usedA][prev];
	    }
	    
	    int ans = oo;
	    if(h[0] <= a)	ans = Math.min(ans, dp[1][h[0]][0]);
	    if(h[0] <= b)	ans = Math.min(ans,	dp[1][0][1]);
	    if(ans >= oo)	ans = -1;
	    
	    w.println(ans);
	    w.close(); 
	    br.close();
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}
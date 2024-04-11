import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class R96qCLogoTurtle {
	
	static char a[];
	static int n;
	static int dp[][][][];
	static int oo = 1000;
	static int L = oo - 100,R = oo + 100;
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    String in = br.readLine();
	    a = new char[in.length() + 1];
	    for(int i=0;i<a.length-1;i++)
	    	a[i] = in.charAt(i);
	    
	    n = ip(br.readLine());    
	
	    dp = new int[a.length][n+1][2][2];
	    for(int i=0;i<a.length;i++)
	    	for(int j=0;j<=n;j++)
	    		for(int k=0;k<2;k++)
	    		dp[i][j][k][0] = dp[i][j][k][1] = 10*oo;
	    
	    int ans1 = solveMax(0,n,m(a[0]),0);
	    //System.out.println(ans1);
	    
	    for(int i=0;i<a.length;i++)
	    	for(int j=0;j<=n;j++)
	    		for(int k=0;k<2;k++)
	    		dp[i][j][k][0] = dp[i][j][k][1] = 10*oo;
	    
	    int ans2 = -1*solveMin(0,n,m(a[0]),0);
	    //System.out.println(ans2);
	    
	    if(ans1 > 100)	ans1 = 0;
	    if(ans2 > 100)	ans2 = 0;
	    
	    w.println(Math.max(ans1, ans2));
	    w.close(); 
	}
	
	public static int solveMax(int curr,int movesLeft,int currState,int direction){
		if(curr == a.length-1)
			return movesLeft == 0 ? 0 : -oo;
		if(dp[curr][movesLeft][currState][direction] == 10*oo){
			int ans = -oo;
			if(currState == 0)
				ans = Math.max(ans, solveMax(curr+1,movesLeft,m(a[curr+1]),direction) + ((direction == 0) ? 1 : -1) );
			else
				ans = Math.max(ans, solveMax(curr+1,movesLeft,m(a[curr+1]),1 - direction) );
			if(movesLeft > 0)
				ans = Math.max(ans, solveMax(curr,movesLeft-1,1-currState,direction));
			dp[curr][movesLeft][currState][direction] = ans;
		}
		//System.out.println(curr +  " " + movesLeft + " " + currState + " " + direction + " : " + dp[curr][movesLeft][currState][direction] );
		return dp[curr][movesLeft][currState][direction];
	}
	
	public static int solveMin(int curr,int movesLeft,int currState,int direction){
		if(curr == a.length-1)
			return movesLeft == 0 ? 0 : oo;
		if(dp[curr][movesLeft][currState][direction] == 10*oo){
			int ans = oo;
			if(currState == 0)
				ans = Math.min(ans, solveMin(curr+1,movesLeft,m(a[curr+1]),direction) + ((direction == 0) ? 1 : -1) );
			else
				ans = Math.min(ans, solveMin(curr+1,movesLeft,m(a[curr+1]),1 - direction) );
			if(movesLeft > 0)
				ans = Math.min(ans, solveMin(curr,movesLeft-1,1-currState,direction));
			dp[curr][movesLeft][currState][direction] = ans;
		}
		return dp[curr][movesLeft][currState][direction];
	}
	
	public static int m(char x){	return (x == 'F') ? 0 : 1;	}
	
	public static int ip(String s){		return Integer.parseInt(s);	}
}
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class R121DynastyPuzzle {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    int n = ip(br.readLine());
	    int s[] = new int[n];
	    int e[] = new int[n];
	    int l[] = new int[n];
	    
	    String in;
	    for(int i=0;i<n;i++){
	    	in = br.readLine();
	    	l[i] = in.length();
	    	s[i] = in.charAt(0) - 'a';
	    	e[i] = in.charAt(l[i]-1) - 'a';
	    }
	    
	    int dp[][] = new int[26][26];
	    
	    for(int curr=0;curr<n;curr++){
	    	for(int i=0;i<26;i++)
	    		if(dp[i][s[curr]] != 0)
	    			dp[i][e[curr]] = Math.max(dp[i][e[curr]],l[curr] + dp[i][s[curr]]);
	    	dp[s[curr]][e[curr]] = Math.max(dp[s[curr]][e[curr]] , l[curr]);
	    }
	    
	    int ans = 0;
	    for(int i=0;i<26;i++)
	    	ans = Math.max(ans, dp[i][i]);
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}